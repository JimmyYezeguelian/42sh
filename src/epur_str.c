/*
** epur_str.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Jimmy Yezeguelian
** Login   <yezegu_j@epitech.net>
**
** Started on  Wed Apr  2 10:18:02 2014 Jimmy Yezeguelian
** Last update Sun May 25 18:05:19 2014 Yezeguelian Jimmy
*/

#include "42sh.h"

t_epur		init_epur(char *str)
{
  t_epur	e;
  int		count;
  char		*tmp2;

  e.com = xmalloc(sizeof(char) * 5);
  e.com[0] = '|';
  e.com[1] = '&';
  e.com[2] = ';';
  e.com[3] = '>';
  e.com[4] = '<';
  e.k = 0;
  e.i = 0;
  tmp2 = first_epur(str);
  count = count_size(tmp2, &e);
  e.tmp = xmalloc(sizeof(char) * (my_strlen(tmp2) + count) + 1);
  my_bzero(e.tmp, my_strlen(tmp2) + count);
  xfree(tmp2);
  return (e);
}

void		epur_single_next(char *str, t_epur *e, int j)
{
  if (str[e->i] == e->com[j] && str[e->i - 1] != ' '
      && str[e->i + 1] == ' ')
    {
      e->tmp[e->k++] = ' ';
      e->tmp[e->k++] = e->com[j];
      e->i++;
    }
  else if (str[e->i] == e->com[j] && str[e->i - 1] == ' '
	   && str[e->i + 1] != ' ')
    {
      e->tmp[e->k++] = e->com[j];
      e->tmp[e->k++] = ' ';
      e->i++;
    }
}

char		*epur_single(char *str, t_epur *e)
{
  int		l;

  l = 0;
  while (l < 5)
    {
      if (error_token(str, e, l) == -1)
	return (NULL);
      if (str[e->i] == e->com[l] && str[e->i + 1] != e->com[l]
	  && str[e->i - 1] != '2')
	{
	  if (str[e->i - 1] != ' ' && str[e->i + 1] != ' ')
	    {
	      e->tmp[e->k++] = ' ';
	      e->tmp[e->k++] = e->com[l];
	      e->tmp[e->k++] = ' ';
	      e->i++;
	    }
	  epur_single_next(str, e, l++);
	}
      else
	if (check_double(str, e, l++) == -1)
	  return (NULL);
    }
  return (e->tmp);
}

int		epur_fct(char *str, t_epur *e)
{
  while (str[e->i] == ' ' && str[e->i] != '\0')
    e->i++;
  while (str[e->i] != '\0')
    {
      while ((str[e->i] == ' ' && str[e->i + 1] == ' ') ||
	     (str[e->i] == '\t' && str[e->i + 1] == '\t'))
	e->i++;
      if ((e->tmp = epur_single(str, e)) != NULL)
	{
	  e->tmp[e->k] = str[e->i];
	  e->k++;
	  e->i++;
	}
      else
	return (-1);
      e->tmp[e->k] = '\0';
    }
  e->tmp = check_end(str, e);
  if (check_start(e->tmp) == -1 || epur_end(str) == -1)
    return (-1);
  else
    return (1);
}

char		*epur_str(char *str)
{
  t_epur	e;

  if (str != NULL && my_strlen(str) > 0)
    {
      e = init_epur(str);
      if (epur_fct(str, &e) != -1)
	{
	  xfree(e.com);
	  return (e.tmp);
	}
      else
	{
	  xfree(e.com);
	  return (NULL);
	}
    }
  else
    return (NULL);
}
