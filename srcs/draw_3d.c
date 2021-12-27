/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:20:18 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/27 16:50:03 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	isometric_projection(t_wireframe *data)
{
	data->angle = angle(60);
	data->rotation_x = angle(0);
	data->rotation_y = angle(0);
	data->rotation_z = angle(0);
}

void	tridimensional(t_point *point, t_wireframe *data)
{
	point->x = (point->x - point->y) * data->angle.cos;
	point->y = (point->x + point->y) * data->angle.sin - \
		point->z * data->z_scale;
}

void	rotation_z(t_point *point, t_wireframe *data)
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
