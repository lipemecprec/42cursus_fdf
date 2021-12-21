/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:36:06 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/18 18:11:12 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	translate(t_point *point, t_wireframe *data)
{
	point->x += data->position.x;
	point->y += data->position.y;
}

t_point	proj(int x, int y, t_wireframe *data)
{
	t_point	point;

	point.x = x * data->zoom;
	point.y = y * data->zoom;
	point.z = data->z_grid[(int)y][(int)x].z;
	point.color = data->z_grid[(int)y][(int)x].color;
	rotation_x(&point, data);
	rotation_y(&point, data);
	rotation_z(&point, data);
	tridimensional(&point, data);
	translate(&point, data);
	return (point);
}

void	draw(t_wireframe *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(proj(x, y, data), proj(x + 1, y, data), data);
			if (y < data->height - 1)
				bresenham(proj(x, y, data), proj(x, y + 1, data), data);
			x++;
		}
		y++;
	}
}
