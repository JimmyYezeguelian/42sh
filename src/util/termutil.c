/*
** termutil.c for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Wed Apr  2 11:20:47 2014 Newton Guillaume
** Last update Sun May 25 16:12:30 2014 Newton Guillaume
*/

#include "42sh.h"

int	set_raw_mode(struct termios *termios_p)
{
  termios_p->c_lflag &= ~ICANON;
  termios_p->c_lflag &= ~ECHO;
  termios_p->c_cc[VMIN] = 1;
  termios_p->c_cc[VTIME] = 0;
  if ((tcsetattr(0, 0, termios_p)) == -1)
    {
      my_putstr(ERR_PUT_TERM_INFOS, 2);
      return (-1);
    }
  return (0);
}

int	ini_all(struct termios *termios_p, t_env *env)
{
  char	*str;

  if ((tcgetattr(0, termios_p)) == -1)
    {
      my_putstr(ERR_GET_TERM_INFOS, 2);
      return (-1);
    }
  str = my_getenv("TERM", env);
  if ((tgetent(NULL, str)) <= 0)
    {
      xfree(str);
      my_putstr(ERR_GET_NCURSES_DB, 2);
      return (-1);
    }
  xfree(str);
  return (0);
}

void	putcap(const char *bgn, const char *str,
	       const char *end, const int fd)
{
  my_putstr(bgn, fd);
  my_putstr(str, fd);
  my_putstr(end, fd);
}

