/*
** redirect.c for 42sh in /home/guillaume/Coding/42sh/src
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Mon May  5 12:41:05 2014 Newton Guillaume
** Last update Sun May 25 18:19:58 2014 Robin Maronier
*/

#include	"42sh.h"

int		fileredirect(char **line, const int place, t_env *env)
{
  int		fd;
  int		pid;
  int		rtrn;
  char		*tmp;

  if ((fd = open(line[place + 1], O_RDONLY)) == -1)
    return (my_putstr(ERR_OPEN_FAIL, 2));
  pid = xfork();
  if (pid == 0)
    {
      dup2(fd, 0);
      tmp = line[place];
      line[place] = NULL;
      exec_line(line, env);
      line[place] = tmp;
      dup2(0, 0);
      close(fd);
      exit(0);
    }
  else
    wait(&rtrn);
  return (rtrn);
}

int		redirect(char **line, const int place, t_env *env)
{
  int		fd;
  int		pid;
  int		rtrn;
  char		*tmp;

  if ((fd = creat(line[place + 1],
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (my_putstr(ERR_CREATE_FAIL, 2));
  pid = xfork();
  if (pid == 0)
    {
      dup2(fd, 1);
      tmp = line[place];
      line[place] = NULL;
      exec_line(line, env);
      line[place] = tmp;
      dup2(1, 1);
      close(fd);
      exit(0);
    }
  else
    wait(&rtrn);
  return (rtrn);
}

int		err_redirect(char **line, const int place, t_env *env)
{
  int		fd;
  int		pid;
  int		rtrn;
  char		*tmp;

  if ((fd = creat(line[place + 1],
                  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (my_putstr(ERR_CREATE_FAIL, 2));
  pid = xfork();
  if (pid == 0)
    {
      dup2(fd, 2);
      tmp = line[place];
      line[place] = NULL;
      exec_line(line, env);
      line[place] = tmp;
      dup2(2, 2);
      close(fd);
      exit(0);
    }
  else
    wait(&rtrn);
  return (rtrn);
}

int		concatenate(char **line, const int place, t_env *env)
{
  int		fd;
  int		pid;
  int		rtrn;
  char		*tmp;

  if ((fd = open(line[place + 1], O_CREAT | O_WRONLY | O_APPEND,
                 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (my_putstr(ERR_OPEN_FAIL, 2));
  pid = xfork();
  if (pid == 0)
    {
      dup2(fd, 1);
      tmp = line[place];
      line[place] = NULL;
      exec_line(line, env);
      line[place] = tmp;
      dup2(1, 1);
      close(fd);
      exit(0);
    }
  else
    wait(&rtrn);
  return (rtrn);
}

int		get_redirect(char **line, const int place, t_env *env)
{
  int		i;
  int		rtrn;
  t_command	tabb[] =
    {{"<", &fileredirect},
     {">", &redirect},
     {"2>", &err_redirect},
     {">>", &concatenate},
     {"<<", &double_left},
     {"|", &single_pipe},
     {NULL, NULL}};

  i = 0;
  while (tabb[i].fct != NULL)
    {
      if (my_strcmp(tabb[i].signe, line[place]) == 0)
	{
	  rtrn = tabb[i].fct(line, place, env);
	  return (rtrn);
	}
      i++;
    }
  return (my_putstr(ERR_UNKNOWN_REDIRECT, 2));
}
