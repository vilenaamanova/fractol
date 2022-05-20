/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:18:03 by ncathy            #+#    #+#             */
/*   Updated: 2022/05/19 20:42:19 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_in(int x, int y, t_fractol *fractol)
{
	long double	move_x;
	long double	move_y;
	long double	zoom;

	zoom = 0.8f;
	move_x = (long double)x / ((long double)WIDTH
			/ (long double)(fractol->max_x - fractol->min_x))
		+ (long double)fractol->min_x;
	move_y = (long double)y / ((long double)HEIGHT
			/ (long double)(fractol->max_y - fractol->min_y))
		* -1 + (long double)fractol->max_y;
	fractol->max_x = move_x + ((fractol->max_x - move_x) * zoom);
	fractol->min_x = move_x + ((fractol->min_x - move_x) * zoom);
	fractol->max_y = move_y + ((fractol->max_y - move_y) * zoom);
	fractol->min_y = move_y + ((fractol->min_y - move_y) * zoom);
	refresh_win(fractol);
	return (0);
}

int	zoom_out(int x, int y, t_fractol *fractol)
{
	double	move_x;
	double	move_y;
	double	zoom;

	zoom = 1.2f;
	move_x = (long double)x / ((long double)WIDTH
			/ (long double)(fractol->max_x - fractol->min_x))
		+ (long double)fractol->min_x;
	move_y = (long double)y / ((long double)HEIGHT
			/ (long double)(fractol->max_y - fractol->min_y))
		* -1 + (long double)fractol->max_y;
	fractol->max_x = move_x + ((fractol->max_x - move_x) * zoom);
	fractol->min_x = move_x + ((fractol->min_x - move_x) * zoom);
	fractol->max_y = move_y + ((fractol->max_y - move_y) * zoom);
	fractol->min_y = move_y + ((fractol->min_y - move_y) * zoom);
	refresh_win(fractol);
	return (0);
}

void	mlx_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->win, 2, 5, keyboard, fractol);
	mlx_mouse_hook(fractol->win, zoom_fractol, fractol);
	mlx_hook(fractol->win, 17, 1L << 17, exit_fractol, NULL);
	mlx_key_hook(fractol->win, close_window_esc, fractol);
	if (fractol->fractal_code == 2)
		mlx_hook(fractol->win, 6, 1L << 6, julia_motion, fractol);
}
