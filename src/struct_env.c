/*
** struct_env.c for 42sh in /Users/sicard_f/Github/42sh/src
**
** Made by Flavien Sicard
** Login   <sicard_f@epitech.net>
**
** Started on  Wed Apr  2 16:31:31 2014 Flavien Sicard
** Last update Sun May 25 18:17:14 2014 Robin Maronier
*/

#include "42sh.h"

char	*chain_env_name(char *env)
{
  int	i;
  char	*name = NULL;

  i = 0;
  while (env[i] != '=' && env[i] != '\0')
    i++;
  if (env[i] == '=')
    {
      name = xmalloc((i + 2) * sizeof(char));
      my_bzero(name, i + 2);
      i = 0;
      while (env[i] != '=')
        {
          name[i] = env[i];
          i++;
        }
      name[i] = '\0';
    }
  return (name);
}

char	*chain_env_value(char *env)
{
  int	i;
  int	k;
  char	*value;

  value = NULL;
  i = 0;
  while (env[i] != '=' && env[i] != '\0')
    i++;
  if (env[i] == '=')
    {
      k = i + 1;
      while (env[k] != '\0')
        k++;
      value = xmalloc((k - i + 1) * sizeof(char));
      my_bzero(value, k - i + 1);
      k = 0;
      while (env[++i] != '\0')
        {
          value[k] = env[i];
          k++;
        }
      value[k] = '\0';
    }
  return (value);
}

t_env	*new_elem_chain_env(char *env)
{
  t_env	*elem;

  elem = xmalloc(sizeof(t_env));
  if (elem == NULL)
    return (NULL);
  elem->env_name = chain_env_name(env);
  elem->env_value = chain_env_value(env);
  elem->next = NULL;
  return (elem);
}

t_env	*fill_list_env(char **env)
{
  int	i;
  t_env	*elem;
  t_env	*bgn;

  i = 0;
  elem = new_elem_chain_env(env[i]);
  bgn = elem;
  while (env[i + 1] != NULL)
    {
      i++;
      elem->next = new_elem_chain_env(env[i]);
      elem = elem->next;
    }
  return (bgn);
}

void	aff_env(t_env *chain_env)
{
  int	i;

  i = 0;
  while (chain_env->next != NULL)
    {
      printf("%s=%s\n", chain_env->env_name, chain_env->env_value);
      chain_env = chain_env->next;
      i++;
    }
}
