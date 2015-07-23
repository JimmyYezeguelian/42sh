/*
** signals.c for 42sh in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Fri May  9 13:03:38 2014 Robin Maronier
** Last update Sun May 25 18:17:42 2014 Robin Maronier
*/

#include "42sh.h"

void	caught_signal_main(int sig)
{
  if (sig == SIGINT)
    {
      my_putstr("^C\n", 2);
      aff_prompt(NULL, 0);
    }
}

void	caught_signal(int sig)
{
  if (sig == 11)
    kill(getpid(), SIGKILL);
}

int	my_signal()
{
  if (signal(SIGINT, caught_signal_main) == SIG_ERR)
    return (my_putstr("ERROR: signal error !\n", 2));
  return (0);
}
