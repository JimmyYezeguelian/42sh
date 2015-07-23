/*
** redirect.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Thu May 22 16:16:52 2014 Newton Guillaume
** Last update Fri May 23 07:04:50 2014 Newton Guillaume
*/

#ifndef	_REDIRECT_H_
#define	_REDIRECT_H_

/* REDIRECT.C */
int	get_redirect(char **line, const int place, t_env *env);

/* DOUBLE_LEFT.C */
int	double_left(char **line, const int place, t_env *env);

/* PIPE.C */
int	single_pipe(char **line, const int place, t_env *env);

/* DOUBLE_SEPARATOR.C */
int	get_double(char **line, const int place, t_env *env);

#endif
