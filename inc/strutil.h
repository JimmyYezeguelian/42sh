/*
** strutil.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Thu May 22 07:45:46 2014 Newton Guillaume
** Last update Fri May 23 07:17:01 2014 Newton Guillaume
*/

#ifndef	_STRUTIL_H_
#define	_STRUTIL_H_

void	my_putchar(const char c, const int fd);
int	my_strlen(const char *str);
int	my_putstr(const char *str, const int fd);
int	my_putrevstr(const char *str, const int fd);
int	my_strcmp(const char *str1, const char *str2);
int	my_strcat(char *dest, const char *src);
int	my_strcpy(char *dest, const char *src);
int	my_strncpy(char *dest, const char *src, const int n);
int	my_bzero(char *str, const int n);

#endif
