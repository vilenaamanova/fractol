/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:23:13 by ncathy            #+#    #+#             */
/*   Updated: 2022/05/19 17:58:01 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2)
	{
		write(1, "You need to pass the parameter, e.g.:\n", 38);
		write(1, "./fractol [Mandelbrot] [Julia] [Burning_Ship]\n", 46);
		exit (1);
	}
	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (-1);
	parse_args(fractol, argv);
	fractol = init_fractol(fractol);
	init_values(fractol);
	draw_by_pixel(fractol);
	mlx_hooks(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
