/*
** alias.c for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Tue May  6 14:58:09 2014 Newton Guillaume
** Last update Wed May 21 17:05:34 2014 Robin Maronier
*/

#include "42sh.h"

char	*get_aliasname(char *line, int *place)
{
  char	*name;

  while (line[*place] && line[*place] != '=')
    {
      if (line[*place] == '\0')
	return (NULL);
      *place += 1;
    }
  name = xmalloc(sizeof(char) * (*place + 1));
  line[*place] = '\0';
  my_strcpy(name, line);
  line[*place] = '=';
  return (name);
}

t_env	*get_alias(char *line)
{
  int	place;
  char	*name;
  t_env	*elem;

  place = 0;
  elem = xmalloc(sizeof(t_env));
  elem->next = NULL;
  name = get_aliasname(&line[6], &place);
  elem->env_name = xmalloc(sizeof(char) * (my_strlen(name) + 1));
  my_strcpy(elem->env_name, name);
  xfree(name);
  elem->env_value = xmalloc(sizeof(char) * (my_strlen(&line[6 + place]) + 1));
  my_strcpy(elem->env_value, &line[6 + place]);
  return (elem);
}

int	test_config(char *read, t_env *elem, t_env *env)
{
  char	*line;
  char	**tabb;

  (void)env;
  line = epur_str(read);
  tabb = my_str_to_wordtab(line, ' ');
  if (my_strcmp(tabb[0], "alias") == 0)
    {
      elem->next = get_alias(line);
      elem = elem->next;
    }
  if (elem->next == NULL)
    return (-1);
  return (0);
}

/* else if (my_strcmp(tabb[0], "export") == 0) */
/*   get_export(line, env); */
t_env	*get_config(t_env *env)
{
  int	fd;
  char	*line;
  t_env	*bgn;
  t_env	*elem;

  if ((fd = open(".42shrc", O_RDONLY, 00644)) == -1)
    {
      my_putstr(ERR_OPEN_FAIL, 2);
      return (NULL);
    }
  bgn = xmalloc(sizeof(t_env));
  bgn->env_name = NULL;
  bgn->env_value = NULL;
  bgn->next = NULL;
  elem = bgn;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (test_config(line, elem, env) == -1)
	return (NULL);
    }
  return (bgn);
}
