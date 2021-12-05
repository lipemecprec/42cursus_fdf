/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:56:01 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/04 21:25:06 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	strline(t_point bgn, t_point end, t_wireframe *data)
{
	if (bgn.x == end.x)
	{
		while (bgn.y <= end.y)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
				bgn.x, bgn.y, bgn.color);
			bgn.y++;
		}
	}
	else if (bgn.y == end.y)
	{
		while (bgn.x <= end.x)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
				bgn.x, bgn.y, bgn.color);
			bgn.x++;
		}
	}
}
