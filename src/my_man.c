/*
** man_echo.c for 42sh in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Sat May 24 10:48:26 2014 Robin Maronier
** Last update Sun May 25 15:52:19 2014 Robin Maronier
*/

#include "42sh.h"

char	*my_str_man(char *str2, char *str_man)
{
  int	y;
  int	i;
  char	my_man[] = "man/";

  i = 0;
  y = 0;
  while (my_man[i] != '\0')
    {
      str_man[y] = my_man[i];
      y++;
      i++;
    }
  i = 0;
  while (str2[i] != '\0')
    {
      str_man[y] = str2[i];
      y++;
      i++;
    }
  str_man[y] = '\0';
  return (str_man);
}

int	my_man(char *str2)
{
  int	nb;
  int	fd;
  char	*str;
  char	*str_man;

  nb = my_strlen(str2);
  str_man = xmalloc(sizeof(char) * (nb + 4));
  str_man = my_str_man(str2, str_man);
  fd = open(str_man, O_RDONLY);
  if (fd == -1)
    return (-1);
  str = get_next_line(fd);
  while (str != NULL)
    {
      my_putstr(str, 1);
      my_putchar('\n', 1);
      str = get_next_line(fd);
    }
  close(fd);
  return (0);
}
