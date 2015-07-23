/*
** home_modify.c for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Sun May 25 14:50:21 2014 Newton Guillaume
** Last update Sun May 25 14:52:45 2014 Newton Guillaume
*/

#include "42sh.h"

char	*have_path(char *path, char *home, int len)
{
  char	*str;
  int	i;
  int	i2;

  i = 0;
  i2 = 2;
  str = xmalloc(sizeof(char) * my_strlen(path));
  my_bzero(str, my_strlen(path));
  str[0] = '~';
  str[1] = '/';
  if (my_strcmp(path, home) != 0)
    {
      i = len + 1;
      while (path[i] != '\0')
	{
	  str[i2] = path[i];
	  i2++;
	  i++;
	}
    }
  str[i2] = '\0';
  xfree(path);
  xfree(home);
  return (str);
}

char	*now_path(t_env *env)
{
  char	*home;
  int	len;
  char	*path;

  path = xmalloc(sizeof(char) * 200);
  my_bzero(path, 200);
  path = getcwd(path, 200);
  home = my_getenv("HOME", env);
  len = my_strlen(home);
  if (home != NULL && strncmp(path, home, len) == 0)
    return (have_path(path, home, len));
  xfree(home);
  return (path);
}
