/*
** epur_str_error.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Jimmy Yezeguelian
** Login   <yezegu_j@epitech.net>
**
** Started on  Tue May 13 18:09:06 2014 Jimmy Yezeguelian
** Last update Sun May 25 19:18:09 2014 Yezeguelian Jimmy
*/

#include "42sh.h"

int	error_token(char *str, t_epur *e, int l)
{
  if (str[e->i] == e->com[l] && str[e->i + 1] == ' '
      && str[e->i + 2] == e->com[l])
    {
      my_putstr("\n42sh : Syntax error near unexpected token « ", 2);
      my_putchar(str[e->i], 2);
      my_putstr(" »\n", 2);
      xfree(e->tmp);
      return (-1);
    }
  else
    return (1);
}

int	check_tab_error(char **com)
{
  int	i;

  i = 0;
  if (com[i][0] == '|' || com[i][0] == '&' || com[i][0] == '<'
      || com[i][0] == '>' || com[i][0] == ';')
    {
      my_putstr("42sh : Syntax error near unexpected token « ", 2);
      my_putchar(com[i][0], 2);
      my_putstr(" »\n", 2);
      return (-1);
    }
  return (0);
}

char	*check_end(char *str, t_epur *e)
{
  int	i;
  int	l;

  l = 0;
  i = e->i;
  while (l < 5)
    {
      if (str[i] == e->com[l] && str[i + 1] != e->com[l])
  	{
  	  while (str[i] != '\0')
  	    {
  	      if (str[i] >= 'A' && str[i] <= 'z' && str[i] != e->com[l])
  		return (e->tmp);
  	      else
  		i++;
  	    }
  	  e->tmp[e->i++] = '\0';
  	  return (e->tmp);
  	}
      else
  	l++;
    }
  return (e->tmp);
}

int	check_start(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t' && (str[i] < 'a' || str[i] > 'z') &&
	  (str[i] < 'A' || str[i] > 'Z') && str[i] != '/' && str[i] != '.')
	{
	  my_putstr("\n42sh : Syntax error near unexpected token « ", 2);
	  my_putchar(str[i], 2);
	  my_putstr(" »", 2);
	  return (-1);
	}
      else
	return (1);
    }
  return (-1);
}

int		epur_end(char *str)
{
  int		i;

  i = my_strlen(str) - 1;
  while (i > 0)
    {
      if (str[i] == ' ')
	{
	  str[i] = '\0';
	  i--;
	}
      else if (str[i] == '|' || str[i] == '&' || str[i] == '<'
	       || str[i] == '>' || str[i] == ';')
	{
	  my_putstr("\n42sh : Syntax error near unexpected token « ", 2);
	  my_putchar(str[i], 2);
	  my_putstr(" »", 2);
	  return (-1);
	}
      else if ((str[i] >= 'a' || str[i] <= 'z') &&
	       (str[i] >= 'A' || str[i] <= 'Z'))
	return (1);
      i--;
    }
  return (1);
}
