/*
** epur_str.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Thu May 22 09:26:53 2014 Newton Guillaume
** Last update Sun May 25 17:56:19 2014 Yezeguelian Jimmy
*/

#ifndef	_EPUR_STR_H_
#define	_EPUR_STR_H_

/* EPUR_STR.C */
char	*epur_str(char *str);

/* EPUR_STR_NEXT.C */
int	check_double(char *str, t_epur *e, int l);

/*  EPUR_STR_SIZE.C */
char	*first_epur(char *str);
int	count_size(char *str, t_epur *e);

/* EPUR_STR_ERROR.C */
int	error_token(char *str, t_epur *e, int l);
int	check_tab_error(char **com);
char	*check_end(char *str, t_epur *e);
int	check_start(char *str);
int	epur_end(char *str);

#endif
