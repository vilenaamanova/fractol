/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:17:17 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/31 14:05:49 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define WIDTH 1200
# define HEIGHT 900
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define MAX_ITERATIONS 500
# define SCROLL_UP 5
# define SCROLL_DOWN 4

typedef struct s_comp {
	double	im;
	double	re;
}	t_comp;

typedef struct s_coord {
	double	x;
	double	y;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
}	t_coord;

typedef struct s_data {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
	int	opacity;
}	t_rgb;

typedef struct s_fractol {
	void	*mlx;
	void	*win;
	char	*fractal_name;
	double	shift_y;
	double	shift_x;
	int		iterations;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	zoom;
	t_comp	comp;
	t_data	data;
	t_rgb	rgb;
	t_coord	coord;
}	t_fractol;

/* fractals */
int		mandelbrot(t_fractol *fractol);
void	julia(t_fractol *fractol);
void	burningship(t_fractol *fractol);

/* img control */
int		zoom_in(int x, int y, t_fractol *fractol);
int		zoom_out(int x, int y, t_fractol *fractol);

/* keyboard control */
int		close_window_esc(int key, t_fractol *fractol);
int		move_fractal(int key, t_fractol *fractol);

/* mouse control */
int		zoom_fractol(int key, int x, int y, t_fractol *fractol);

/* fractol utils */
int		exit_fractol();
int		compare(char *s1, char *s2);
void	select_fractal(char *parameter, t_fractol *fractol);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
int		refresh_win(t_fractol *fractol);

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void	init_values(t_fractol *fractol);
void	reset_values(t_fractol *fractol);

// int		julia_motion(int x, int y, t_fractol *fractol);

#	endif
