/*
** conditions.c for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Wed May 14 08:29:22 2014 Newton Guillaume
** Last update Sun May 25 14:15:44 2014 Newton Guillaume
*/

#include "42sh.h"

void	write_char(char *line, const char *tmp,
		   const char *input, const int fd)
{
  int	i;
  int	len;

  my_putchar(input[0], fd);
  my_putrevstr(tmp, fd);
  len = my_strlen(tmp);
  i = -1;
  while (++i < len)
    my_putchar('\b', fd);
  strncat(line, input, 1);
}

int	get_ctrl_d(char *line, const char *tmp, const int fd)
{
  if (!line[0] && !tmp[0])
    {
      my_putstr("quitting.", 1);
      return (-2);
    }
  else
    write_char(line, tmp, "\0\0\0", fd);
  return (0);
}

int	conditions(char *line, char *tmp, const char *input, const int fd)
{
  if (input[0] == 4 && input[1] == 0 && input[2] == 0
      && !line[0] && !tmp[0])
    return (get_ctrl_d(line, tmp, fd));
  else if (input[0] == 27)
    special_char(line, tmp, input, fd);
  else if (input[0] == 126)
    {
      if (my_strlen(tmp) > 0)
	delete_char(tmp, fd);
    }
  else if (input[0] == 127)
    {
      if (my_strlen(line) > 0)
	get_backspace(line, fd);
    }
  else if (input[0] >= ' ')
    write_char(line, tmp, input, fd);
  return (0);
}

void	get_mult_exec(char **tabb, t_env *env)
{
  int	i;
  char	*tmp;

  i = 0;
  if (check_tab_error(tabb) == 0)
    {
      while (tabb[i] && tabb[i][0] != ';')
	i++;
      if (tabb[i] != NULL && tabb[i + 1] != NULL)
	{
	  tmp = tabb[i];
	  tabb[i] = NULL;
	  exec_line(tabb, env);
	  get_mult_exec(&tabb[i + 1], env);
	  tabb[i] = tmp;
	}
      else
	exec_line(tabb, env);
    }
}
