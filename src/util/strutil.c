/*
** strutil.c for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Wed Apr  2 10:22:15 2014 Newton Guillaume
** Last update Sun May 25 16:15:10 2014 Newton Guillaume
*/

#include "42sh.h"

void	my_putchar(const char c, const int fd)
{
  write(fd, &c, 1);
}

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i])
	i++;
      return (i);
    }
  return (0);
}

int	my_putstr(const char *str, const int fd)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i])
	i++;
      write(fd, str, i);
      if (fd == 2)
	return (-1);
      return (0);
    }
  return (-1);
}

int	my_putrevstr(const char *str, const int fd)
{
  int	i;
  int	len;

  len = my_strlen(str);
  i = len;
  while (i >= 0)
    {
      my_putchar(str[i], fd);
      i--;
    }
  if (fd == 2)
    return (-1);
  return (0);
}
