/*
** get_special_char_next.c for 42sh in /home/jimmy/rendu/42sh
**
** Made by Yezeguelian Jimmy
** Login   <yezegu_j@epitech.net>
**
** Started on  Sat May 24 12:02:18 2014 Yezeguelian Jimmy
** Last update Sat May 24 12:05:00 2014 Yezeguelian Jimmy
*/

#include "42sh.h"

void	get_backspace(char *line, const int fd)
{
  my_putchar('\b', fd);
  write(fd, tgetstr("dc", NULL), my_strlen(tgetstr("dc", NULL)));
  line[strlen(line) - 1] = '\0';
}
