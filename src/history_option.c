/*
** history_option.c for 42sh in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Tue May 13 17:27:01 2014 Robin Maronier
** Last update Fri May 23 07:23:52 2014 Newton Guillaume
*/

#include "42sh.h"

t_hist		*fill_history_list(t_hist *hist, char *str)
{
  if (hist == NULL)
    hist = xmalloc(sizeof (t_hist));
  hist->next = xmalloc(sizeof(t_hist));
  hist->next->prev = hist;
  hist = hist->next;
  hist->line = xmalloc(sizeof(char) * (my_strlen(str) + 1));
  strcpy(hist->line, str);
  hist->next = NULL;
  return (hist);
}

int		select_history(char *str, t_hist *hist, char arrow, int test)
{
 static t_hist	*tmp = NULL;

 if (test == 1 || tmp == NULL)
   tmp = hist;
 my_bzero(str, my_strlen(str));
 if (tmp != NULL && arrow == DOWN && tmp->next != NULL)
   {
     my_strcpy(str, tmp->line);
     tmp = tmp->next;
   }
 else if (tmp != NULL && arrow == UP && tmp->prev != NULL)
   {
     my_strcpy(str, tmp->line);
     tmp = tmp->prev;
   }
 return (0);
}

t_hist		*fill_history(char *str, t_hist *hist,
			      t_hist *bgn, const int fd)
{
  write(fd, str, my_strlen(str));
  write(fd, "\n", 1);
  hist = fill_history_list(hist, str);
  bgn = hist;
  return (bgn);
}

void		empty_history(int fd)
{
  close(fd);
  history(NULL, '\0', 'c');
}
