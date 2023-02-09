/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:52 by sharsune          #+#    #+#             */
/*   Updated: 2023/01/24 12:41:54 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_zoom(t_fractal *vars, int x, int y)
{
	vars->zoom.x_factor = (vars->grid.maxre - vars->grid.minre) \
	/ (vars->width - 1);
	vars->zoom.y_factor = (vars->grid.maxim - vars->grid.minim) \
	/ (vars->height - 1);
	vars->zoom.x_c = vars->grid.minre + vars->width * vars->zoom.x_factor;
	vars->zoom.y_c = vars->grid.maxim - vars->height * vars->zoom.y_factor;
	vars->zoom.x_c = vars->grid.minre + x * vars->zoom.x_factor;
	vars->zoom.y_c = vars->grid.maxim - y * vars->zoom.y_factor;
}

void	zoom_in(t_fractal *vars)
{
	vars->grid.minre = vars->zoom.x_c - \
	(vars->zoom.x_c - vars->grid.minre) * 0.9;
	vars->grid.maxre = vars->zoom.x_c + \
	(vars->grid.maxre - vars->zoom.x_c) * 0.9;
	vars->grid.minim = vars->zoom.y_c - \
	(vars->zoom.y_c - vars->grid.minim) * 0.9;
	vars->grid.maxim = vars->zoom.y_c + \
	(vars->grid.maxim - vars->zoom.y_c) * 0.9;
	vars->zoom_multiply *= 1.1;
}

void	zoom_out(t_fractal *vars)
{
	vars->grid.minre = vars->zoom.x_c - \
	(vars->zoom.x_c - vars->grid.minre) / 0.9;
	vars->grid.maxre = vars->zoom.x_c + \
	(vars->grid.maxre - vars->zoom.x_c) / 0.9;
	vars->grid.minim = vars->zoom.y_c - \
	(vars->zoom.y_c - vars->grid.minim) / 0.9;
	vars->grid.maxim = vars->zoom.y_c + \
	(vars->grid.maxim - vars->zoom.y_c) / 0.9;
	vars->zoom_multiply *= 0.9;
}
