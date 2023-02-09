/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:12:03 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/17 12:50:14 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*machine(char *str, int n)
{
	int	is_negative;
	int	j;

	is_negative = 0;
	j = 0;
	if (n == 0)
		str[j++] = '0';
	if (n < 0)
		is_negative = 1;
	while (n && is_negative)
	{
		str[j++] = n % 10 * (-1) + '0';
		n /= 10;
	}
	while (n)
	{
		str[j++] = n % 10 + '0';
		n /= 10;
	}
	if (is_negative)
		str[j++] = '-';
	str[j] = '\0';
	return (str);
}

static int	count_size(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*reverse(char *str)
{
	int		len;
	int		start;
	char	temp;

	start = -1;
	len = ft_strlen(str);
	while (++start < --len)
	{
		temp = str[start];
		str[start] = str[len];
		str[len] = temp;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (count_size(n) + 1));
	if (!str)
		return (NULL);
	machine(str, n);
	reverse (str);
	return (str);
}
