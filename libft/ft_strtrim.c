/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:00:59 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/17 13:30:20 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*newstr(char const *s1, size_t len, int start, int end)
{
	char	*newstr;
	int		c;

	newstr = malloc(sizeof (char) * (len + 1));
	if (!newstr)
		return (0);
	c = 0;
	while (start <= end)
	{
		newstr[c] = s1[start];
		start++;
		c++;
	}
	newstr[c] = '\0';
	return (newstr);
}

static int	end_str(char const *s1)
{
	int	end;

	end = 0;
	while (s1[end] != '\0')
		end++;
	return (end - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	end = end_str(s1);
	i = 0;
	while (ft_strchr(set, s1[start]) && start < (end + 1))
		start++;
	i = 0;
	while (ft_strchr(set, s1[end]) && start < (end + 1))
	{	
		end--;
		i++;
	}
	len = len - start - i;
	return (newstr(s1, len, start, end));
}
