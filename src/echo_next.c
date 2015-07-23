/*
** echo_next.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Yezeguelian Jimmy
** Login   <yezegu_j@epitech.net>
**
** Started on  Sat May 24 11:32:23 2014 Yezeguelian Jimmy
** Last update Sun May 25 13:49:28 2014 Robin Maronier
*/

#include "42sh.h"

int	test_opt(char **av, char *tabb, int y, int i)
{
  int	bo;

  bo = 0;
  y++;
  while (av[i][y] != '\0')
    {
      if (av[i][y] == 'e' || av[i][y] == 'E')
        tabb[0] = av[i][y];
      else if (av[i][y] == 'n')
        tabb[1] = av[i][y];
      else if (av[i][y] == 's')
        tabb[2] = av[i][y];
      else
        bo = 1;
      y++;
    }
  if (av[i][y - 1] == '-')
    bo = 1;
  return (bo);
}

int	my_lenght_var(char *str, int i)
{
  int	lenght;

  while ((str && str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')
    {
      lenght++;
      i++;
    }
  return (lenght);
}

char	*cpy_name_env(int i, int len, char *str)
{
  int	i2;
  char	*var;

  i2 = 0;
  var = xmalloc(sizeof(char) * len + 1);
  while (i2 != len)
    {
      var[i2] = str[i];
      i2++;
      i++;
    }
  var[i2] = '\0';
  return (var);
}

int	write_var_env(char *str, int i, t_env *env)
{
  char	*var;
  int	len;

  if (str[i] == '$')
    {
      i++;
      len = my_lenght_var(str, i);
      var = cpy_name_env(i, len, str);
      while (env != NULL)
	{
	  if (my_strcmp(var, env->env_name) == 0)
	    {
	      my_putstr(env->env_value, 1);
	      xfree(var);
	      return (len + 1);
	    }
	  env = env->next;
	}
      xfree(var);
      return (len);
    }
  return (0);
}

void	my_put_echo(char *str, t_env *env)
{
  int	i;
  int	add;

  i = 0;
  while (str[i] != '\0')
    {
      if ((add = write_var_env(str, i, env)) != 0)
	i = i + add + 1;
      else
	{
	  my_putchar(str[i], 1);
	  i++;
	}
    }
}
