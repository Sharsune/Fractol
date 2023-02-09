/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:38:10 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/15 15:03:42 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (len == 0 && *needle == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (*needle && nlen != 0)
	{
		while (*haystack != 0 && len > 0)
		{
			if (!ft_strncmp(haystack, needle, nlen) && nlen <= len)
				return ((char *)haystack);
			haystack++;
			len--;
		}
		return (0);
	}
	return ((char *)haystack);
}
