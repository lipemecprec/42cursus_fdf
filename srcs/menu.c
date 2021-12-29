/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:39:12 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/29 18:16:41 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	menu_bg(t_wireframe *data, t_point bgn, t_point end)
{
	int	y0;

	y0 = bgn.y;
	while (bgn.x < end.x)
	{
		bgn.y = y0;
		while (bgn.y < end.y)
		{
			ft_pixel_put(&data->img, bgn.x, bgn.y, GREY - 0x080808);
			bgn.y++;
		}
		bgn.x++;
	}
}

void	menu_title(t_wireframe *data)
{
	menu_bg(data, point(0, 0, 0, 0), point(130, 20, 0, 0));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 15, TEAL, \
	"Press H for help.");
}

void	menu_show(t_wireframe *data)
{
	int	x_pos;
	int	y_pos;

	menu_bg(data, point(0, 20, 0, 0), point(220, 130, 0, 0));
	x_pos = 10;
	y_pos = 17;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x_pos, y_pos += 20, WHITE, \
	"Press W / S to zoom in / out.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, x_pos, y_pos += 20, WHITE, \
	"Press A / D to rotate ccw / cw.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, x_pos, y_pos += 20, WHITE, \
	"Press Arrow keys to move.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, x_pos, y_pos += 20, WHITE, \
	"Press Z / X to control Z scaling.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, x_pos, y_pos += 20, WHITE, \
	"Press ESC to exit.");
}
