/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:17:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/29 18:15:04 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	key_move(int key, t_wireframe *data)
{
	if (key == KEY_LEFT)
		data->position.x -= 10;
	else if (key == KEY_UP)
		data->position.y -= 10;
	else if (key == KEY_RIGHT)
		data->position.x += 10;
	else if (key == KEY_DOWN)
		data->position.y += 10;
}

static void	key_scale(int key, t_wireframe *data)
{
	float	zoom_factor;

	zoom_factor = (float)256 / data->width;
	if (key == KEY_W)
		data->zoom += zoom_factor;
	else if (key == KEY_S)
		data->zoom -= zoom_factor;
	else if (key == KEY_Z)
		data->z_scale += 0.1;
	else if (key == KEY_X)
		data->z_scale -= 0.1;
	if (data->zoom < 1)
		data->zoom = 1;
}

static void	key_rotation(int key, t_wireframe *data)
{
	if (key == KEY_A)
		data->rotation_z = angle(data->rotation_z.deg + 5);
	else if (key == KEY_D)
		data->rotation_z = angle(data->rotation_z.deg - 5);
	else if (key == KEY_I)
		isometric_projection(data);
}

int	deal_key(int key, t_wireframe *data)
{
	if (key == KEY_ESC)
		farewell(data, 0);
	else if (KEY_LEFT <= key && key <= KEY_DOWN)
		key_move(key, data);
	else if (key == KEY_W || key == KEY_S || key == KEY_Z || key == KEY_X)
		key_scale(key, data);
	else if (key == KEY_A || key == KEY_D || key == KEY_I)
		key_rotation(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	if (key == KEY_H)
		menu_show(data);
	return (0);
}
