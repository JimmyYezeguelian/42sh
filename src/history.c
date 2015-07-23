/*
** history.c for 42sh in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Tue May  6 09:38:34 2014 Robin Maronier
** Last update Sat May 24 10:48:57 2014 Robin Maronier
*/

#include "42sh.h"

void		free_history(t_hist *hist)
{
  while (hist != NULL)
    {
      xfree(hist->line);
      hist->line = NULL;
      if (hist->next != NULL)
	xfree(hist->next);
      hist->next = NULL;
      hist = hist->prev;
    }
}

void		aff_history(t_hist *hist)
{
  int		cpt;
  t_hist	*tmp;

  cpt = 1;
  tmp = hist;
  while (tmp->prev != NULL && cpt < 1000)
    {
      printf("%d  %s \n", cpt, tmp->line);
      cpt++;
      tmp = tmp->prev;
    }
}

t_hist		*creat_hist(const int fd)
{
  char		*line;
  t_hist	*bgn;
  t_hist	*hist;

  hist = xmalloc(sizeof(t_hist));
  hist->next = NULL;
  hist->prev = NULL;
  bgn = hist;
  while ((line = get_next_line(fd)) != NULL)
    {
      hist->prev = xmalloc(sizeof(t_hist));
      hist->prev->next = hist;
      hist = hist->prev;
      hist->line = xmalloc(sizeof(char) * (my_strlen(line) + 1));
      my_bzero(hist->line, my_strlen(line) + 1);
      my_strcpy(hist->line, line);
      hist->prev = NULL;
      xfree(line);
    }
  return (bgn);
}

int		history(char *str, const char arrow, char fct)
{
  static int	fd;
  static t_hist	*bgn = NULL;
  static t_hist	*hist = NULL;
  static int	test = 0;

  if (fct == 'c' && (fd = open("./.history", O_RDWR
			       | O_CREAT | O_TRUNC, 00644)) != -1)
    {
      hist = creat_hist(fd);
      bgn = hist;
      test = 1;
    }
  else if (fct == 'c')
    return (my_putstr(ERR_OPEN_FAIL, 2));
  else if (fct == 'f')
    {
      hist = fill_history(str, hist, bgn, fd);
      bgn = hist;
      test = 1;
    }
  else if (fct == 's')
    test = select_history(str, bgn, arrow, test);
  else if (fct == 'a')
    aff_history(bgn);
  return (0);
}
