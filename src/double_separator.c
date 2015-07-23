/*
** double_separator.c for 42sh in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Mon May 19 11:40:19 2014 Robin Maronier
** Last update Fri May 23 10:12:52 2014 Newton Guillaume
*/

#include "42sh.h"

int	get_double(char **line, const int place, t_env *env)
{
  int	rtrn;
  char	*tmp;

  rtrn = 0;
  if (my_strcmp(line[place], "||") == 0)
    {
      tmp = line[place];
      line[place] = NULL;
      rtrn = exec_line(line, env);
      line[place] = tmp;
      if (rtrn != 0)
	rtrn = exec_line(&line[place + 1], env);
      else
	rtrn = -1;
    }
  else if (my_strcmp(line[place], "&&") == 0)
    {
      tmp = line[place];
      line[place] = NULL;
      rtrn = exec_line(line, env);
      line[place] = tmp;
      if (rtrn == 0)
	rtrn = exec_line(&line[place + 1], env);
    }
  return (rtrn);
}
