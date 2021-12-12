/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:47:42 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/12 12:31:15 by faguilar         ###   ########.fr       */
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

	b.axis = 'x';
	calc_bresenham(bgn, end, &b);
	gradient = get_color_gradient(bgn, end);
	while (bgn.x++ <= end.x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, bgn.x, bgn.y, bgn.color);
		bgn.color = add_color_step(bgn.color, gradient);
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

	b.axis = 'y';
	calc_bresenham(bgn, end, &b);
	gradient = get_color_gradient(bgn, end);
	while (bgn.y++ <= end.y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, bgn.x, bgn.y, bgn.color);
		bgn.color = add_color_step(bgn.color, gradient);
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
