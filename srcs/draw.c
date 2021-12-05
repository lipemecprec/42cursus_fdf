/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:36:06 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/04 23:42:05 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	tridimensional(t_point *point, t_wireframe *data)
{
	point->x = (point->x - point->y) * data->angle.cos;
	point->y = (point->x + point->y) * data->angle.sin - \
		point->z * data->z_scale;
}

void	translate(t_point *point, t_wireframe *data)
{
	point->x += data->position.x;
	point->y += data->position.y;
}

t_point	proj(int x, int y, t_wireframe *data)
{
	t_point	proj;

	proj.x = x * data->zoom;
	proj.y = y * data->zoom;
	proj.z = data->z_grid[(int)y][(int)x];
	if (proj.z == 0)
		proj.color = YELLOW;
	else
		proj.color = RED;
	tridimensional(&proj, data);
	translate(&proj, data);
	return (proj);
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
