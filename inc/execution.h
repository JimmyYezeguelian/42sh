/*
** execution.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Thu May 22 09:32:59 2014 Newton Guillaume
** Last update Sat May 24 11:58:13 2014 Yezeguelian Jimmy
*/

#ifndef	_EXECUTION_H_
#define	_EXECUTION_H_

/* LIST_BUILTIN.C */
int	check_builtin(char **tabb, t_env *env);

/* EXEC_LINE.C */
int	exec_line(char **tabb, t_env *env);
void	get_mult_exec(char **tabb, t_env *env);

/* EXEC_LINE_NEXT.C */
void	execution(char **tabb, t_env *chaine_env);

/* SETUP_EXEC.C */
char	*my_complete_str(char *path, char *strstr);

#endif
