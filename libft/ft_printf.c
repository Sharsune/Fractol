/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:12:25 by sharsune          #+#    #+#             */
/*   Updated: 2023/01/11 18:12:28 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counting_putchar(int c, int fd)
{
	return (write(fd, &c, 1));
}

int	printstr_fd(char *str, int fd)
{
	int	i;
	int	print_result;

	i = 0;
	print_result = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		print_result += counting_putchar(str[i], fd);
		i++;
	}
	return (print_result);
}

int	printnbr_fd(int nb, int fd)
{
	long	temp;
	int		print_result;

	temp = nb;
	print_result = 0;
	if (nb < 0)
	{
		temp = -temp;
		print_result += counting_putchar('-', fd);
	}
	if (temp > 9)
	{
		print_result += printnbr_fd(temp / 10, fd);
		print_result += printnbr_fd(temp % 10, fd);
	}
	else
		print_result += counting_putchar(temp + '0', fd);
	return (print_result);
}

static int	check_format(va_list args, const char str)
{	
	int	print_result;

	print_result = 0;
	if (str == 'c')
		print_result += counting_putchar(va_arg(args, int), 1);
	else if (str == 's')
		print_result += printstr_fd(va_arg(args, char *), 1);
	else if (str == 'p')
	{
		print_result += write(1, "0x", 2);
		print_result += ft_print_pointer_fd(\
		va_arg(args, unsigned long long), 1);
	}
	else if (str == 'd' || str == 'i')
		print_result += printnbr_fd(va_arg(args, int), 1);
	else if (str == 'u')
		print_result += ft_print_unsigned_fd(va_arg(args, unsigned int), 1);
	else if (str == 'x' || str == 'X')
		print_result += ft_print_hex_fd(va_arg(args, unsigned int), &str, 1);
	else if (str == '%')
		print_result += write(1, &str, 1);
	return (print_result);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_result;
	int		i;

	print_result = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{	
			i++;
			print_result += check_format(args, str[i]);
			i++;
		}
		else
		{	
			print_result += write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (print_result);
}
