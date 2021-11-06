/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:23:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/06 18:08:14 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h" 

void	f_sqr(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	while (x1 <= x2)
	{
		ft_line(img, x1, y1, x1, y2,  color );
		x1++;
	}
}

void	e_sqr(t_data *img, t_pair p)
{
	ft_line(img, p.bgn.x, p.bgn.y, p.bgn.x, p.end.y, p.color);
	ft_line(img, p.bgn.x, p.bgn.y, p.end.x, p.bgn.y, p.color);
	ft_line(img, p.end.x, p.end.y, p.end.x, p.bgn.y, p.color);
	ft_line(img, p.end.x, p.end.y, p.bgn.x, p.end.y, p.color);
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
	f_sqr(&img, 0, 0, 15, 15, TEAL ); // 0
	f_sqr(&img, 240, 0, 255, 15, PURPLE ); // ++X
	f_sqr(&img, 0, 240, 15, 255, BLUE ); // +Y
	f_sqr(&img, 240, 240, 255, 255, SILVER ); // XY
	e_sqr(&img, new_pair(new_coord(0, 0, 0), new_coord(15, 15, 0), SILVER));
	e_sqr(&img, new_pair(new_coord(240, 0, 0), new_coord(255, 15, 0), BLUE));
	e_sqr(&img, new_pair(new_coord(0, 240, 0), new_coord(15, 255, 0), PURPLE));
	e_sqr(&img, new_pair(new_coord(240, 240, 0), new_coord(255, 255, 0), TEAL));

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	exit(0);
}