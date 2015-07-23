/*
** builtin.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Fri May 23 07:18:48 2014 Newton Guillaume
** Last update Sun May 25 13:06:48 2014 Robin Maronier
*/

#ifndef	_BUILTIN_H_
#define	_BUILTIN_H_

/* ECHO.C */
int	my_echo(char **av, t_env *env);
int	write_var_env(char *str, int i, t_env *env);
void	my_put_echo(char *str, t_env *env);

/* ECHO_NEXT.C */
int	test_opt(char **av, char *tabb, int y, int i);

/* BUILTIN_CD.C */
int	my_cd(char **command, t_env *env);

/* BUILTIN_ENV.C */
int	my_setenv(t_env *env, char **tabb);
int	my_env(t_env *env);

/* UNSETENV.C */
int	my_unsetenv(t_env *chain_env, char **str);

#endif
