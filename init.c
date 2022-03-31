/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:58:35 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/31 17:30:23 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values(t_fractol *fractol)
{
	fractol->max_x = 1.0;
	fractol->max_y = 1.0;
	fractol->min_x = -1.5;
	fractol->min_y = -1.0;
}

void	reset_values(t_fractol *fractol)
{
	fractol->coord.old_im = 0;
	fractol->coord.old_re = 0;
	fractol->coord.new_re = 0;
	fractol->coord.new_im = 0;
	fractol->iterations = 0;
}
