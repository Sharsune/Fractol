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

# include <mlx.h>
# include "libft/libft.h"

enum e_keys
{
	ESC = 53,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124
};

struct s_zoom
{
	double	x_factor;
	double	y_factor;
	double	x_c;
	double	y_c;
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
	void	*mlx_ptr;
	void	*win_ptr;
};

typedef struct s_fractal
{
	unsigned int			width;
	unsigned int			height;
	unsigned int			max_iterations;
	int						argc;
	char					**argv;
	double					c_re;
	double					c_im;
	double					z_re;
	double					z_re2;
	double					z_im;
	double					z_im2;
	double					j_re;
	double					j_im;
	double					zoom_multiply;
	struct s_coordinates	grid;
	struct s_mlx			mlx;
	struct s_data			img;
	struct s_zoom			zoom;
}	t_fractal;

void	start_mlx(t_fractal *vars);
void	error_exit(void);
void	check_argv(t_fractal *vars);
void	check_digits(const char *str);
double	ft_atof(const char *str);
double	after_dot(const char *str, int i, int sign, int result);
void	initialize_mandelbrot(t_fractal *vars);
void	initialize_zoom(t_fractal *vars, int x, int y);
void	initialize_julia(t_fractal *vars);
void	my_mlx_pixel_put(t_fractal *vars, unsigned int x, \
unsigned int y, int *color);
void	make_colors(unsigned char *colors, int inside, unsigned int n);
void	mandelbrot_set(t_fractal *vars);
void	julia_set(t_fractal *vars);
void	inner_loop(t_fractal *vars, unsigned int *n, int *inside);
int		close_window(void *param);
int		key_deal(int keycode, void *param);
int		move_up(void *param);
int		move_down(void *param);
int		move_right(void *param);
int		move_left(void *param);
void	zoom_in(t_fractal *vars);
void	zoom_out(t_fractal *vars);
int		mouse_scroll(int keycode, int x, int y, void *param);
#endif