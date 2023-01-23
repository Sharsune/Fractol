/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:14:18 by sharsune          #+#    #+#             */
/*   Updated: 2023/01/10 19:14:20 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>

enum e_keys
{
	ESC = 53,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124
};

typedef struct {
    double r;       
    double g;       
    double b;       
} rgb;

typedef struct {
    double h;       
    double s;       
    double v;       
} hsv;

struct s_zoom
{
	double x_factor;
	double y_factor;
	double x_c;
	double y_c;
};

struct s_coordinates
{
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	re_factor;
	double	im_factor;
};

struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct	s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
};

typedef struct s_fractal
{
	unsigned int			width;
	unsigned int			height;
	unsigned int			max_iterations;
	double					c_re;
	double					c_im;
	double					z_re;
	double					z_re2;
	double					z_im;
	double					z_im2;
	double					j_re;
	double					j_im;
	struct s_coordinates 	grid;
	struct s_mlx			mlx;
	struct s_data			img;
	struct s_zoom			zoom;
}	t_fractal;

void	initialize_numbers(t_fractal *vars);
void	initialize_zoom(t_fractal *vars, int x, int y);
void	initialize_julia_set(t_fractal *vars);
void	my_mlx_pixel_put(t_fractal *vars, unsigned int x, unsigned int y, int color);
int		make_offset_color(t_fractal *vars, unsigned int n);
int		mandelbrot_set(t_fractal *vars);
int		julia_set(t_fractal *vars);
int		close(void *param);
int		key_deal(int keycode, void *param);
int		move_up(void *param);
int		move_down(void *param);
int 	move_right(void *param);
int		move_left(void *param);
int		mouse_scroll(int keycode, int x, int y, t_fractal *vars);
void 	hsv_to_rgb(double h, double s, double v, int* r, int* g, int* b);
# endif