/*
** str_to_wordtab.c for rt in /home/guillaume/Coding/Raytracer
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Sun May 11 13:18:13 2014 Newton Guillaume
** Last update Sun May 25 16:16:31 2014 Newton Guillaume
*/

#include "42sh.h"

int	get_words_nbr(const char *str, const char sep)
{
  int	i;
  int	_bool;
  int	nb_word;

  i = 0;
  _bool = 1;
  nb_word = 0;
  while (str[i])
    {
      if (_bool == 1 && str[i] != sep)
	{
	  nb_word++;
	  _bool = 0;
	}
      else if (str[i] == sep)
	_bool = 1;
      i++;
    }
  return (nb_word);
}

int	get_size_word(const char *str, const char sep)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != sep)
    i++;
  return (i);
}

int	new_word(char **wordtab, const char *str, const int j, const char sep)
{
  int	word_size;

  word_size = get_size_word(str, sep);
  wordtab[j] = xmalloc(sizeof(char) * (word_size + 1));
  my_bzero(wordtab[j], word_size + 1);
  my_strncpy(wordtab[j], str, word_size);
  return (0);
}

char	**my_str_to_wordtab(const char *str, const char sep)
{
  int	i;
  int	j;
  int	_bool;
  int	nb_word;
  char	**wordtab;

  nb_word = get_words_nbr(str, sep);
  wordtab = xmalloc(sizeof(char *) * (nb_word + 1));
  i = -1;
  j = -1;
  _bool = 1;
  while (str[++i])
    {
      if (_bool == 1 && str[i] != sep)
	_bool = new_word(wordtab, &str[i], ++j, sep);
      else if (str[i] == sep)
	_bool = 1;
    }
  wordtab[++j] = NULL;
  return (wordtab);
}
