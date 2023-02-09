/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:30:53 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/14 18:50:20 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (dstsize <= 0)
		return (slen);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize -1))
		{
			if (i == dstsize)
				break ;
			dst[i] = src[i];
			i++;
		}
	}	
	dst[i] = '\0';
	return (slen);
}
