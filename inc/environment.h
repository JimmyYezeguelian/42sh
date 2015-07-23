/*
** environment.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Thu May 22 09:25:21 2014 Newton Guillaume
** Last update Fri May 23 07:09:35 2014 Newton Guillaume
*/

#ifndef	_ENVIRONMENT_H_
#define	_ENVIRONMENT_H_

/* TAB_ENV.C */
char	**tab_env(t_env *env);

/*  */
t_env	*fill_list_env(char **env);
char	*my_getenv(char *str, t_env *env);

#endif
