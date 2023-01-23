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

int	mouse_scroll(int keycode, int x, int y, t_fractal *vars)
{
    initialize_zoom(vars, x, y);
	if(keycode == 4)
	{
        vars->grid.minre = vars->zoom.x_c - (vars->zoom.x_c - vars->grid.minre) * 0.9;
		vars->grid.maxre = vars->zoom.x_c + (vars->grid.maxre - vars->zoom.x_c) * 0.9;
		vars->grid.minim = vars->zoom.y_c - (vars->zoom.y_c - vars->grid.minim) * 0.9;
		vars->grid.maxim = vars->zoom.y_c + (vars->grid.maxim - vars->zoom.y_c) * 0.9;
	}
	if(keycode == 5)
	{
        vars->grid.minre = vars->zoom.x_c - (vars->zoom.x_c - vars->grid.minre) / 0.9;
		vars->grid.maxre = vars->zoom.x_c + (vars->grid.maxre - vars->zoom.x_c) / 0.9;
		vars->grid.minim = vars->zoom.y_c - (vars->zoom.y_c - vars->grid.minim) / 0.9;
		vars->grid.maxim = vars->zoom.y_c + (vars->grid.maxim - vars->zoom.y_c) / 0.9;
	}
    vars->grid.re_factor = (vars->grid.maxre - vars->grid.minre) / (vars->width - 1);
	vars->grid.im_factor = (vars->grid.maxim - vars->grid.minim) / (vars->height - 1);
    mandelbrot_set(vars);
    //julia_set(vars);
    mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win_ptr, vars->img.img, 0, 0);
	return (0);
}

int	close(void *param)
{
	t_fractal *vars = (t_fractal *)param;
	mlx_destroy_image(vars->mlx.mlx_ptr, vars->img.img);
	mlx_destroy_window(vars->mlx.mlx_ptr, vars->mlx.win_ptr);
	exit (0);
}

int	key_deal(int keycode, void *param)
{
	t_fractal *vars = (t_fractal *)param;
	if(keycode == 53)
		close(vars);
    if(keycode == 126)
        move_up(vars);
    if(keycode == 125)
        move_down(vars);
    if(keycode == 124)
        move_right(vars);
    if(keycode == 123)
        move_left(vars);
	return (0);
}

void hsv_to_rgb(double h, double s, double v, int* r, int* g, int* b)
{
	double H = h, S = s, V = v,
            P, Q, T,
            fract;

    (H == 360.)?(H = 0.):(H /= 60.);
    fract = H - floor(H);

    P = V*(1. - S);
    Q = V*(1. - S*fract);
    T = V*(1. - S*(1. - fract));

    if      (0. <= H && H < 1.)
    {
        *r = V * 255;
        *g = T * 255;
        *b = P * 255;
    }
    else if (1. <= H && H < 2.)
    {
        *r = Q * 255;
        *g = V * 255;
        *b = P * 255;
    }
    else if (2. <= H && H < 3.)
    {
        *r = P * 255;
        *g = V * 255;
        *b = T * 255;
    }
    else if (3. <= H && H < 4.)
    {
        *r = P * 255;
        *g = Q * 255;
        *b = V * 255;
    }
    else if (4. <= H && H < 5.)
    {
        *r = T * 255;
        *g = P * 255;
        *b = V * 255;
    }
    else if (5. <= H && H < 6.)
    {
        *r = V * 255;
        *g = P * 255;
        *b = Q * 255;
    }
    else
    {
        *r = 0;
        *g = 0;
        *b = 0;
    }
}