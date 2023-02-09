/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:12:02 by sharsune          #+#    #+#             */
/*   Updated: 2023/01/11 18:12:05 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer_fd(unsigned long long nb, int fd)
{
	int	print_result;

	print_result = 0;
	if (nb >= 16)
	{
		print_result += ft_print_pointer_fd(nb / 16, fd);
		print_result += ft_print_pointer_fd(nb % 16, fd);
	}
	else
	{
		if (nb <= 9)
			print_result += counting_putchar(nb + '0', fd);
		if (nb >= 10 && nb <= 15)
			print_result += counting_putchar(nb + 87, fd);
	}
	return (print_result);
}

int	ft_print_hex_fd(unsigned int nb, const char *str, int fd)
{
	int	print_result;

	print_result = 0;
	if (nb >= 16)
	{
		print_result += ft_print_hex_fd(nb / 16, str, fd);
		print_result += ft_print_hex_fd(nb % 16, str, fd);
	}
	else
	{
		if (nb <= 9)
			print_result += counting_putchar(nb + '0', fd);
		if (nb >= 10 && nb <= 15)
		{	
			if (*str == 'x')
			print_result += counting_putchar(nb + 87, fd);
			if (*str == 'X')
			print_result += counting_putchar(nb + 55, fd);
		}
	}
	return (print_result);
}

int	ft_print_unsigned_fd(unsigned int nb, int fd)
{
	long	temp;
	int		print_result;

	temp = nb;
	print_result = 0;
	if (temp > 9)
	{
		print_result += ft_print_unsigned_fd(temp / 10, fd);
		print_result += ft_print_unsigned_fd(temp % 10, fd);
	}
	else
		print_result += counting_putchar(temp + '0', fd);
	return (print_result);
}
