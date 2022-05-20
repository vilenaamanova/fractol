/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:00:10 by ncathy            #+#    #+#             */
/*   Updated: 2022/05/19 20:58:15 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractol *fractol, int iterations)
{
	int	color_code;

	if (fractol->change_color == 1)
		color_code = 0x00F0F8FF;
	else if (fractol->change_color == 2)
		color_code = 0x00FFF0F5;
	else if (fractol->change_color == 3)
		color_code = 0x00F3F0FF;
	if (iterations < MAX_ITERATIONS)
		my_mlx_pixel_put(fractol, fractol->coord.x,
			fractol->coord.y, color_code * iterations);
	else
		my_mlx_pixel_put(fractol, fractol->coord.x,
			fractol->coord.y, 0x00000000);
}

void	draw_by_pixel(t_fractol *fractol)
{
	fractol->coord.y = 0;
	while (fractol->coord.y < HEIGHT)
	{
		fractol->coord.x = 0;
		while (fractol->coord.x < WIDTH)
		{
			if (fractol->fractal_code == 1)
				fractol->iterations = mandelbrot(fractol);
			else if (fractol->fractal_code == 2)
				fractol->iterations = julia(fractol);
			else if (fractol->fractal_code == 3)
				fractol->iterations = burningship(fractol);
			draw_fractal(fractol, fractol->iterations);
			fractol->coord.x++;
		}
		fractol->coord.y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->data.img_ptr, 0, 0);
}
