/*
** epur_str2.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Jimmy Yezeguelian
** Login   <yezegu_j@epitech.net>
**
** Started on  Tue Apr 15 17:08:21 2014 Jimmy Yezeguelian
** Last update Sun May 25 18:46:45 2014 Yezeguelian Jimmy
*/

#include "42sh.h"

char	*check_pv(char *str, t_epur *e)
{
  if (str[e->i] == ';' && str[e->i + 1] == ';')
    {
      my_putstr("\n42sh : Syntax error near unexpected token « ;; »", 2);
      xfree(e->tmp);
      return (NULL);
    }
  else
    return (e->tmp);
}

char	*my_check_tab(char *str, t_epur *e, int l)
{
  int	i;

  i = 0;
  while (i < 5)
    {
      if (str[e->i + 1] == e->com[l] && str[e->i + 2] == e->com[l]
	  && str[e->i + 3] == e->com[l])
	{
	  printf("\n42sh : Syntax error near unexpected token « %c%c »",
		 str[e->i + 1], str[e->i + 1]);
	  xfree(e->tmp);
	  return (NULL);
	}
      else
	i++;
    }
  return (e->tmp);
}

void	my_space_next(char *str, t_epur *e, int l)
{
  if (str[e->i] == e->com[l]  && str[e->i + 1] == e->com[l] &&
      str[e->i - 1] == ' ' && str[e->i + 2] != ' ')
    {
      e->tmp[e->k++] = e->com[l];
      e->tmp[e->k++] = e->com[l];
      e->tmp[e->k++] = ' ';
      e->i += 2;
    }
  else if (str[e->i] == e->com[l]  && str[e->i + 1] == e->com[l] &&
      str[e->i - 1] == ' ' && str[e->i + 2] == ' ')
    {
      e->tmp[e->k++] = e->com[l];
      e->tmp[e->k++] = e->com[l];
      e->tmp[e->k++] = ' ';
      e->i += 3;
    }
}

void	my_space(char *str, t_epur *e, int l)
{
  if (str[e->i] == e->com[l] && str[e->i + 1] == e->com[l] &&
      str[e->i - 1] != ' ' && str[e->i + 2] != ' ' && str[e->i - 1] != '2')
    {
      e->tmp[e->k++] = ' ';
      e->tmp[e->k++] = e->com[l];
      e->tmp[e->k++] = e->com[l];
      e->tmp[e->k++] = ' ';
      e->i += 2;
    }
  if (str[e->i] == e->com[l] && str[e->i + 1] == e->com[l] &&
      str[e->i - 1] != ' ' && str[e->i + 2] == ' ' && str[e->i - 1] != '2')
    {
      e->tmp[e->k++] = ' ';
      e->tmp[e->k++] = e->com[l];
      e->tmp[e->k++] = e->com[l];
      e->i += 2;
    }
  my_space_next(str, e, l);
}

int	check_double(char *str, t_epur *e, int l)
{
  if ((e->tmp = check_pv(str, e)) == NULL)
    return (-1);
  else if ((e->tmp = my_check_tab(str, e, l)) == NULL)
    return (-1);
  else
    {
      my_space(str, e, l);
      return (1);
    }
}
