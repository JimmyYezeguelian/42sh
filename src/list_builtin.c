/*
** list_builtin.c for 42sh in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Tue May 13 17:37:36 2014 Robin Maronier
** Last update Sun May 25 18:23:47 2014 Robin Maronier
*/

#include "42sh.h"

int	check_builtin_next(char **tabb, t_env *env)
{
  if (my_strcmp(tabb[0], "echo") == 0)
    my_echo(tabb, env);
  else if (my_strcmp(tabb[0], "man") == 0 && tabb[1] != NULL)
    {
      if (my_man(tabb[1]) == -1)
	return (-1);
    }
  else
    return (-1);
  return (0);
}

int	check_builtin(char **tabb, t_env *env)
{
  int	rt;

  rt = 0;
  if (my_strcmp(tabb[0], "unsetenv") == 0)
    rt = my_unsetenv(env, tabb);
  else if (my_strcmp(tabb[0], "setenv") == 0)
    rt = my_setenv(env, tabb);
  else if (my_strcmp(tabb[0], "env") == 0)
    rt = my_env(env);
  else if (my_strcmp(tabb[0], "cd") == 0)
    rt = my_cd(tabb, env);
  else if (my_strcmp(tabb[0], "history") == 0)
    history(NULL, '\0', 'a');
  else
    return (check_builtin_next(tabb, env));
  return (rt);
}
