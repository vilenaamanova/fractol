/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:18:03 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/31 17:08:39 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_in(int x, int y, t_fractol *fractol)
{
	double	move_x;
	double	move_y;
	double	zoom;

	zoom = 0.9f;
	move_x = ((double)x / (double)WIDTH) * (fractol->max_x - fractol->min_x) + fractol->min_x;
	move_y = ((double)y / (double)HEIGHT) * (fractol->max_y - fractol->min_y) + fractol->min_y;
	// fractol->max_x = fractol->max_x * zoom + move_x * (1 - zoom);
	// fractol->min_x = fractol->min_x * zoom + move_x * (1 - zoom);
	// fractol->max_y = fractol->max_y * zoom + move_y * (1 - zoom);
	// fractol->min_y = fractol->min_y * zoom + move_y * (1 - zoom);
	fractol->max_x = move_x + (fractol->max_x - move_x) * zoom;
	fractol->min_x = move_x + (fractol->min_x - move_x) * zoom;
	fractol->max_y = move_y + (fractol->max_y - move_y) * zoom;
	fractol->min_y = move_y + (fractol->min_y - move_y) * zoom;
	refresh_win(fractol);
	return (0);
}

int	zoom_out(int x, int y, t_fractol *fractol)
{
	double	move_x;
	double	move_y;
	double	zoom;

	zoom = 1.1f;
	move_x = ((double)x / (double)WIDTH) * (fractol->max_x - fractol->min_x) + fractol->min_x;
	move_y = ((double)y / (double)HEIGHT) * (fractol->max_y - fractol->min_y) + fractol->min_y;
	// fractol->max_x = fractol->max_x * zoom + move_x * (1 - zoom);
	// fractol->min_x = fractol->min_x * zoom + move_x * (1 - zoom);
	// fractol->max_y = fractol->max_y * zoom + move_y * (1 - zoom);
	// fractol->min_y = fractol->min_y * zoom + move_y * (1 - zoom);
	fractol->max_x = move_x + (fractol->max_x - move_x) * zoom;
	fractol->min_x = move_x + (fractol->min_x - move_x) * zoom;
	fractol->max_y = move_y + (fractol->max_y - move_y) * zoom;
	fractol->min_y = move_y + (fractol->min_y - move_y) * zoom;
	refresh_win(fractol);
	return (0);
}
