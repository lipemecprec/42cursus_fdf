/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:36:06 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/02 11:32:22 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_draw(t_screen *img, t_wireframe *data)
{
	int		x;
	int		y;
	t_pair	pair;

	y = 0;
	while (y <= data->height - 1)
	{
		x = 0;
		while (x <= data->width - 1)
		{
			if (x < data->width - 1)
			{
				pair = new_line(x, y, (x + 1), y);
				ft_line(img, proj(&pair, img, data));
			}
			if (y < data->height - 1)
			{
				pair = new_line(x, y, x, (y + 1));
				ft_line(img, proj(&pair, img, data));
			}
			x++;
		}
		y++;
	}
}

void	perspective(float *x, float *y, int z, t_angle ang)
{
	*x = (*x - *y) * ang.cos;
	*y = (*x + *y) * ang.sin - z * 5;
}

void	trans(float *x, float *y, int trans_x, int trans_y)
{
	*x += trans_x;
	*y += trans_y;
}

t_pair	proj(t_pair *line, t_screen *img, t_wireframe *data)
{
	int z_bgn;
	int z_end;
	
	z_bgn = data->grid[(int)line->bgn.y][(int)line->bgn.x].z;
	z_end = data->grid[(int)line->end.y][(int)line->end.x].z;
	if (z_bgn)
		line->color = 0xe80c0c;
	line->bgn.x *= data->zoom;
	line->bgn.y *= data->zoom;
	perspective(&line->bgn.x, &line->bgn.y, z_bgn, new_angle(45));
	trans(&line->bgn.x, &line->bgn.y, 100, 150);
	line->end.x *= data->zoom;
	line->end.y *= data->zoom;
	perspective(&line->end.x, &line->end.y, z_end, new_angle(45));
	trans(&line->end.x, &line->end.y, 100, 150);
	return (*line);
}