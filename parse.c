/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:52:53 by ncathy            #+#    #+#             */
/*   Updated: 2022/05/19 17:56:05 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_args(t_fractol *fractol, char **argv)
{
	fractol->fractal_name = ft_strdup(argv[1]);
	if (compare(fractol->fractal_name, "Mandelbrot") == 0)
		fractol->fractal_code = 1;
	else if (compare(fractol->fractal_name, "Julia") == 0)
		fractol->fractal_code = 2;
	else if (compare(fractol->fractal_name, "Burning_Ship") == 0)
		fractol->fractal_code = 3;
	else
	{
		write(1, "Incorrect parameter name, e.g.:\n", 33);
		write(1, "[Mandelbrot] [Julia] [Burning_Ship]\n", 36);
		exit(1);
	}
}
