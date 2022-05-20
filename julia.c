/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:00:31 by ncathy            #+#    #+#             */
/*   Updated: 2022/05/19 20:39:28 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_julia(t_fractol *fractol)
{
	fractol->coord.new_re = fractol->min_x + fractol->coord.x
		* ((fractol->max_x - fractol->min_x) / (HEIGHT - 1));
	fractol->coord.new_im = fractol->max_y - fractol->coord.y
		* ((fractol->max_x - fractol->min_x) / (WIDTH - 1));
}

int	julia_motion(int x, int y, t_fractol *fractol)
{
	fractol->comp.re = 4 * ((double)x / WIDTH - 0.5);
	fractol->comp.im = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
	refresh_win(fractol);
	return (0);
}

int	julia(t_fractol *fractol)
{
	fractol->iterations = 0;
	fractol->coord.new_re = 0;
	fractol->coord.new_im = 0;
	calculate_julia(fractol);
	while (pow(fractol->coord.new_im, 2.0)
		+ pow(fractol->coord.new_re, 2.0) <= 4
		&& fractol->iterations < MAX_ITERATIONS)
	{
		fractol->coord.old_re = pow(fractol->coord.new_re, 2.0)
			- pow(fractol->coord.new_im, 2.0) + fractol->comp.re;
		fractol->coord.new_im = 2 * fractol->coord.new_re
			* fractol->coord.new_im + fractol->comp.im;
		fractol->coord.new_re = fractol->coord.old_re;
		fractol->iterations++;
	}
	return (fractol->iterations);
}
