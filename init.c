/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:58:35 by ncathy            #+#    #+#             */
/*   Updated: 2022/05/19 20:59:39 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fract-ol");
	fractol->data.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->data.addr = mlx_get_data_addr(fractol->data.img_ptr,
			&fractol->data.bits_per_pixel, &fractol->data.line_length,
			&fractol->data.endian);
	fractol->change_color = 1;
	return (fractol);
}

void	init_values(t_fractol *fractol)
{
	fractol->max_x = 2.0;
	fractol->max_y = 2.0;
	fractol->min_x = -2.0;
	fractol->min_y = -2.0;
	fractol->zoom = 1.0f;
}

void	reset_values(t_fractol *fractol)
{
	fractol->coord.old_im = 0;
	fractol->coord.old_re = 0;
	fractol->coord.new_re = 0;
	fractol->coord.new_im = 0;
	fractol->iterations = 0;
}
