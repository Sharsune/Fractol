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

void	initialize_zoom(t_fractal *vars, int x, int y)
{
	vars->zoom.x_factor = (vars->grid.maxre - vars->grid.minre) / (vars->width - 1);
	vars->zoom.y_factor = (vars->grid.maxim - vars->grid.minim) / (vars->height - 1);
	vars->zoom.x_c = vars->grid.minre + vars->width * vars->zoom.x_factor;
	vars->zoom.y_c = vars->grid.maxim - vars->height * vars->zoom.y_factor;
	vars->zoom.x_c = vars->grid.minre + x * vars->zoom.x_factor;
	vars->zoom.y_c = vars->grid.maxim - y * vars->zoom.y_factor;
}

void	initialize_julia_set(t_fractal *vars)
{
	vars->grid.minre = -2.0;
	vars->grid.maxre = 2.0;
	vars->grid.minim = -2;
	vars->grid.maxim = 2.0;
	vars->grid.re_factor = (vars->grid.maxre - vars->grid.minre) / (vars->width - 1);
	vars->grid.im_factor = (vars->grid.maxim - vars->grid.minim) / (vars->height - 1);
	vars->max_iterations = 50;
	vars->j_re = -0.835;
	vars->j_im = -0.2321;
	vars->c_im = vars->j_im;
	vars->c_re = vars->j_re;
}

int	julia_set(t_fractal *vars)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	n;
	int	inside;

	y = 0;
	x = 0;
	n = 0;
	inside = 0;
	//initialize_julia_set(vars);
	while(y < vars->height)
	{
		x = 0;
		while(x < vars->width)
		{
			vars->z_re = vars->grid.minre + x * vars->grid.re_factor;
			vars->z_im = vars->grid.maxim - y * vars->grid.im_factor;
			inside = 1;
			n = 0;
			while(n < vars->max_iterations)
			{
				vars->z_re2 = vars->z_re * vars->z_re;
				vars->z_im2 = vars->z_im * vars->z_im;
				if (vars->z_re2 + vars->z_im2 > 4)
				{
					inside = 2;
					break;
				}
				vars->z_im = 2 * vars->z_re * vars->z_im + vars->c_im;
				vars->z_re = vars->z_re2 - vars->z_im2 + vars->c_re;
				n++;
			}
			if(inside == 1)
				my_mlx_pixel_put(vars, x, y, 0x00000000);
			if(inside == 2)
				my_mlx_pixel_put(vars, x, y, make_offset_color(vars, n));
			x++;
		}
		y++;
	}
	return (0);
}
