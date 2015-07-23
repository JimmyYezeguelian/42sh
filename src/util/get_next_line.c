/*
** get_next_line.c for lem_in in /Users/sicard_f/Github/Lem-In
**
** Made by Sicard Flavien
** Login   <sicard_f@epitech.net>
**
** Started on  Tue Apr 29 10:28:41 2014 Sicard Flavien
** Last update Sun May 25 16:36:27 2014 Newton Guillaume
*/

#include "42sh.h"

char		get_char(const int fd)
{
  char		c;
  static int	i = 0;
  static int	j = 0;
  static char	buffer[BUFF_SIZE];

  if (i == j)
    {
      j = read(fd, buffer, 2);
      i = 0;
    }
  if (j == 0 || j == -1)
    return (-1);
  c = buffer[i];
  i++;
  return (c);
}

char		*get_next_line(const int fd)
{
  int		i;
  char		*buffer;

  i = 0;
  buffer = xmalloc(sizeof(char*) * 2);
  while ((buffer[i] = get_char(fd)) != '\0')
    {
      if (buffer[i] == '\n')
        {
          buffer[i] = '\0';
          return (buffer);
        }
      if (buffer[i] <= 0)
	{
	  xfree(buffer);
	  return (NULL);
	}
      i = i + 1;
    }
  xfree(buffer);
  return (NULL);
}
