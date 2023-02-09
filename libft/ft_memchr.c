/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:17:17 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/09 15:59:25 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	check;
	size_t			i;

	str = (unsigned char *)s;
	check = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == check)
			return (str);
		i++;
		str++;
	}
	return (NULL);
}
