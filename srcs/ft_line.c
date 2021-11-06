/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:08:17 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/06 18:06:01 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	set_right_direction(int *x1, int *y1, int *x2, int *y2)
{
	int	temp;

	if (*x1 > *x2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
		temp = *y1;
		*y1 = *y2;
		*y2 = temp;
	}
}

static void	set_down_direction(int *x1, int *y1, int *x2, int *y2)
{
	int	temp;

	if (*y1 > *y2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
		temp = *y1;
		*y1 = *y2;
		*y2 = temp;
	}
}

static void	bresenham_x(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	int	ddx;
	int	ddy;
	int	yinc;
	int	pz;

	ddx = 2 * (x2 - x1);
	ddy = 2 * (y2 - y1);
	yinc = 1;
	if (ddy < 0)
	{
		yinc = -yinc;
		ddy = -ddy;
	}
	pz = ddy - (ddx / 2);
	while (x1++ <= x2)
	{
		ft_putpxl(img, x1, y1, color);
		if (pz > 0)
		{
			pz = pz - ddx + ddy;
			y1 += yinc;
		}
		else
			pz = pz + ddy;
	}
}

static void	bresenham_y(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	int	ddx;
	int	ddy;
	int	xinc;
	int	pz;

	ddx = 2 * (x2 - x1);
	ddy = 2 * (y2 - y1);
	xinc = 1;
	if (ddx < 0)
	{
		ddx = -ddx;
		xinc = -xinc;
	}
	pz = ddy - (ddx / 2);
	while (y1++ <= y2)
	{
		ft_putpxl(img, x1, y1, color);
		if (pz > 0)
		{
			pz = pz - ddy + ddx;
			x1 += xinc;
		}
		else
			pz = pz + ddx;
	}
}

static void	strline(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	if (x1 == x2)
	{
		while (y1 <= y2)
		{
			ft_putpxl(img, x1, y1, color);
			y1++;
		}
	}
	else if (y1 == y2)
	{
		while (x1 <= x2)
		{
			ft_putpxl(img, x1, y1, color);
			x1++;
		}
	}
}

void	ft_line(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	if (fabs((double)(x1 - x2)) >= fabs((double)(y1 - y2)))
	{
		set_right_direction(&x1, &y1, &x2, &y2);
		if (y1 == y2)
			strline(img, x1, y1, x2, y2, color);
		else
			bresenham_x(img, x1, y1, x2, y2, color);
	}
	else
	{
		set_down_direction(&x1, &y1, &x2, &y2);
		if (x1 == x2)
			strline(img, x1, y1, x2, y2, color);
		else
			bresenham_y(img, x1, y1, x2, y2, color);
	}
}
