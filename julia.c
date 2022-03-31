#include "fractol.h"
#include <unistd.h>
#include <stdio.h>

// int	julia_motion(int x, int y, t_fractol *fractol)
// {
// 	fractol->comp.re = 4 * ((double)x / WIDTH - 0.5);
// 	fractol->comp.im = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
// 	julia(fractol);
// 	return (0);
// }

void	julia(t_fractol *fractol)
{
	int is_inside;
	t_coord coord;

	fractol->comp.re = 0.28;
	fractol->comp.im = 0.008;

	coord.y = 0;
	while(coord.y < HEIGHT)
	{
		coord.x = 0;
		while(coord.x < WIDTH)
		{
			fractol->iterations = 0;
			is_inside = 1;
			// julia_motion(coord.x, coord.y, fractol);
			coord.new_re = 4 * (coord.x - WIDTH / 2) / WIDTH;
			coord.new_im = 4 * (coord.y - HEIGHT / 2) / WIDTH;
			while (fractol->iterations < MAX_ITERATIONS)
			{
				coord.old_im = coord.new_im;
				coord.old_re = coord.new_re;
				coord.new_re = coord.old_re * coord.old_re - coord.old_im * coord.old_im + fractol->comp.re;
				coord.new_im = 2 * coord.old_re * coord.old_im + fractol->comp.im;
				fractol->iterations++;
				if ((coord.new_im * coord.new_im + coord.new_re * coord.new_re) > 4)
				{
					is_inside = 0;
					break;
				}
			}
			if (is_inside == 1)
				my_mlx_pixel_put(fractol, coord.x, coord.y, 0x00000000);
			else if (is_inside == 0)
				my_mlx_pixel_put(fractol, coord.x, coord.y, 0x001DA0E6 * fractol->iterations);
			coord.x++;
		}
		coord.y++;
	}
}
