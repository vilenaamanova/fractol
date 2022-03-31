/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:20:04 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/31 17:44:29 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractol()
{
	exit(0);
	return (0);
}

int	compare(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	select_fractal(char *parameter, t_fractol *fractol)
{
	if (compare(parameter, "Mandelbrot") == 0)
		mandelbrot(fractol);
	else if (compare(parameter, "Julia") == 0)
		julia(fractol);
	else if (compare(parameter, "Burning_Ship") == 0)
		burningship(fractol);
	else
	{
		printf("Incorrect parameter name, try entering a parameter from the list below:\n[Mandelbrot] [Julia] [Burning_Ship]");
		exit(1);
	}
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char *dst;

	dst = fractol->data.addr + (y * fractol->data.line_length + x * (fractol->data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	refresh_win(t_fractol *fractol)
{
	// mlx_destroy_image(fractol->mlx, fractol->data.img_ptr);
	// // select_fractal(fractol->fractal_name, fractol);
	// // mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->data.img_ptr, 0, 0);
	// mlx_clear_window(fractol->mlx, fractol->win);
	// fractol->data.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	// fractol->data.addr = mlx_get_data_addr(fractol->data.img_ptr, &fractol->data.bits_per_pixel, &fractol->data.line_length, &fractol->data.endian);
	// select_fractal(fractol->fractal_name, fractol);
	// mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->data.img_ptr, 0, 0);
	mlx_clear_window(fractol->mlx, fractol->win);
	select_fractal(fractol->fractal_name, fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->data.img_ptr, 0, 0);
	return (0);
}
