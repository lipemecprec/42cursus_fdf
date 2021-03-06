/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:47:42 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/28 16:04:23 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	calc_bresenham(t_point bgn, t_point end, t_bresenham *b)
{
	b->ddx = 2 * (end.x - bgn.x);
	b->ddy = 2 * (end.y - bgn.y);
	b->step = 1;
	if (b->ddy < 0 || b->ddx < 0)
	{
		if (b->axis == 'y')
			b->ddx = -b->ddx;
		else
			b->ddy = -b->ddy;
		b->step = -b->step;
	}
	b->pz = b->ddy - (b->ddx / 2);
}

static void	bresenham_x(t_point bgn, t_point end, t_wireframe *data)
{
	t_bresenham	b;
	t_color		gradient;
	t_color		bgn_c;

	b.axis = 'x';
	calc_bresenham(bgn, end, &b);
	gradient = get_color_gradient(bgn, end);
	bgn_c = color(bgn.color);
	while (bgn.x++ <= end.x)
	{
		ft_pixel_put(&data->img, bgn.x, bgn.y, bgn_c.value);
		add_color_step(&bgn_c, gradient);
		if (b.pz > 0)
		{
			b.pz = b.pz - b.ddx + b.ddy;
			bgn.y += b.step;
		}
		else
			b.pz = b.pz + b.ddy;
	}
}

static void	bresenham_y(t_point bgn, t_point end, t_wireframe *data)
{
	t_bresenham	b;
	t_color		gradient;
	t_color		bgn_c;

	b.axis = 'y';
	calc_bresenham(bgn, end, &b);
	gradient = get_color_gradient(bgn, end);
	bgn_c = color(bgn.color);
	while (bgn.y++ <= end.y)
	{
		ft_pixel_put(&data->img, bgn.x, bgn.y, bgn_c.value);
		add_color_step(&bgn_c, gradient);
		if (b.pz > 0)
		{
			b.pz = b.pz - b.ddy + b.ddx;
			bgn.x += b.step;
		}
		else
			b.pz = b.pz + b.ddx;
	}
}

void	bresenham(t_point bgn, t_point end, t_wireframe *data)
{
	if (fabs(bgn.x - end.x) >= fabs(bgn.y - end.y))
	{
		set_right_direction(&bgn, &end);
		bresenham_x(bgn, end, data);
	}
	else
	{
		set_down_direction(&bgn, &end);
		bresenham_y(bgn, end, data);
	}
}
