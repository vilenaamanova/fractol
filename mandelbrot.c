/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:54:37 by ncathy            #+#    #+#             */
/*   Updated: 2022/05/19 20:39:15 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_mandelbrot(t_fractol *fractol)
{
	fractol->comp.re = fractol->min_x + fractol->coord.x
		* ((fractol->max_x - fractol->min_x) / (HEIGHT - 1));
	fractol->comp.im = fractol->max_y - fractol->coord.y
		* ((fractol->max_x - fractol->min_x) / (WIDTH - 1));
}

int	mandelbrot(t_fractol *fractol)
{
	fractol->iterations = 0;
	fractol->coord.new_re = 0;
	fractol->coord.new_im = 0;
	calculate_mandelbrot(fractol);
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
