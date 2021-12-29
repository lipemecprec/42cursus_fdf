/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:36:06 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/29 18:14:11 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	set_img_center(t_wireframe *data)
{
	data->center.x = (data->width / 2) * data->zoom;
	data->center.y = (data->height / 2) * data->zoom;
}

static void	clear_image(t_wireframe *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCR_WIDTH)
	{
		y = 0;
		while (y < SCR_HEIGHT)
		{
			ft_pixel_put(&data->img, x, y, BG_COLOR);
			y++;
		}
		x++;
	}
}

void	draw(t_wireframe *data)
{
	int	x;
	int	y;

	clear_image(data);
	set_img_center(data);
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	menu_title(data);
}
