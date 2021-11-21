/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:23:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/20 21:12:47 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h" 

 

void	e_sqr(t_data *img, t_pair p)
{
	t_pair	top;
	t_pair	bot;
	t_pair	lft;
	t_pair	rgt;

	top = new_pair(new_coord(p.bgn.x, p.bgn.y, 0), new_coord(p.bgn.x, p.end.y, 0), p.color);
	bot = new_pair(new_coord(p.bgn.x, p.bgn.y, 0), new_coord(p.end.x, p.bgn.y, 0), p.color);
	lft = new_pair(new_coord(p.end.x, p.end.y, 0), new_coord(p.end.x, p.bgn.y, 0), p.color);
	rgt = new_pair(new_coord(p.end.x, p.end.y, 0), new_coord( p.bgn.x, p.end.y, 0),p.color);
	ft_line(img, top);
	ft_line(img, bot);
	ft_line(img, lft);
	ft_line(img, rgt);
}

t_coord	ft_rotate(t_angle ang, t_coord p)
{
	t_coord rotated;

	rotated.x = (int)(floor(p.x * ang.cos) + floor(p.y * ang.sin));
	rotated.y = (int)(floor(-p.x * ang.sin) + floor(p.y * ang.cos));
	return (rotated);
}

void	ft_grid(t_data *img, t_pair v, t_angle ang, int d)
{
	int y0;
	t_coord	bgn;
	t_coord	end;
	t_pair	line;
	t_angle persp = new_angle(30);

	while (v.bgn.x <= v.end.x)
	{
		y0 = v.bgn.y;
		while (y0 <= v.end.y)
		{
			if (y0 < v.end.y)
			{
				bgn = ft_rotate(ang, new_coord(v.bgn.x, y0 , 0));
				end = ft_rotate(ang, new_coord(v.bgn.x, y0 + d, 0));
				// line = new_pair(bgn, end, GREY);
				// ft_line(img, line);
				bgn = new_proj(bgn.x, bgn.y, bgn.z, persp);
				end = new_proj(end.x, end.y, end.z, persp);
				line = new_pair(bgn, end, LIME);
				ft_line(img, line);
			}
			if (v.bgn.x < v.end.x)
			{
				bgn = ft_rotate(ang, new_coord(v.bgn.x, y0, 0));
				end = ft_rotate(ang, new_coord(v.bgn.x + d, y0, 0));
				// line = new_pair(bgn, end, GREY);
				// ft_line(img, line);
				bgn = new_proj(bgn.x, bgn.y, bgn.z, persp);
				end = new_proj(end.x, end.y, end.z, persp);
				line = new_pair(bgn, end, LIME);
				ft_line(img, line);
			}
			y0 += d;
		}
		v.bgn.x += d;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_pair	line;
	t_coord	bgn;
	t_coord	end;
	t_angle ang;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 256, 256, "fdf");
	img.img = mlx_new_image(mlx, 256, 256);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	bgn = new_coord(20, 20, 0);
	end = new_coord(40, 40, 0);
	line = new_pair(bgn, end, TEAL);
	e_sqr(&img, line);
	ang = new_angle(45);
	ft_grid(&img, new_pair(new_coord(-70, 110, 0), new_coord(90, 250, 0), FUCHSIA), ang, 20);
	e_sqr(&img, new_pair(new_coord(0, 0, 0), new_coord(15, 15, 0), SILVER));
	e_sqr(&img, new_pair(new_coord(240, 0, 0), new_coord(255, 15, 0), BLUE));
	e_sqr(&img, new_pair(new_coord(0, 240, 0), new_coord(15, 255, 0), PURPLE));
	e_sqr(&img, new_pair(new_coord(240, 240, 0), new_coord(255, 255, 0), TEAL));
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	exit(0);
	// mlx_clear_window(&mlx, &mlx_win);
	// mlx_destroy_window(&mlx, &mlx_win);
}
 