/*
** main.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Yezeguelian Jimmy
** Login   <yezegu_j@epitech.net>
**
** Started on  Sat May 24 12:13:04 2014 Yezeguelian Jimmy
** Last update Sun May 25 18:23:02 2014 Robin Maronier
*/

#include "42sh.h"

int			main(int ac, char **av, char **env)
{
  int                   fd;
  t_env                 *new_env;
  struct termios        termios_p;
  struct termios        termios_ini;

  (void)ac;
  (void)av;
  if (my_signal() == -1)
    return (-1);
  if ((fd = open("/dev/tty", O_NOCTTY | O_RDWR)) == -1)
    return (my_putstr(ERR_OPEN_FAIL, 2));
  new_env = NULL;
  if (ini_all(&termios_ini, new_env) == -1)
    return (-1);
  termios_p = termios_ini;
  set_raw_mode(&termios_p);
  new_env = fill_list_env(env);
  history(NULL, '\0', 'c');
  sh(fd, new_env);
  if ((tcsetattr(0, 0, &termios_ini)) == 1)
    return (my_putstr(ERR_PUT_TERM_INFOS, 2));
  close(fd);
  return (0);
}
