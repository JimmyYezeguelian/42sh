/*
** aff_prompt.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Yezeguelian Jimmy
** Login   <yezegu_j@epitech.net>
**
** Started on  Sat May 24 11:09:09 2014 Yezeguelian Jimmy
** Last update Sun May 25 19:27:12 2014 Yezeguelian Jimmy
*/

#include "42sh.h"

void		aff_prompt(t_env *env, int add)
{
  static int	i = 0;
  static char	*str = NULL;
  static char	*now = NULL;

  i = i + add;
  if (env != NULL)
    {
      xfree(now);
      xfree(str);
      str = my_getenv("LOGNAME", env);
      now = now_path(env);
    }
  my_putstr("\e[36m42sh\e[0;1m@\e[1;91m", 1);
  my_putstr(str, 1);
  my_putstr("\e[0m:\e[32m", 1);
  my_putstr(now, 1);
  my_putstr("\e[0m", 1);
  my_putstr(" (\e[33m", 1);
  my_putnbr(i);
  my_putstr("\e[0m)> ", 1);
}

void		aff_ascii(const int fd)
{
  my_putstr("\033c", 1);
  my_putstr(ASCII_1, 1);
  my_putstr(ASCII_2, 1);
  my_putstr(ASCII_3, 1);
  my_putstr(ASCII_4, 1);
  my_putstr(ASCII_5, 1);
  my_putstr(ASCII_6, 1);
  my_putstr(WELCOME_MSG, fd);
}
