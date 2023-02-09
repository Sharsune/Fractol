/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:43:44 by sharsune          #+#    #+#             */
/*   Updated: 2022/11/01 15:53:32 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	c;
	int	totalnumber;
	int	negative;

	c = 0;
	totalnumber = 0;
	negative = 1;
	while ((str[c] >= 9 && str[c] <= 13) || (str[c] == 32))
		c++;
	if (str[c] == '-')
		negative = negative * -1;
	if ((str[c] == '-') || (str[c] == '+'))
		c++;
	while ((str[c] != '\0') && (str[c] >= '0' && str[c] <= '9'))
	{
		totalnumber = totalnumber * 10 + str[c] - '0';
		c++;
	}
	return (totalnumber = totalnumber * negative);
}
