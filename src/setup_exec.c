/*
** setup_exec.c for 42sh in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Tue May 13 17:35:17 2014 Robin Maronier
** Last update Sun May 25 18:18:15 2014 Robin Maronier
*/

#include "42sh.h"

char	*my_complete_str(char *path, char *strstr)
{
  int	i;
  int	i2;
  char	*str;

  i = 0;
  i2 = 0;
  str = xmalloc(sizeof (char *) * (my_strlen(path) + (my_strlen(strstr)) + 1));
  while (path[i])
    {
      str[i] = path[i2];
      i++;
      i2++;
    }
  str[i] = '/';
  i++;
  i2 = 0;
  while (strstr[i2])
    {
      str[i] = strstr[i2];
      i++;
      i2++;
    }
  str[i] = '\0';
  return (str);
}
