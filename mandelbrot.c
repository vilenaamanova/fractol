#include "fractol.h"
#include <unistd.h>
#include <stdio.h>

int	mandelbrot(t_fractol *fractol)
{
	int		is_inside;

	fractol->coord.y = 0;
	while(fractol->coord.y < HEIGHT)
	{
		fractol->coord.x = 0;
		// fractol->comp.im = 4 * (fractol->coord.y - HEIGHT / 2) / WIDTH;
		fractol->comp.im = fractol->max_y - (fractol->coord.y * ((fractol->max_y - fractol->min_y) / ((double)HEIGHT - 1)));
		while(fractol->coord.x < WIDTH)
		{
			reset_values(fractol);
			is_inside = 1;
			// fractol->comp.re = 4 * (fractol->coord.x - WIDTH / 1.6) / WIDTH;
			fractol->comp.re = fractol->min_x + (fractol->coord.x * ((fractol->max_x - fractol->min_x) / ((double)WIDTH - 1)));
			while (fractol->iterations < MAX_ITERATIONS)
			{
				fractol->coord.old_im = fractol->coord.new_im;
				fractol->coord.old_re = fractol->coord.new_re;
				fractol->coord.new_re = fractol->coord.old_re * fractol->coord.old_re - fractol->coord.old_im * fractol->coord.old_im + fractol->comp.re;
				fractol->coord.new_im = 2 * fractol->coord.old_re * fractol->coord.old_im + fractol->comp.im;
				fractol->iterations++;
				if ((fractol->coord.new_im * fractol->coord.new_im + fractol->coord.new_re * fractol->coord.new_re) > 4)
				{
					is_inside = 0;
					break;
				}
			}
			if (is_inside == 1)
				my_mlx_pixel_put(fractol, fractol->coord.x, fractol->coord.y, 0x00000000);
			else if (is_inside == 0)
				my_mlx_pixel_put(fractol, fractol->coord.x, fractol->coord.y, 0x001DA0E6 * fractol->iterations);
			fractol->coord.x++;
		}
		fractol->coord.y++;
	}
	return (fractol->iterations);
}
