/*
** get_special_char.c for 42sh in /home/guillaume/Coding/42sh/src
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Tue Apr 22 17:48:47 2014 Newton Guillaume
** Last update Sat May 24 12:03:07 2014 Yezeguelian Jimmy
*/

#include "42sh.h"

void	history_arrow(char *line, char *tmp,
		      const char arrow, const int fd)
{
  int	i;
  int	tmp_len;
  int	line_len;

  tmp_len = my_strlen(tmp);
  line_len = my_strlen(line);
  i = -1;
  while (++i < line_len)
    my_putchar('\b', fd);
  write(fd, tgetstr("dc", NULL), my_strlen(tgetstr("ce", NULL)));
  history(line, arrow, 's');
  bzero(tmp, tmp_len + 1);
  my_putstr(line, fd);
}

void	get_arrow(char *line, char *tmp, const char arrow, const int fd)
{
  int	tmp_len;
  int	line_len;

  tmp_len = my_strlen(tmp) - 1;
  line_len = my_strlen(line) - 1;
  if (arrow == RIGHT && tmp_len >= 0)
    {
      write(fd, tgetstr("nd", NULL), my_strlen(tgetstr("nd", NULL)));
      strcat(line, &tmp[tmp_len]);
      tmp[tmp_len] = '\0';
    }
  else if (arrow == LEFT && line_len >= 0)
    {
      write(fd, tgetstr("le", NULL), my_strlen(tgetstr("le", NULL)));
      strcat(tmp, &line[line_len]);
      line[line_len] = '\0';
    }
  else if (arrow == UP || arrow == DOWN)
    history_arrow(line, tmp, arrow, fd);
}

void	get_home_end(char *line, char *tmp, const char arrow, const int fd)
{
  int	tmp_len;
  int	line_len;

  tmp_len = my_strlen(tmp) - 1;
  line_len = my_strlen(line) - 1;
  if (arrow == HOME)
    {
      while (tmp_len >= 0)
	{
	  write(fd, tgetstr("nd", NULL), my_strlen(tgetstr("nd", NULL)));
	  strcat(line, &tmp[tmp_len]);
	  tmp[tmp_len] = '\0';
	  tmp_len--;
	}
    }
  else if (arrow == END)
    {
      while (line_len >= 0)
	{
	  write(fd, tgetstr("le", NULL), my_strlen(tgetstr("le", NULL)));
	  strcat(tmp, &line[line_len]);
	  line[line_len] = '\0';
	  line_len--;
	}
    }
}

void	delete_char(char *str, const int fd)
{
  int	i;
  int	len;

  i = -1;
  len = my_strlen(str);
  str[len - 1] = '\0';
  my_putrevstr(str, fd);
  my_putchar(' ', fd);
  while (++i < len)
    my_putchar('\b', fd);
}

void	special_char(char *line, char *tmp,
		     const char *input, const int fd)
{
  if (input[1] == 91)
    get_arrow(line, tmp, input[2], fd);
  else if (input[1] == 79)
    get_home_end(line, tmp, input[2], fd);
}
