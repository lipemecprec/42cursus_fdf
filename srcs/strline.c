/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:56:01 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/08 19:37:51 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int get_color(t_point bgn, t_point end, t_point act)
{
	if ((end.z-bgn.z) != 0)
		return (bgn.color + (((act.z-bgn.z)/(end.z-bgn.z))*(end.color-bgn.color)));
	return (bgn.color);
}

void	strline(t_point bgn, t_point end, t_wireframe *data)
{
	t_point	act;

	act = bgn;
	if (bgn.x == end.x)
	{
		while (act.y <= end.y)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
				act.x, act.y, get_color(bgn, end, act));
			act.y++;
		}
	}
	else if (bgn.y == end.y)
	{
		while (act.x <= end.x)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
				act.x, act.y, get_color(bgn, end, act));
			act.x++;
		}
	}
}
