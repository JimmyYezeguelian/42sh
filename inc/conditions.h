/*
** conditions.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Thu May 22 15:58:05 2014 Newton Guillaume
** Last update Fri May 23 07:15:27 2014 Newton Guillaume
*/

#ifndef	_CONDITIONS_H_
#define	_CONDITIONS_H_

/* CONDITIONS.C */
void	write_char(char *line, const char *tmp,
		   const char *input, const int fd);
int	conditions(char *line, char *tmp, const char *input, const int fd);

/* GET_SPECIAL_CHAR.C */
void	get_backspace(char *line, const int fd);
void	delete_char(char *str, const int fd);
void	special_char(char *line, char *tmp, const char *input, const int fd);

#endif
