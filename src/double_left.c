/*
** double_left.c for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Mon May 19 09:04:25 2014 Newton Guillaume
** Last update Thu May 22 16:17:13 2014 Newton Guillaume
*/

#include "42sh.h"

int	doubleleft_conditions(char *line, char *tmp,
			      const char *input, const int fd)
{
  if (input[0] == 27)
    special_char(line, tmp, input, fd);
  else if (input[0] == 126 && my_strlen(tmp) > 0)
    delete_char(tmp, fd);
  else if (input[0] == 127)
    {
      if (my_strlen(line) > 0)
	get_backspace(line, fd);
    }
  else if (input[0] >= ' ')
    write_char(line, tmp, input, fd);
  return (0);
}

int	doubleleft_action(char *line, char *tmp, const char *input,
			  const int fd, const char *end)
{
  if (input[0] == '\n')
    {
      set_full_line(line, tmp);
      if (my_strcmp(end, line) == 0)
	{
	  bzero(line, CMD_SIZE);
	  bzero(tmp, CMD_SIZE);
	  my_putchar('\n', 1);
	  return (-1);
	}
      my_putstr(line, fd);
      my_putchar('\n', fd);
      my_putstr("\n> ", 1);
      bzero(line, CMD_SIZE);
      bzero(tmp, CMD_SIZE);
    }
  else
    return (doubleleft_conditions(line, tmp, input, 1));
  return (0);
}

void	get_double_left(const int fd, const char *end)
{
  int	endread;
  char	input[3];
  char	*line;
  char	*tmp;

  my_putstr("> ", 1);
  endread = 0;
  line = xmalloc(sizeof(char) * (CMD_SIZE + 1));
  tmp = xmalloc(sizeof(char) * (CMD_SIZE + 1));
  bzero(line, CMD_SIZE);
  bzero(tmp, CMD_SIZE);
  bzero(input, 3);
  while (endread >= 0 && read(0, input, 3) >= 0)
    {
      endread = doubleleft_action(line, tmp, input, fd, end);
      bzero(input, 3);
    }
  xfree(line);
  xfree(tmp);
}

int	double_left(char **line, const int place, t_env *env)
{
  int	fd;
  char	*str;
  char	*tmp;

  if ((fd = creat("/tmp/42shtmp",
                  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (my_putstr(ERR_CREATE_FAIL, 2));
  get_double_left(fd, line[place + 1]);
  close(fd);
  line[place][1] = '\0';
  tmp = line[place + 1];
  str = xmalloc(sizeof(char) * 13);
  my_bzero(str, 12);
  my_strcpy(str, "/tmp/42shtmp");
  line[place + 1] = str;
  exec_line(line, env);
  line[place + 1] = tmp;
  xfree(str);
  line[place][1] = '<';
  return (0);
}
