/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:08:17 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/24 16:47:05 by faguilar         ###   ########.fr       */
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

static void	bresenham_x(t_data *img, t_pair p)
{
	int	ddx;
	int	ddy;
	int	yinc;
	int	pz;

	ddx = 2 * (p.end.x - p.bgn.x);
	ddy = 2 * (p.end.y - p.bgn.y);
	yinc = 1;
	if (ddy < 0)
	{
		yinc = -yinc;
		ddy = -ddy;
	}
	pz = ddy - (ddx / 2);
	while (p.bgn.x++ <= p.end.x)
	{
		ft_putpxl(img, p.bgn.x, p.bgn.y, p.color);
		if (pz > 0)
		{
			pz = pz - ddx + ddy;
			p.bgn.y += yinc;
		}
		else
			pz = pz + ddy;
	}
}

static void	bresenham_y(t_data *img, t_pair p)
{
	int	ddx;
	int	ddy;
	int	xinc;
	int	pz;

	ddx = 2 * (p.end.x - p.bgn.x);
	ddy = 2 * (p.end.y - p.bgn.y);
	xinc = 1;
	if (ddx < 0)
	{
		ddx = -ddx;
		xinc = -xinc;
	}
	pz = ddy - (ddx / 2);
	while (p.bgn.y++ <= p.end.y)
	{
		ft_putpxl(img, p.bgn.x, p.bgn.y, p.color);
		if (pz > 0)
		{
			pz = pz - ddy + ddx;
			p.bgn.x += xinc;
		}
		else
			pz = pz + ddx;
	}
}

void	ft_line(t_data *img, t_pair p)
{
	if (fabs(p.bgn.x - p.end.x) >= fabs(p.bgn.y - p.end.y))
	{
		set_right_direction(&p.bgn.x, &p.bgn.y, &p.end.x, &p.end.y);
		if (p.bgn.y == p.end.y)
			ft_strline(img, p);
		else
			bresenham_x(img, p);
	}
	else
	{
		set_down_direction(&p.bgn.x, &p.bgn.y, &p.end.x, &p.end.y);
		if (p.bgn.x == p.end.x)
			ft_strline(img, p);
		else
			bresenham_y(img, p);
	}
}
