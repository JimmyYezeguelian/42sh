/*
** 42sh.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Wed Apr  2 09:52:46 2014 Newton Guillaume
** Last update Sun May 25 15:23:40 2014 Newton Guillaume
*/

#ifndef		_42SH_H_
#define		_42SH_H_

#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<termios.h>
#include	<term.h>
#include	<sys/wait.h>
#include	<termcap.h>
#include	<curses.h>
#include	<string.h>
#include	"struct.h"
#include	"strutil.h"
#include	"defines.h"
#include	"verif.h"
#include	"str_to_wordtab.h"
#include	"environment.h"
#include	"epur_str.h"
#include	"history.h"
#include	"execution.h"
#include	"conditions.h"
#include	"signals.h"
#include	"termutil.h"
#include	"get_next_line.h"
#include	"redirect.h"
#include	"builtin.h"
#include	"my_man.h"

void		aff_prompt(t_env *env, int add);
void		my_putnbr(int nbr);
char		*now_path(t_env *env);
void		aff_ascii(const int fd);
void		set_full_line(char *line, char *tmp);
void		freetab(char **tabb);
void		free_list(t_env *env);
void            after_clean_str(char *line, char **tabb,
				t_env *env, char *tmp);
void		sh(const int fd, t_env *env);

#endif
