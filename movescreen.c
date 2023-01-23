/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movescreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:21:15 by sharsune          #+#    #+#             */
/*   Updated: 2023/01/23 12:21:16 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int move_right(void *param)
{
    t_fractal *vars = (t_fractal *)param;
	vars->grid.minre += 0.05;
	vars->grid.maxre += 0.05;
	mandelbrot_set(vars);
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win_ptr, vars->img.img, 0, 0);
	return (0);
}

int	move_left(void *param)
{
	t_fractal *vars = (t_fractal *)param;
	vars->grid.minre -= 0.05;
	vars->grid.maxre -= 0.05;
	mandelbrot_set(vars);
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win_ptr, vars->img.img, 0, 0);
	return (0);
}

int	move_up(void *param)
{
	t_fractal *vars = (t_fractal *)param;
	vars->grid.minim += 0.05;
	vars->grid.maxim += 0.05;
	mandelbrot_set(vars);
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win_ptr, vars->img.img, 0, 0);
	return (0);
}

int	move_down(void *param)
{
	t_fractal *vars = (t_fractal *)param;
	vars->grid.minim -= 0.05;
	vars->grid.maxim -= 0.05;
	mandelbrot_set(vars);
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win_ptr, vars->img.img, 0, 0);
	return (0);
}