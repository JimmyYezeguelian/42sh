/*
** unsetenv.c for 42sh in /Users/sicard_f/Github/42sh-final
**
** Made by Sicard Flavien
** Login   <sicard_f@epitech.net>
**
** Started on  Mon May  5 21:28:07 2014 Sicard Flavien
** Last update Sun May 25 18:11:10 2014 Robin Maronier
*/

#include "42sh.h"

void	modif_env(t_env *chain_env, t_env *tmp_before)
{
  chain_env->env_name = chain_env->next->env_name;
  chain_env->env_value = chain_env->next->env_value;
  tmp_before = chain_env->next->next;
  xfree(chain_env->next);
  chain_env->next = tmp_before;
}

int	if_error(int error)
{
  if (error == 1)
    {
      my_putstr("Can't find this environement variable\n", 2);
      return (1);
    }
  return (0);
}

int	my_unsetenv(t_env *chain_env, char **str)
{
  int	error;
  t_env	*tmp_before;

  error = 1;
  tmp_before = NULL;
  if (str[1] != NULL)
    {
      while (chain_env != NULL && error == 1)
	{
	  if (my_strcmp(chain_env->env_name, str[1]) == 0)
	    {
	      if (tmp_before == NULL)
		modif_env(chain_env, tmp_before);
	      else
		tmp_before->next = chain_env->next;
	      error = 0;
	    }
	  tmp_before = chain_env;
	  chain_env = chain_env->next;
	}
      if (if_error(error) == 1)
	return (1);
    }
  return (0);
}
