/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:50:01 by sharsune          #+#    #+#             */
/*   Updated: 2023/01/17 18:50:03 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	start_mlx(t_fractal *vars)
{
	vars->width = 1000;
	vars->height = 800;
	vars->mlx.mlx_ptr = mlx_init();
	vars->mlx.win_ptr = mlx_new_window(vars->mlx.mlx_ptr, vars->width, \
	vars->height, "Fractol");
	vars->img.img = mlx_new_image(vars->mlx.mlx_ptr, vars->width, vars->height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
	&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
}

int	mouse_scroll(int keycode, int x, int y, void *param)
{
	t_fractal	*vars;

	vars = (t_fractal *)param;
	initialize_zoom(vars, x, y);
	if (keycode == 4)
		zoom_in(vars);
	if (keycode == 5)
		zoom_out(vars);
	vars->grid.re_factor = (vars->grid.maxre - vars->grid.minre) \
	/ (vars->width - 1);
	vars->grid.im_factor = (vars->grid.maxim - vars->grid.minim) \
	/ (vars->height - 1);
	if (ft_strncmp(vars->argv[1], "mandelbrot", 10) == 0)
	{
		mandelbrot_set(vars);
		mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win_ptr, \
		vars->img.img, 0, 0);
	}
	else if (ft_strncmp(vars->argv[1], "julia", 5) == 0)
	{
		julia_set(vars);
		mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win_ptr, \
		vars->img.img, 0, 0);
	}
	return (0);
}

int	close_window(void *param)
{
	t_fractal	*vars;

	vars = (t_fractal *)param;
	mlx_destroy_image(vars->mlx.mlx_ptr, vars->img.img);
	mlx_destroy_window(vars->mlx.mlx_ptr, vars->mlx.win_ptr);
	exit (0);
}

int	key_deal(int keycode, void *param)
{
	t_fractal	*vars;

	vars = (t_fractal *)param;
	if (keycode == ESC)
		close_window(vars);
	if (keycode == UP)
		move_up(vars);
	if (keycode == DOWN)
		move_down(vars);
	if (keycode == RIGHT)
		move_right(vars);
	if (keycode == LEFT)
		move_left(vars);
	return (0);
}
