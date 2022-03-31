/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:12:05 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/30 16:12:00 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_fractol(int key, int x, int y, t_fractol *fractol)
{
	if (key == SCROLL_UP)
		zoom_in(x, y, fractol);
	else if (key == SCROLL_DOWN)
		zoom_out(x, y, fractol);
	return (0);
}
