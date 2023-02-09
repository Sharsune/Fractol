/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:39:53 by sharsune          #+#    #+#             */
/*   Updated: 2023/01/30 15:39:56 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_argv(t_fractal *vars)
{
	if (vars->argc == 1)
		error_exit();
	if (ft_strcmp(vars->argv[1], "julia") == 0)
	{
		if (vars->argc == 3 || vars->argc > 4)
			error_exit();
		if (vars->argc > 2)
		{
			check_digits(vars->argv[2]);
			check_digits(vars->argv[3]);
		}
		start_mlx(vars);
		initialize_julia(vars);
		julia_set(vars);
	}
	else if (vars->argc != 2)
		error_exit();
	else if (ft_strcmp(vars->argv[1], "mandelbrot") == 0)
	{
		start_mlx(vars);
		initialize_mandelbrot(vars);
		mandelbrot_set(vars);
	}
	else
		error_exit();
}

void	check_digits(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	i++;
	if (str[i] == '2')
	{
		if (str[i + 1] != '\0')
			error_exit();
		return ;
	}
	if (str[i] != '0' && str[i] != '1')
		error_exit();
	if (str[++i] == '\0')
		return ;
	if (str[i++] != '.')
		error_exit();
	while (str[i] != '\0')
		if (!ft_isdigit(str[i++]))
			error_exit();
}

void	error_exit(void)
{
	ft_printf("%s\n", "Available fractals: mandelbrot, julia");
	exit(0);
}
