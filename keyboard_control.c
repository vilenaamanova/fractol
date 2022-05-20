/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:12:38 by ncathy            #+#    #+#             */
/*   Updated: 2022/05/19 19:30:02 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window_esc(int key, t_fractol *fractol)
{
	if (key == 53)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit(0);
	}
	return (0);
}

int	move_fractal(int key, t_fractol *fractol)
{
	fractol->shift_x = fabsl(fractol->max_x - fractol->min_x);
	fractol->shift_y = fabsl(fractol->max_y - fractol->min_y);
	if (key == 123)
	{
		fractol->min_x -= fractol->shift_x * 0.05;
		fractol->max_x -= fractol->shift_x * 0.05;
	}
	else if (key == 124)
	{
		fractol->min_x += fractol->shift_x * 0.05;
		fractol->max_x += fractol->shift_x * 0.05;
	}
	else if (key == 125)
	{
		fractol->min_y += fractol->shift_y * 0.05;
		fractol->max_y += fractol->shift_y * 0.05;
	}
	else if (key == 126)
	{
		fractol->min_y -= fractol->shift_y * 0.05;
		fractol->max_y -= fractol->shift_y * 0.05;
	}
	return (0);
}

int	choose_color(int key, t_fractol *fractol)
{
	if (key == 18)
		fractol->change_color = 1;
	else if (key == 19)
		fractol->change_color = 2;
	else if (key == 20)
		fractol->change_color = 3;
	return (0);
}

int	keyboard(int key, t_fractol *fractol)
{
	if (key == 49)
		init_values(fractol);
	move_fractal(key, fractol);
	choose_color(key, fractol);
	refresh_win(fractol);
	return (0);
}
