/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:17:17 by ncathy            #+#    #+#             */
/*   Updated: 2022/05/19 20:45:06 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

# define WIDTH 750
# define HEIGHT 750
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define MAX_ITERATIONS 50
# define SCROLL_UP 5
# define SCROLL_DOWN 4

typedef struct s_comp {
	long double	im;
	long double	re;
}	t_comp;

typedef struct s_coord {
	long double	x;
	long double	y;
	long double	new_re;
	long double	new_im;
	long double	old_re;
	long double	old_im;
}	t_coord;

typedef struct s_data {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractol {
	void		*mlx;
	void		*win;
	char		*fractal_name;
	long double	shift_y;
	long double	shift_x;
	int			iterations;
	int			is_inside;
	int			change_color;
	int			fractal_code;
	long double	min_x;
	long double	max_x;
	long double	min_y;
	long double	max_y;
	long double	zoom;
	t_comp		comp;
	t_data		data;
	t_coord		coord;
}	t_fractol;

/* fractals */
int				mandelbrot(t_fractol *fractol);
int				julia(t_fractol *fractol);
int				burningship(t_fractol *fractol);

/* img control */
int				zoom_in(int x, int y, t_fractol *fractol);
int				zoom_out(int x, int y, t_fractol *fractol);
void			mlx_hooks(t_fractol *fractol);

/* keyboard control */
int				close_window_esc(int key, t_fractol *fractol);
int				move_fractal(int key, t_fractol *fractol);
int				keyboard(int key, t_fractol *fractol);

/* mouse control */
int				zoom_fractol(int key, int x, int y, t_fractol *fractol);
int				julia_motion(int x, int y, t_fractol *fractol);

/* fractol utils */
int				exit_fractol(void);
int				compare(char *s1, char *s2);
void			my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
int				refresh_win(t_fractol *fractol);
void			draw_fractal(t_fractol *fractol, int iterations);
void			draw_by_pixel(t_fractol *fractol);
void			my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void			init_values(t_fractol *fractol);
void			reset_values(t_fractol *fractol);
int				julia_motion(int x, int y, t_fractol *fractol);
void			parse_args(t_fractol *fractol, char **argv);
t_fractol		*init_fractol(t_fractol *fractol);

#	endif
