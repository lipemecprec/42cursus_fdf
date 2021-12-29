/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:20:18 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/29 18:13:58 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	zoom(t_point *point, t_wireframe *data)
{
	point->x *= data->zoom;
	point->y *= data->zoom;
}

static void	rotation_z(t_point *point, t_wireframe *data)
{
	float	x;
	float	y;
	float	cos;
	float	sin;

	x = point->x - data->center.x;
	y = point->y - data->center.y;
	cos = data->rotation_z.cos;
	sin = data->rotation_z.sin;
	point->x = (cos * x + sin * y) + data->center.x;
	point->y = (-sin * x + cos * y) + data->center.y;
}

static void	tridimensional(t_point *point, t_wireframe *data)
{
	point->x = (point->x - point->y) * data->angle.cos;
	point->y = (point->x + point->y) * data->angle.sin - \
		point->z * data->z_scale * data->zoom;
}

static void	translate(t_point *point, t_wireframe *data)
{
	point->x += data->position.x;
	point->y += data->position.y;
}

t_point	proj(int x, int y, t_wireframe *data)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = data->z_grid[(int)y][(int)x].z;
	point.color = data->z_grid[(int)y][(int)x].color;
	zoom(&point, data);
	rotation_z(&point, data);
	tridimensional(&point, data);
	translate(&point, data);
	return (point);
}
