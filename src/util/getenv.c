/*
** getenv.c for 42sh in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Wed May  7 18:39:39 2014 Robin Maronier
** Last update Sun May 25 16:36:49 2014 Newton Guillaume
*/

#include "42sh.h"

char	*my_getenv(char *str, t_env *env)
{
  int	len;
  char	*value;
  t_env	*bgn;

  bgn = env;
  while (env != NULL)
    {
      if (my_strcmp(str, env->env_name) == 0)
	{
	  len = strlen(env->env_value);
	  value = xmalloc(sizeof(char) * (len + 1));
	  my_bzero(value, len + 1);
	  my_strcpy(value, env->env_value);
	  env = bgn;
	  return (value);
	}
      env = env->next;
    }
  env = bgn;
  return (NULL);
}
