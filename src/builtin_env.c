/*
** builtin_env.c for 42sh in /home/sicard_f/rendu/42sh/src
**
** Made by Flavien Sicard
** Login   <sicard_f@epitech.net>
**
** Started on  Wed Apr  2 11:34:35 2014 Flavien Sicard
** Last update Sun May 25 15:38:07 2014 Robin Maronier
*/

#include "42sh.h"

int	tablen(const char **tabb)
{
  int	i;

  i = 0;
  while (tabb[i] != NULL)
    i++;
  return (i);
}

void	fill_env(t_env *elem, char **tabb, t_env *tmp)
{
  tmp->next = xmalloc(sizeof(t_env));
  elem = tmp->next;
  elem->env_name = xmalloc(sizeof(char) * (my_strlen(tabb[1]) + 1));
  my_bzero(elem->env_name, my_strlen(tabb[1]) + 1);
  my_strcpy(elem->env_name, tabb[1]);
  elem->env_value = xmalloc(sizeof(char) * (my_strlen(tabb[2]) + 1));
  my_bzero(elem->env_value, my_strlen(tabb[2]) + 1);
  my_strcpy(elem->env_value, tabb[2]);
  elem->next = NULL;
}

int	my_setenv(t_env *env, char **tabb)
{
  t_env	*elem;
  t_env	*tmp;

  if (tabb[1] == NULL || tabb[2] == NULL)
    {
      my_putstr("ERROR: bad argument given\n", 2);
      return (1);
    }
  elem = env;
  while (elem != NULL)
    {
      if (my_strcmp(elem->env_name, tabb[1]) == 0)
	{
	  env->env_value = xmalloc(sizeof(char) * (my_strlen(tabb[2]) + 1));
	  my_bzero(elem->env_value, my_strlen(tabb[2]));
	  my_strcpy(elem->env_value, tabb[2]);
	  return (0);
	}
      tmp = elem;
      elem = elem->next;
    }
  fill_env(elem, tabb, tmp);
  return (0);
}

int	my_env(t_env *env)
{
  while (env != NULL)
    {
      my_putstr(env->env_name, 1);
      my_putstr("=", 1);
      my_putstr(env->env_value, 1);
      my_putstr("\n", 1);
      env = env->next;
    }
  return (0);
}
