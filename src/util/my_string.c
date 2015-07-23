/*
** my_string.h for 42sh in /home/guillaume/Coding/42sh/src/util
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Sun May 25 15:45:35 2014 Newton Guillaume
** Last update Sun May 25 16:17:13 2014 Newton Guillaume
*/

#include "42sh.h"

int	my_strcmp(const char *str1, const char *str2)
{
  int	i;

  i = 0;
  if (str1 != NULL && str2 != NULL)
    {
      while (str1[i] && str2[i])
	{
	  if (str1[i] != str2[i])
	    return (1);
	  i++;
	}
      if (str1[i] != str2[i])
	return (1);
      else
	return (0);
    }
  else
    return (1);
}

int	my_strcat(char *dest, const char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (dest == NULL || src == NULL)
    return (-1);
  while (dest[i] != '\0')
    i++;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  return (0);
}

int	my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (-1);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (0);
}

int	my_strncpy(char *dest, const char *src, const int n)
{
  int	i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (-1);
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (0);
}

int	my_bzero(char *str, const int n)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (i <= n)
    {
      str[i] = '\0';
      i++;
    }
  return (0);
}
