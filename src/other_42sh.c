/*
** other_42sh.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Yezeguelian Jimmy
** Login   <yezegu_j@epitech.net>
**
** Started on  Sat May 24 12:06:24 2014 Yezeguelian Jimmy
** Last update Sun May 25 18:21:25 2014 Robin Maronier
*/

#include	"42sh.h"

void	 freetab(char **tabb)
{
  int	 i;

  i = 0;
  while (tabb[i] != NULL)
    {
      xfree(tabb[i]);
      i++;
    }
  xfree(tabb);
}

void	free_list(t_env *env)
{
  t_env	*elem;

  elem = env->next;
  while (elem != NULL)
    {
      xfree(env->env_name);
      xfree(env->env_value);
      xfree(env);
      env = elem;
      elem = elem->next;
    }
  xfree(env->env_name);
  xfree(env->env_value);
  xfree(env);
}

void	my_putnbr(int nbr)
{
  if (nbr >= 10)
    {
      my_putnbr(nbr / 10);
      my_putnbr(nbr % 10);
    }
  else
    my_putchar(48 + nbr, 1);
}

void	after_clean_str(char *line, char **tabb, t_env *env, char *tmp)
{
  history(line, '\0', 'f');
  get_mult_exec(tabb, env);
  my_bzero(line, CMD_SIZE);
  my_bzero(tmp, CMD_SIZE);
  freetab(tabb);
  aff_prompt(env, 1);
}
