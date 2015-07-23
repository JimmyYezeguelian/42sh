/*
** tab_env.c for 42sh in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Mon May  5 16:15:02 2014 Robin Maronier
** Last update Sun May 25 18:12:14 2014 Robin Maronier
*/

#include "42sh.h"

void	copy_envline(char *dest, const char *name, const char *value)
{
  my_bzero(dest, my_strlen(name) + my_strlen(value) + 2);
  my_strcpy(dest, name);
  strcat(dest, "=");
  strcat(dest, value);
}

int	count_elem(t_env *bgn)
{
  int	i;
  t_env	*elem;

  i = 0;
  elem = bgn;
  while (elem != NULL)
    {
      i++;
      elem = elem->next;
    }
  return (i);
}

char	**tab_env(t_env *env)
{
  int	i;
  int	size;
  char	**new_env;
  t_env	*elem;

  size = count_elem(env);
  new_env = xmalloc(sizeof(char *) * (size + 1));
  i = 0;
  elem = env;
  while (elem != NULL)
    {
      new_env[i] = xmalloc(sizeof(char) * (my_strlen(elem->env_name)
					   + my_strlen(elem->env_value) + 2));
      my_bzero(new_env[i], my_strlen(elem->env_name)
	       + my_strlen(elem->env_value) + 1);
      copy_envline(new_env[i], elem->env_name, elem->env_value);
      i++;
      elem = elem->next;
    }
  new_env[i] = NULL;
  return (new_env);
}

