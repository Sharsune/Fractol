/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:59:03 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/17 13:31:01 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_fail(char **newstrs)
{
	int	i;

	i = 0;
	while (newstrs[i])
	{
		free (newstrs[i]);
		i++;
	}
	free (newstrs);
	return (0);
}

static char	**newstr_cpy(char const *s, char c, char **newstrs)
{
	int	i;
	int	j;
	int	current;

	i = 0;
	j = 0;
	current = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			newstrs[current][j] = s[i];
			i++;
			j++;
		}
		if (newstrs[current] != NULL)
			newstrs[current][j] = '\0';
		current++;
		j = 0;
	}
	return (newstrs);
}

static char	**word_size(char const *s, char c, int word, char **newstrs)
{
	int	i;
	int	size;
	int	j;

	i = 0;
	size = 0;
	j = 0;
	while (s[i] != '\0' && word > 0)
	{
		if (s[i] == c)
			i++;
		if (s[i++] != c)
		{
			size++;
			if (s[i] == c || s[i] == '\0')
			{
				newstrs[j] = malloc(sizeof(char) * (size + 1));
				if (!newstrs[j++])
					return (malloc_fail(newstrs));
				size = 0;
				word--;
			}
		}
	}
	return (newstrs);
}

static int	word_count(char const *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		if (s[i] != c)
		{
			i++;
			if (s[i] == c || s[i] == '\0')
				word++;
		}
		else if (s[i - 1] == c && s[i] == c)
			i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**newstrs;

	if (!s)
		return (NULL);
	word = word_count(s, c);
	newstrs = malloc(sizeof(char *) * (word + 1));
	if (!newstrs)
		return (NULL);
	newstrs[word] = 0;
	word_size(s, c, word, newstrs);
	newstr_cpy(s, c, newstrs);
	return (newstrs);
}
