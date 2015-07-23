/*
** epur_str_size.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Jimmy Yezeguelian
** Login   <yezegu_j@epitech.net>
**
** Started on  Mon May 12 13:13:25 2014 Jimmy Yezeguelian
** Last update Sat May 24 11:05:33 2014 Yezeguelian Jimmy
*/

#include "42sh.h"

char		*first_epur(char *str)
{
  int		i;
  int		k;
  char		*tmp;
  int		size;

  size = my_strlen(str);
  tmp = xmalloc(sizeof(char) * size + 1);
  my_bzero(tmp, size);
  i = 0;
  k = 0;
  while (str[i] == ' ' && str[i] != '\0')
    i++;
  while (str[i])
    {
      while (str[i] && ((str[i] == ' ' && str[i + 1] == ' ') ||
			(str[i] == '\t' && str[i + 1] == '\t')))
	i++;
      tmp[k] = str[i];
      k++;
      i++;
    }
  return (tmp);
}

int		count_size(char *str, t_epur *e)
{
  t_count	c;

  c.count = 0;
  c.i = 0;
  while (str[c.i + 1] != '\0')
    {
      c.l = 0;
      while (c.l < 5)
	{
	  if (c.i - 1 >= 0)
	    if (str[c.i] == e->com[c.l] && (str[c.i - 1] != ' ' ||
					    str[c.i + 1] != ' '))
	      {
		c.count += 2;
		c.i += 2;
		c.l++;
	      }
	    else
	      c.l++;
	  else
	    c.l++;
	}
      c.i++;
    }
  return (c.count);
}
