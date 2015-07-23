/*
** struct.h for 42sh in /Users/sicard_f/Github/42sh/inc
**
** Made by Flavien Sicard
** Login   <sicard_f@epitech.net>
**
** Started on  Wed Apr  2 13:52:40 2014 Flavien Sicard
** Last update Sun May 25 14:22:44 2014 Newton Guillaume
*/

#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef	struct	s_line
{
  char		*line;
  char		*tmp;
}		t_line;

typedef struct	s_env
{
  char		*env_name;
  char		*env_value;
  struct s_env	*next;
}		t_env;

typedef	struct	s_command
{
  char		*signe;
  int		(*fct)(char **, const int, t_env *);
}		t_command;

typedef struct  s_wordtab
{
  int           i;
  int           j;
  int           i2;
  char          **tabb;
}               t_wordtab;

typedef	struct	s_epur
{
  int		k;
  int		i;
  int		check;
  char		*com;
  char		*tmp;
}		t_epur;

typedef struct	s_count
{
  int		count;
  int		l;
  int		i;
}		t_count;

typedef struct  s_hist
{
  char          *line;
  struct s_hist *next;
  struct s_hist *prev;
}               t_hist;

typedef struct	s_pipe
{
  int		pid;
  int		rtrn;
  int		pipefd[2];
  char		*tmp;
}		t_pipe;

#endif
