/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:23:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/06 18:43:32 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h" 

// void	f_sqr(t_data *img, t_pair p)
// {
// 	ft_line(img, p);
// }

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_pair	line;
	t_coord	bgn;
	t_coord	end;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 256, 256, "fdf");
	img.img = mlx_new_image(mlx, 256, 256);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	bgn = new_coord(20, 20, 0);
	end = new_coord(40, 40, 0);
	line = new_pair(bgn, end, TEAL);
	e_sqr(&img, line);
	e_sqr(&img, new_pair(new_coord(0, 0, 0), new_coord(15, 15, 0), SILVER));
	e_sqr(&img, new_pair(new_coord(240, 0, 0), new_coord(255, 15, 0), BLUE));
	e_sqr(&img, new_pair(new_coord(0, 240, 0), new_coord(15, 255, 0), PURPLE));
	e_sqr(&img, new_pair(new_coord(240, 240, 0), new_coord(255, 255, 0), TEAL));

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	exit(0);
}