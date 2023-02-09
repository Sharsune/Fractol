/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:52:23 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/04 18:56:47 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		c;
	char	*newstr;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = -1;
	c = 0;
	newstr = malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (0);
	while (s1[++i] != '\0')
		newstr[i] = s1[i];
	while (s2[c] != '\0')
		newstr[i++] = s2[c++];
	newstr[i] = '\0';
	return (newstr);
}
