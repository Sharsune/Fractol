/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:55:32 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/18 17:46:50 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	i = 0;
	slen = ft_strlen(src);
	if (!dst && !dstsize)
		return (slen);
	dlen = ft_strlen(dst);
	if (dst && dstsize < dlen + 1)
		return (dstsize + slen);
	if (dstsize > dlen + 1)
	{
		while (src[i] != '\0' && dlen + 1 + i < dstsize)
		{
			dst[dlen + i] = src[i];
			i++;
		}
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
