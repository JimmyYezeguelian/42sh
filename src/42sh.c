/*
** 42sh.c for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Wed Apr  2 09:50:44 2014 Newton Guillaume
** Last update Sun May 25 14:51:29 2014 Newton Guillaume
*/

#include "42sh.h"

void		set_full_line(char *line, char *tmp)
{
 int		i;

  i = my_strlen(tmp);
  while (--i >= 0)
    {
      strcat(line, &tmp[i]);
      tmp[i] = '\0';
    }
}

int		line_null(t_line *command, t_env *env)
{
  my_putchar('\n', 1);
  bzero(command->line, CMD_SIZE);
  bzero(command->tmp, CMD_SIZE);
  aff_prompt(env, 0);
  return (0);
}

int		action(t_line *command, const char *input,
			const int fd, t_env *env)
{
  char		*str;
  char		**tabb;

  if (input[0] == '\n')
    {
      set_full_line(command->line, command->tmp);
      str = epur_str(command->line);
      if (str == NULL)
	return (line_null(command, env));
      tabb = my_str_to_wordtab(str, ' ');
      xfree(str);
      my_putstr("\n", 1);
      if (tabb[0] != NULL && (my_strcmp(tabb[0], "exit") == 0))
	{
	  freetab(tabb);
	  return (-1);
	}
      after_clean_str(command->line, tabb, env, command->tmp);
    }
  else
    return (conditions(command->line, command->tmp, input, fd));
  return (0);
}

void		sh(const int fd, t_env *env)
{
  int		endread;
  char		input[3];
  t_line	command;

  aff_ascii(fd);
  aff_prompt(env, 42);
  endread = 0;
  command.line = xmalloc(sizeof(char) * (CMD_SIZE + 1));
  command.tmp = xmalloc(sizeof(char) * (CMD_SIZE + 1));
  my_bzero(command.line, CMD_SIZE);
  my_bzero(command.tmp, CMD_SIZE);
  my_bzero(input, 3);
  while (endread >= 0 && read(0, input, 3) >= 0)
    {
      endread = action(&command, input, fd, env);
      my_bzero(input, 3);
    }
  my_putchar('\n', fd);
  xfree(command.line);
  xfree(command.tmp);
  free_list(env);
  my_putstr(LEAVING_SHELL, 1);
}
