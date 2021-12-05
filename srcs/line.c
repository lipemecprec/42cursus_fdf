/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:47:42 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/04 22:39:17 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	set_right_direction(float *x1, float *y1, float *x2, float *y2)
{
	float	temp;

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

static void	set_down_direction(float *x1, float *y1, float *x2, float *y2)
{
	float	temp;

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

static void	bresenham_x(t_point bgn, t_point end, t_wireframe *data)
{
	int	ddx;
	int	ddy;
	int	yinc;
	int	pz;

	ddx = 2 * (end.x - bgn.x);
	ddy = 2 * (end.y - bgn.y);
	yinc = 1;
	if (ddy < 0)
	{
		yinc = -yinc;
		ddy = -ddy;
	}
	pz = ddy - (ddx / 2);
	while (bgn.x++ <= end.x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, bgn.x, bgn.y, bgn.color);
		if (pz > 0)
		{
			pz = pz - ddx + ddy;
			bgn.y += yinc;
		}
		else
			pz = pz + ddy;
	}
}

static void	bresenham_y(t_point bgn, t_point end, t_wireframe *data)
{
	int	ddx;
	int	ddy;
	int	xinc;
	int	pz;

	ddx = 2 * (end.x - bgn.x);
	ddy = 2 * (end.y - bgn.y);
	xinc = 1;
	if (ddx < 0)
	{
		ddx = -ddx;
		xinc = -xinc;
	}
	pz = ddy - (ddx / 2);
	while (bgn.y++ <= end.y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, bgn.x, bgn.y, bgn.color);
		if (pz > 0)
		{
			pz = pz - ddy + ddx;
			bgn.x += xinc;
		}
		else
			pz = pz + ddx;
	}
}

void	bresenham(t_point bgn, t_point end, t_wireframe *data)
{
	if (fabs(bgn.x - end.x) >= fabs(bgn.y - end.y))
	{
		set_right_direction(&bgn.x, &bgn.y, &end.x, &end.y);
		if (bgn.y == end.y)
			strline(bgn, end, data);
		else
			bresenham_x(bgn, end, data);
	}
	else
	{
		set_down_direction(&bgn.x, &bgn.y, &end.x, &end.y);
		if (bgn.x == end.x)
			strline(bgn, end, data);
		else
			bresenham_y(bgn, end, data);
	}
}
