/*
** exec_line.c for 42sh in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Wed Apr 23 11:11:29 2014 Robin Maronier
** Last update Sun May 25 18:52:13 2014 Yezeguelian Jimmy
*/

#include "42sh.h"

int	check_for_execution(char **tabb, t_env *env)
{
  int	rtrn;
  int	rt;

  if ((rt = check_builtin(tabb, env)) != -1)
    return (rt);
  if (xfork() == 0)
    execution(tabb, env);
  wait(&rtrn);
  if (WIFSIGNALED(rtrn) != 0)
    {
      if (WTERMSIG(rtrn) == SIGSEGV)
	{
	  my_putstr("Segmentation Fault (Core Dumped)\n", 0);
	  my_putstr("\tQuitting program...\n", 0);
	}
      if (WTERMSIG(rtrn) == SIGINT)
	my_putstr("^C\n", 2);
    }
  return (rtrn);
}

int	get_execution(char **tabb, int j2, t_env *env)
{
  int	rtrn;
  char	*str;
  char	**final;

  str = xmalloc(sizeof(char) * (my_strlen(tabb[j2]) + 4096));
  my_bzero(str, my_strlen(tabb[j2]) + 4096);
  my_strcpy(str, tabb[j2]);
  j2++;
  while (tabb[j2] != NULL)
    {
      my_strcat(str, " ");
      my_strcat(str, tabb[j2]);
      j2++;
    }
  final = my_str_to_wordtab(str, ' ');
  xfree(str);
  rtrn = check_for_execution(final, env);
  freetab(final);
  return (rtrn);
}

int	double_redirect(char **tabb, int *j, t_env *env)
{
  while (*j >= 0 && my_strcmp(tabb[*j], "&&") && my_strcmp(tabb[*j], "||"))
    *j = *j - 1;
  if (*j < 0 || *j == 0)
    return (0);
  else
    return (get_double(tabb, *j, env));
}

int	unique_redirect(char **tabb, int *j, t_env *env)
{
  while (*j >= 0 && tabb[*j][0] != ';' && tabb[*j][0] != '|'
	 && tabb[*j][0] != '>' && tabb[*j][0] != '<')
    *j = *j - 1;
  if (*j < 0 || *j == 0)
    return (0);
  else
    return (get_redirect(tabb, *j, env));
}

int	exec_line(char **tabb, t_env *env)
{
  int	j;
  int	tmp;
  int	rtrn;

  j = 0;
  rtrn = -1;
  while (tabb[j] != NULL)
    j++;
  j--;
  tmp = j;
  rtrn = double_redirect(tabb, &j, env);
  if (j < 0 || j == 0)
    {
      j = tmp;
      rtrn = unique_redirect(tabb, &j, env);
    }
  if (j < 0 || j == 0)
    rtrn = get_execution(tabb, 0, env);
  return (rtrn);
}
