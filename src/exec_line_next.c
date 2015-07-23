/*
** exec_line_next.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Yezeguelian Jimmy
** Login   <yezegu_j@epitech.net>
**
** Started on  Sat May 24 11:56:30 2014 Yezeguelian Jimmy
** Last update Sun May 25 18:52:09 2014 Yezeguelian Jimmy
*/

#include "42sh.h"

void	execution(char **tabb, t_env *chaine_env)
{
  int	j;
  char	**path;
  char	*str;
  char	**env;
  char	*value_path;

  j = 0;
  env = tab_env(chaine_env);
  if ((tabb[0][0] == '.' || tabb[0][0] == '/') && access(tabb[0], R_OK) == 0)
    execve(tabb[0], tabb, env);
  else if ((value_path = my_getenv("PATH", chaine_env)) != NULL)
    {
      path = my_str_to_wordtab(value_path, ':');
      while (path[j] != NULL)
        {
	  str = my_complete_str(path[j], tabb[0]);
          if (access(str, R_OK) == 0)
            execve(str, tabb, env);
          j++;
          xfree(str);
        }
    }
  printf("42sh: command not found : %s\n", tabb[0]);
  exit(-1);
}
