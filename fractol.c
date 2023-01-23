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

int make_offset_color(t_fractal *vars, unsigned int n)
{
    int red, green, blue;
    float hue = (float)n / vars->max_iterations;
    hue = hue * 360;
    hsv_to_rgb(hue, 1.0, 1.0, &red, &green, &blue);
    return (red << 16 | green << 8 | blue);
}
/*int		make_offset_color(t_fractal *vars, unsigned int n)
{
	int red;

	red = 0xFF * ((float)n / (float)vars->max_iterations);
	if(n > 0 && n <= vars->max_iterations / 2 - 1)
	{
		return(red << 1);
	}
	else if(n >= vars->max_iterations / 2 && n <= vars->max_iterations - 1)
	{
		return(red << 16);
	}
	return (0);
}*/

void	my_mlx_pixel_put(t_fractal *vars, unsigned int x, unsigned int y, int color)
{
	char	*dst;

	dst = (vars->img).addr + (y * (vars->img).line_length + x * ((vars->img).bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	initialize_numbers (t_fractal *vars)
{
	vars->grid.minre = -2.0;
	vars->grid.maxre = 1.0;
	vars->grid.minim = -1.2;
	vars->grid.maxim = vars->grid.minim + (vars->grid.maxre - vars->grid.minre) * vars->height/vars->width;
	vars->grid.re_factor = (vars->grid.maxre - vars->grid.minre) / (vars->width - 1);
	vars->grid.im_factor = (vars->grid.maxim - vars->grid.minim) / (vars->height - 1);
	vars->max_iterations = 50;
}

int	mandelbrot_set(t_fractal *vars)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	n;
	int	inside;

	y = 0;
	x = 0;
	n = 0;
	inside = 0;
	while(y < vars->height)
	{
		vars->c_im = vars->grid.maxim - y * vars->grid.im_factor;
		x = 0;
		while(x < vars->width)
		{
			vars->c_re = vars->grid.minre + x * vars->grid.re_factor;
			vars->z_re = vars->c_re;
			vars->z_im = vars->c_im;
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

int	main(void)
{
	t_fractal	vars;

	vars.width = 1000;
	vars.height = 800;
	initialize_numbers(&vars);
	//initialize_julia_set(&vars);
	vars.mlx.mlx_ptr = mlx_init();
	vars.mlx.win_ptr = mlx_new_window(vars.mlx.mlx_ptr, vars.width, vars.height, "Fractol");
	vars.img.img = mlx_new_image(vars.mlx.mlx_ptr, vars.width, vars.height);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, \
	&vars.img.line_length, &vars.img.endian);
	mandelbrot_set(&vars);
	//julia_set(&vars);
	mlx_put_image_to_window(vars.mlx.mlx_ptr, vars.mlx.win_ptr, vars.img.img, 0, 0);
	mlx_hook(vars.mlx.win_ptr, 17, 0, close, &vars);
	mlx_hook(vars.mlx.win_ptr, 4, 0, mouse_scroll, &vars);
	mlx_hook(vars.mlx.win_ptr, 5, 0, mouse_scroll, &vars);
	mlx_key_hook(vars.mlx.win_ptr, key_deal, &vars);
	mlx_loop(vars.mlx.mlx_ptr);
	return (0);
}