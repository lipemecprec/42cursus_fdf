/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:01:40 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/07 14:37:48 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_coord	new_coord(int x, int y, int z)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}

t_pair	new_pair(t_coord bgn, t_coord end, int color)
{
	t_pair	pair;

	pair.bgn = bgn;
	pair.end = end;
	pair.color = color;
	return (pair);
}

t_angle	new_angle(double deg)
{
	t_angle	angle;

	angle.deg = deg;
	angle.rad = PI / 180 * deg;
	angle.sin = sin(angle.rad);
	angle.cos = cos(angle.rad);
	angle.tan = tan(angle.rad);
	return (angle);
}
