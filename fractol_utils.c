/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:20:04 by ncathy            #+#    #+#             */
/*   Updated: 2022/05/19 20:53:57 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractol(void)
{
	exit(0);
	return (0);
}

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->data.addr + (int)(y * fractol->data.line_length
			+ x * (fractol->data.bits_per_pixel * 0.125));
	*(unsigned int *)dst = color;
}

int	refresh_win(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx, fractol->win);
	draw_by_pixel(fractol);
	return (0);
}
