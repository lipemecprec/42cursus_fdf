/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:23:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/24 22:22:49 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h" 

// void	e_sqr(t_data *img, t_pair p)
// {
// 	t_pair	top;
// 	t_pair	bot;
// 	t_pair	lft;
// 	t_pair	rgt;

// 	top = new_pair(new_coord(p.bgn.x, p.bgn.y, 0), new_coord(p.bgn.x, p.end.y, 0), p.color);
// 	bot = new_pair(new_coord(p.bgn.x, p.bgn.y, 0), new_coord(p.end.x, p.bgn.y, 0), p.color);
// 	lft = new_pair(new_coord(p.end.x, p.end.y, 0), new_coord(p.end.x, p.bgn.y, 0), p.color);
// 	rgt = new_pair(new_coord(p.end.x, p.end.y, 0), new_coord( p.bgn.x, p.end.y, 0),p.color);
// 	ft_line(img, top);
// 	ft_line(img, bot);
// 	ft_line(img, lft);
// 	ft_line(img, rgt);
// }

// t_coord	ft_rotate(t_angle ang, t_coord p)
// {
// 	t_coord rotated;

// 	rotated.x = (int)(floor(p.x * ang.cos) + floor(p.y * ang.sin));
// 	rotated.y = (int)(floor(-p.x * ang.sin) + floor(p.y * ang.cos));
// 	return (rotated);
// }

// void	ft_grid(t_data *img, t_pair v, t_angle ang, int d)
// {
// 	int y0;
// 	t_coord	bgn;
// 	t_coord	end;
// 	t_pair	line;
// 	t_angle persp = new_angle(15);

// 	while (v.bgn.x <= v.end.x)
// 	{
// 		y0 = v.bgn.y;
// 		while (y0 <= v.end.y)
// 		{
// 			if (y0 < v.end.y)
// 			{
// 				bgn = ft_rotate(ang, new_coord(v.bgn.x, y0 , 0));
// 				end = ft_rotate(ang, new_coord(v.bgn.x, y0 + d, 0));
// 				// line = new_pair(bgn, end, GREY);
// 				// ft_line(img, line);
// 				bgn = new_proj(bgn.x, bgn.y, bgn.z, persp);
// 				end = new_proj(end.x, end.y, end.z, persp);
// 				line = new_pair(bgn, end, LIME);
// 				ft_line(img, line);
// 			}
// 			if (v.bgn.x < v.end.x)
// 			{
// 				bgn = ft_rotate(ang, new_coord(v.bgn.x, y0, 0));
// 				end = ft_rotate(ang, new_coord(v.bgn.x + d, y0, 0));
// 				// line = new_pair(bgn, end, GREY);
// 				// ft_line(img, line);
// 				bgn = new_proj(bgn.x, bgn.y, bgn.z, persp);
// 				end = new_proj(end.x, end.y, end.z, persp);
// 				line = new_pair(bgn, end, LIME);
// 				ft_line(img, line);
// 			}
// 			y0 += d;
// 		}
// 		v.bgn.x += d;
// 	}
// }

int	deal_key(int key, t_data *img)
{
	printf("%d", key);
	return (0);
}

int	main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_data		img;
	t_wireframe	*data;
	t_angle		ang;

	if (argc != 2)
		return(1);
	data = (t_wireframe *)malloc(sizeof(t_wireframe));
	ft_read_wireframe(argv[1], data);
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1024, 1024, "FDF");
	mlx_key_hook(mlx_win, deal_key, NULL);
	img.img = mlx_new_image(mlx_ptr, 1024, 1024);
	img.zoom = 10;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	ft_draw(&img, data);
	mlx_key_hook(mlx_win, deal_key, &img);
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);

	mlx_loop(mlx_ptr);
	// mlx_clear_window(&mlx, &mlx_win);
	// mlx_destroy_window(&mlx, &mlx_win);

}
 