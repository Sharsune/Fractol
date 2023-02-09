/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:19:57 by sharsune          #+#    #+#             */
/*   Updated: 2023/01/18 14:19:59 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_mandelbrot(t_fractal *vars)
{
	vars->grid.minre = -2.0;
	vars->grid.maxre = 1.0;
	vars->grid.minim = -1.2;
	vars->grid.maxim = vars->grid.minim + (vars->grid.maxre - vars->grid.minre) \
	* vars->height / vars->width;
	vars->grid.re_factor = (vars->grid.maxre - vars->grid.minre) \
	/ (vars->width - 1);
	vars->grid.im_factor = (vars->grid.maxim - vars->grid.minim) \
	/ (vars->height - 1);
	vars->max_iterations = 50;
	vars->zoom_multiply = 1.0;
}

void	initialize_julia(t_fractal *vars)
{
	vars->grid.minre = -2.0;
	vars->grid.maxre = 2.0;
	vars->grid.minim = -2;
	vars->grid.maxim = 2.0;
	vars->grid.re_factor = (vars->grid.maxre - vars->grid.minre) \
	/ (vars->width - 1);
	vars->grid.im_factor = (vars->grid.maxim - vars->grid.minim) \
	/ (vars->height - 1);
	vars->max_iterations = 50;
	if (vars->argc == 2)
	{
		vars->j_re = -0.835;
		vars->j_im = -0.2321;
	}
	else
	{
		vars->j_re = ft_atof(vars->argv[2]);
		vars->j_im = ft_atof(vars->argv[3]);
	}
	vars->c_im = vars->j_im;
	vars->c_re = vars->j_re;
	vars->zoom_multiply = 1.0;
}

void	inner_loop(t_fractal *vars, unsigned int *n, int *inside)
{
	while (*n < vars->max_iterations)
	{
		vars->z_re2 = vars->z_re * vars->z_re;
		vars->z_im2 = vars->z_im * vars->z_im;
		if (vars->z_re2 + vars->z_im2 > 4)
		{
			*inside = 2;
			break ;
		}
		vars->z_im = 2 * vars->z_re * vars->z_im + vars->c_im;
		vars->z_re = vars->z_re2 - vars->z_im2 + vars->c_re;
		(*n)++;
	}
}

double	ft_atof(const char *str)
{
	double	result;
	double	power;
	int		i;
	int		sign;

	result = 0.0;
	power = 1.0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = 10.0 * result + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	return (after_dot(str, i, sign, result));
}

double	after_dot(const char *str, int i, int sign, int result)
{
	double	power;

	power = 1.0;
	while (ft_isdigit(str[i]))
	{
		result = 10.0 * result + (str[i] - '0');
		power *= 10.0;
		i++;
	}
	return (sign * result / power);
}
