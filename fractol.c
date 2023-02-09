/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:29:50 by sharsune          #+#    #+#             */
/*   Updated: 2023/01/10 18:29:52 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	make_colors(unsigned char *colors, int inside, unsigned int n)
{
	if (inside == 1)
	{
		colors[0] = (unsigned char)0;
		colors[1] = (unsigned char)0;
		colors[2] = (unsigned char)0;
		colors[3] = (unsigned char)0;
	}
	else if (inside == 2)
	{
		colors[0] = (unsigned char)n * 500;
		colors[1] = (unsigned char)n * 500;
		colors[2] = (unsigned char)n * 520;
		colors[3] = (unsigned char)sin(n) * 1000;
	}
}

void	my_mlx_pixel_put(t_fractal *vars, unsigned int x, \
unsigned int y, int *color)
{
	char	*dst;

	dst = (vars->img).addr + (y * (vars->img).line_length + \
	x * ((vars->img).bits_per_pixel / 8));
	*(unsigned int *)dst = *color;
}

void	julia_set(t_fractal *vars)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	n;
	int				inside;
	unsigned char	colors[4];

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			vars->z_re = vars->grid.minre + x * vars->grid.re_factor;
			vars->z_im = vars->grid.maxim - y * vars->grid.im_factor;
			inside = 1;
			n = 0;
			inner_loop(vars, &n, &inside);
			make_colors(colors, inside, n);
			my_mlx_pixel_put(vars, x, y, (int *)colors);
			x++;
		}
		y++;
	}
}

void	mandelbrot_set(t_fractal *vars)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	n;
	int				inside;
	unsigned char	colors[4];

	y = 0;
	while (y < vars->height)
	{
		vars->c_im = vars->grid.maxim - y * vars->grid.im_factor;
		x = 0;
		while (x < vars->width)
		{
			vars->c_re = vars->grid.minre + x * vars->grid.re_factor;
			vars->z_re = vars->c_re;
			vars->z_im = vars->c_im;
			inside = 1;
			n = 0;
			inner_loop(vars, &n, &inside);
			make_colors(colors, inside, n);
			my_mlx_pixel_put(vars, x, y, (int *)colors);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_fractal	vars;

	vars.argv = argv;
	vars.argc = argc;
	check_argv(&vars);
	mlx_put_image_to_window(vars.mlx.mlx_ptr, \
	vars.mlx.win_ptr, vars.img.img, 0, 0);
	mlx_hook(vars.mlx.win_ptr, 4, 0, mouse_scroll, (void *)&vars);
	mlx_hook(vars.mlx.win_ptr, 5, 0, mouse_scroll, (void *)&vars);
	mlx_hook(vars.mlx.win_ptr, 17, 0, close_window, (void *)&vars);
	mlx_key_hook(vars.mlx.win_ptr, key_deal, (void *)&vars);
	mlx_loop(vars.mlx.mlx_ptr);
	return (0);
}
