/*
** echo.c for 42sh in /home/sicard_f/rendu/42sh
**
** Made by Sicard Flavien
** Login   <sicard_f@epitech.net>
**
** Started on  Fri May 23 07:18:55 2014 Flavien Sicard
** Last update Sun May 25 14:57:01 2014 Robin Maronier
*/

#include "42sh.h"

void	opt(char **av, char *tabb)
{
  int	i;
  int	y;
  int	bo;

  i = 1;
  my_bzero(tabb, 3);
  while (av[i] != NULL && av[i][0] == '-')
    {
      y = 0;
      if (av[i][y] == '-')
	bo = test_opt(av, tabb, y, i);
      if (bo == 1)
	{
	  my_putstr(av[i], 1);
	  if (av[i + 1] != NULL && tabb[2] != 's')
	    my_putchar(' ', 1);
	}
      i++;
    }
}

void	caract(char c, char *tabb)
{
  if (c == 'a')
    my_putchar('\a', 1);
  else if (c == 'b')
    my_putchar('\b', 1);
  else if (c == 'c')
    tabb[1] = 'n';
  else if (c == 'f')
    my_putchar('\f', 1);
  else if (c == 'n')
    my_putchar('\n', 1);
  else if (c == 'r')
    my_putchar('\r', 1);
  else if (c == 't')
    my_putchar('\t', 1);
  else if (c == 'v')
    my_putchar('\v', 1);
  else if (c == '\\')
    my_putchar('\\', 1);
}

void	my_put_e(char *str, char *tabb, t_env *env)
{
  int	i;
  int	add;

  i = 0;
  while (str[i] != '\0')
    {
      add = write_var_env(str, i, env);
      i = i + add;
      if (str[i] == '\\')
 	{
 	  caract(str[i + 1], tabb);
 	  i++;
 	}
      else
 	my_putchar(str[i], 1);
      i++;
    }
}

int		check_man_echo(char **av)
{
  if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
    {
      my_man("echo");
      return (0);
    }
  return (-1);
}

int		my_echo(char **av, t_env *env)
{
  char		tabb[3];
  int		i;

  if (av[1] == NULL || check_man_echo(av) == 0)
    return (0);
  i = 1;
  opt(av, tabb);
  while (av[i][0] == '-' && av[i + 1] != NULL)
    i++;
  if (av[i][0] == '-')
    i++;
  while (av[i] != NULL)
    {
      if (tabb[0] == 'E' || tabb[0] == '\0')
	my_put_echo(av[i], env);
      else if (tabb[0] == 'e')
	my_put_e(av[i], tabb, env);
      i++;
      if (av[i] != NULL && tabb[2] != 's')
	my_putchar(' ', 1);
    }
  if (tabb[1] != 'n')
    my_putchar('\n', 1);
  return (0);
}
