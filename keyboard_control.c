/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:12:38 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/29 12:33:55 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window_esc(int key, t_fractol *fractol)
{
	// printf("%d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit(0);
	}
	return (0);
}

int	move_fractal(int key, t_fractol *fractol)
{
	if (key == 126)
		fractol->shift_y -= 10;
	else if (key == 125)
		fractol->shift_y += 10;
	else if (key == 123)
		fractol->shift_x -= 10;
	else if (key == 124)
		fractol->shift_x += 10;
	mlx_clear_window(fractol->mlx, fractol->win);
	return (0);
}
