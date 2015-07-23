/*
** verif.c for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Tue May  6 08:02:51 2014 Newton Guillaume
** Last update Sun May 25 16:10:49 2014 Newton Guillaume
*/

#include "42sh.h"

int	xfork()
{
  int	pid;

  pid = fork();
  if (pid == -1)
    return (my_putstr(ERR_FORK_FAIL, 2));
  return (pid);
}

void	*xmalloc(const int size)
{
  void	*var;

  var = malloc(size + 100);
  if (var == NULL)
    {
      my_putstr(ERR_MALLOC, 2);
      return (NULL);
    }
  return (var);
}

void	xfree(void *var)
{
  if (var != NULL)
    free(var);
}
