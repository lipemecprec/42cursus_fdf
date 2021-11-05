/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:23:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/04 22:09:39 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h" 

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	f_sqr(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	int x;
	int y;
	
	x = x1;
	while (x < x2)
	{
		y = y1;
		while(y < y2)
		{
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}

void	e_sqr(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	int x;
	int y;
	
	x = x1;
	while (x < x2)
	{
		my_mlx_pixel_put(img, x, y1, color);
		my_mlx_pixel_put(img, x, y2, color);
		x++;
	}
	y = y1;
	while(y < y2)
	{
		my_mlx_pixel_put(img, x1, y, color);
		my_mlx_pixel_put(img, x2, y, color);
		y++;
	}
}

void	set_right_direction(int *x1, int *y1, int *x2, int *y2)
{
	int temp;

	if(*x1 > *x2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
		temp = *y1;
		*y1 = *y2;
		*y2 = temp;
	}
}

void	set_down_direction(int *x1, int *y1, int *x2, int *y2)
{
	int temp;

	if(*y1 > *y2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
		temp = *y1;
		*y1 = *y2;
		*y2 = temp;
	}
}

void	bresenham_x(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	int ddx;
	int ddy;
	int yinc;
	int pz;
	
	ddx = 2 * ( x2 - x1 );
	ddy = 2 * ( y2 - y1 );
	yinc = 1;
	if (ddy < 0)
	{
		yinc = -yinc;
		ddy = -ddy;
	}
	pz = ddy - ( ddx / 2 );
	while(x1++ <= x2)
	{
		my_mlx_pixel_put(img, x1, y1, color);
		if (pz > 0)
		{
			pz = pz - ddx + ddy;
			y1 += yinc;
		}
		else
			pz = pz + ddy;
	}
}

void	bresenham_y(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	int ddx;
	int ddy;
	int xinc;
	int pz;
	
	ddx = 2 * ( x2 - x1 );
	ddy = 2 * ( y2 - y1 );
	xinc = 1;
	if (ddx < 0)
	{
		ddx = -ddx;
		xinc = -xinc;
	}
	pz = ddy - ( ddx / 2 );
	while(y1++ <= y2)
	{
		my_mlx_pixel_put(img, x1, y1, color);
		if (pz > 0)
		{
			pz = pz - ddy + ddx;
			x1 += xinc;
		}
		else
			pz = pz + ddx;
	}
}

void	strline(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	if(x1 == x2)
	{
		while (y1 <= y2)
		{
			my_mlx_pixel_put(img, x1, y1, color);
			y1++;
		}
	}
	else if(y1 == y2)
	{
		while (x1 <= x2)
		{
			my_mlx_pixel_put(img, x1, y1, color);
			x1++;
		}
	}
}

void	line(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	if (fabs(x1 - x2) >= fabs(y1 - y2))
	{
		set_right_direction(&x1, &y1, &x2, &y2);
		if(y1 == y2)
			strline(img, x1, y1, x2, y2, color);
		else
			bresenham_x(img, x1, y1, x2, y2, color);
	}
	else
	{
		set_down_direction(&x1, &y1, &x2, &y2);
		if(x1 == x2)
			strline(img, x1, y1, x2, y2, color);
		else
			bresenham_y(img, x1, y1, x2, y2, color);
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 256, 256, "fdf");
	img.img = mlx_new_image(mlx, 256, 256);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// squares
	int i = 0;
	while(i < 250)
	{
		int j = 0;
		while (j < 250)
		{
			e_sqr(&img, i, j, i + 10, j + 10, 0x00220022 );
			j += 10;
		}
		i += 10;
	}
	f_sqr(&img, 0, 0, 15, 15, TEAL ); // 0
	f_sqr(&img, 240, 0, 255, 15, PURPLE ); // ++X
	f_sqr(&img, 0, 240, 15, 255, BLUE ); // +Y
	f_sqr(&img, 240, 240, 255, 255, SILVER ); // XY
	// lines
	line(&img, 10,  10, 10,  250,  WHITE ); // VERTICAL
	line(&img, 20, 250, 20,  20,  RED ); // VERTICAL
	line(&img, 30,  30, 250,  30, BLUE ); // HORIZONTAL
	line(&img, 250, 40, 40,  40, YELLOW ); // HORIZONTAL
	line(&img, 50,  50, 120, 120,  CYAN );
	line(&img, 260, 260,120, 120,  FUCHSIA );
	line(&img, 60,  230, 230, 70,  SILVER );
	line(&img, 220, 80, 80,  220,  GREEN );
	line(&img, 10,  250,200, 0,   PURPLE );
	line(&img, 250, 10, 140, 140, TEAL );
	line(&img, 120, 140,140, 10,  WHITE );
	line(&img, 10,  10, 50,  250, RED );
	line(&img, 10,  10, 250, 10,  BLUE );

	// int matrix[3][3] = { { 0, 0, 0}, { 0, 0, 0 } };

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	exit(0);
}