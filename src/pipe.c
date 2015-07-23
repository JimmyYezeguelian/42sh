/*
** pipe.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Jimmy Yezeguelian
** Login   <yezegu_j@epitech.net>
**
** Started on  Mon May  5 14:41:22 2014 Jimmy Yezeguelian
** Last update Sun May 25 18:20:37 2014 Robin Maronier
*/

#include	"42sh.h"

int		get_pipe(char **line, const int place, t_env *env)
{
  t_pipe	pip;

  pip.rtrn = 0;
  if (pipe(pip.pipefd) == -1)
    return (my_putstr("42sh: Error pipe.\n", 2));
  pip.pid = xfork();
  if (pip.pid == 0)
    {
      close(pip.pipefd[0]);
      dup2(pip.pipefd[1], 1);
      pip.tmp = line[place];
      line[place] = NULL;
      exec_line(line, env);
      line[place] = pip.tmp;
      exit(0);
    }
  else
    {
      close(pip.pipefd[1]);
      dup2(pip.pipefd[0], 0);
      exec_line(&line[place + 1], env);
      wait(&pip.rtrn);
      exit(0);
    }
  return (pip.rtrn);
}

int		single_pipe(char **line, const int place, t_env *env)
{
  int		pid;
  int		rtrn;

  rtrn = 0;
  pid = xfork();
  if (pid == 0)
    {
      get_pipe(line, place, env);
      exit(0);
    }
  else
    wait(&rtrn);
  return (rtrn);
}
