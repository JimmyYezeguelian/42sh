/*
** builtin_cd.c for builtin in /home/robin/rendu/42sh/src
**
** Made by Robin Maronier
** Login   <maroni_r@epitech.net>
**
** Started on  Fri Apr 25 11:14:18 2014 Robin Maronier
** Last update Sun May 25 14:51:12 2014 Newton Guillaume
*/

#include "42sh.h"

char	*home_tild(char **command, char *str, t_env *env, int i)
{
  int	i2;
  char	*home;

  i2 = 1;
  if ((home = my_getenv("HOME", env)) != NULL)
    {
      str = xmalloc(sizeof(char) * (my_strlen(command[1]) + my_strlen(home)));
      my_bzero(str, my_strlen(command[1] + my_strlen(home)));
      while (home[i] != 0)
	{
	  str[i] = home[i];
	  i++;
	}
      while (command[1][i2 - 1] != 0)
	{
	  str[i] = command[1][i2];
	  i++;
	  i2++;
	}
      xfree(home);
      xfree(command[1]);
      return (str);
    }
  return (NULL);
}

int	move_cd(char **command, t_env *env)
{
  char	*str;
  int	i;

  i = 0;
  str = NULL;
  if (command[1] == NULL && chdir(my_getenv("HOME", env)) == -1)
    return (my_putstr("Can't access at home\n", 2));
  else if (command[1] != NULL)
    {
      if (command[1][0] == '~' && command[1][1] == '/')
	str = home_tild(command, str, env, i);
      else if (command[1][0] == '-')
	{
	  str = xmalloc(sizeof(char) * (my_strlen(my_getenv("OLDPWD", env))));
	  my_strcpy(str, my_getenv("OLDPWD", env));
	}
      else
	str = command[1];
      if (chdir(str) == -1)
	return (my_putstr("Can't access to this folder\n", 2));
    }
  return (0);
}

void	write_oldpwd(t_env *pwd, t_env *tmp, t_env *tmp2)
{
  char	*str;
  t_env	*oldpwd;

  if (tmp == NULL)
    {
      tmp2->next = xmalloc(sizeof(t_env));
      tmp2 = tmp2->next;
      tmp = tmp2;
      tmp->next = NULL;
    }
  oldpwd = tmp;
  str = xmalloc(sizeof(char) * 200);
  oldpwd->env_name = xmalloc(sizeof(char) * (my_strlen("OLDPWD")));
  my_strcpy(oldpwd->env_name, "OLDPWD");
  oldpwd->env_value = xmalloc(sizeof(char) * my_strlen(pwd->env_value));
  my_strcpy(oldpwd->env_value, pwd->env_value);
  xfree(pwd->env_value);
  str = getcwd(str, 200);
  pwd->env_value = xmalloc(sizeof(char) * my_strlen(str));
  my_strcpy(pwd->env_value, str);
  xfree(str);
}

void	change_env(t_env *env, t_env *tmp, t_env *pwd, t_env *tmp2)
{
  while (tmp != NULL && my_strcmp(tmp->env_name, "PWD") != 0)
    {
      tmp2 = tmp;
      tmp = tmp->next;
    }
  if (tmp == NULL)
    {
      tmp2->next = xmalloc(sizeof(t_env));
      tmp = tmp2;
      tmp->next = NULL;
      tmp->env_name = xmalloc(sizeof(char) * my_strlen("PWD"));
      my_strcpy(tmp->env_name, "PWD");
      tmp->env_value = NULL;
    }
  pwd = tmp;
  tmp = env;
  while (tmp != NULL && my_strcmp(tmp->env_name, "OLDPWD") != 0)
    {
      tmp2 = tmp;
      tmp = tmp->next;
    }
  write_oldpwd(pwd, tmp, tmp2);
}

int	my_cd(char **command, t_env *env)
{
  t_env	*pwd;
  t_env	*tmp;
  t_env	*tmp2;

  tmp = env;
  tmp2 = NULL;
  pwd = NULL;
  if (move_cd(command, env) == -1)
    return (1);
  change_env(env, tmp, pwd, tmp2);
  return (0);
}
