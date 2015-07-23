/*
** history.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Thu May 22 09:30:49 2014 Newton Guillaume
** Last update Thu May 22 16:15:48 2014 Newton Guillaume
*/

#ifndef	_HISTORY_H_
#define	_HISTORY_H_

int	history(char *str, const char arrow, char fct);
t_hist	*fill_history(char *str, t_hist *hist,
		      t_hist *bgn, const int fd);
int	select_history(char *str, t_hist *hist, char arrow, int test);

#endif
