/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:49:25 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/14 14:30:40 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	int		i;

	len = ft_strlen(s);
	i = len;
	while (len > 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
		len --;
	}
	if (s[0] == (char)c)
		return ((char *)(s + i));
	return (0);
}
