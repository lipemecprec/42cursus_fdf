/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:15:09 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/16 16:52:06 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_point	point(float x, float y, float z, int color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}

t_angle	angle(double deg)
{
	t_angle	angle;

	angle.deg = deg;
	angle.rad = (PI / 180) * deg;
	angle.sin = sin(angle.rad);
	angle.cos = cos(angle.rad);
	angle.tan = tan(angle.rad);
	return (angle);
}

t_color	color(int value)
{
	t_color	color;

	color.r = value & 0xFF0000;
	color.g = value & 0x00FF00;
	color.b = value & 0x0000FF;
	color.value = value;
	return (color);
}
