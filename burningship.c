#include "fractol.h"
#include <unistd.h>
#include <stdio.h>

void	burningship(t_fractol *fractol)
{
	int is_inside;
	t_coord	coord;

	coord.y = 0;
	while(coord.y < HEIGHT)
	{
		fractol->comp.im = (coord.y - HEIGHT / 1.27) * 4.0 / WIDTH;
		coord.x = 0;
		while(coord.x < WIDTH)
		{
			fractol->comp.re = (coord.x - WIDTH / 1.7) * 4.0 / WIDTH;
			fractol->iterations = 0;
			is_inside = 1;
			coord.old_im = 0;
			coord.old_re = 0;
			coord.new_re = 0;
			coord.new_im = 0;
			while (fractol->iterations < MAX_ITERATIONS)
			{
				coord.old_im = coord.new_im;
				coord.old_re = coord.new_re;
				coord.new_re = coord.old_re * coord.old_re - coord.old_im * coord.old_im + fractol->comp.re;
				coord.new_im = 2.0 * fabs(coord.old_re * coord.old_im) + fractol->comp.im;
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
