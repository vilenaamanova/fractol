/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:23:13 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/30 16:11:31 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2)
	{
		printf("%s", "You need to pass the parameter, e.g.:\n./fractol [Mandelbrot] [Julia] [Burning_Ship]");
		exit (1);
	}
	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fract-ol");
	fractol->data.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->data.addr = mlx_get_data_addr(fractol->data.img_ptr, &fractol->data.bits_per_pixel, &fractol->data.line_length, &fractol->data.endian);
	fractol->fractal_name = ft_strdup(argv[1]);
	init_values(fractol);
	select_fractal(fractol->fractal_name, fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->data.img_ptr, 0, 0);
	mlx_hook(fractol->win, 17, 1L << 17, exit_fractol, NULL);
	mlx_key_hook(fractol->win, close_window_esc, fractol);
	mlx_mouse_hook(fractol->win, zoom_fractol, fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
