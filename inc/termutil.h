/*
** termutil.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Thu May 22 16:03:49 2014 Newton Guillaume
** Last update Thu May 22 16:05:40 2014 Newton Guillaume
*/

#ifndef	_TERMUTIL_H_
#define	_TERMUTIL_H_

int	set_raw_mode(struct termios *termios_p);
int     ini_all(struct termios *termios_p, t_env *env);

#endif
