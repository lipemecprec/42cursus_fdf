/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:17:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/13 17:40:54 by faguilar         ###   ########.fr       */
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
	if (key == KEY_W)
		data->zoom += 1;
	else if (key == KEY_S)
		data->zoom -= 1;
	else if (key == KEY_Z)
		data->z_scale += 1;
	else if (key == KEY_X)
		data->z_scale -= 1;
}

static void	key_rotation(int key, t_wireframe *data)
{
	if (key == KEY_N)
		data->rotation_z = angle(data->rotation_z.deg + 5);
	else if (key == KEY_M)
		data->rotation_z = angle(data->rotation_z.deg - 5);
	else if (key == KEY_H)
		data->rotation_y = angle(data->rotation_y.deg + 5);
	else if (key == KEY_J)
		data->rotation_y = angle(data->rotation_y.deg - 5);
	else if (key == KEY_K)
		data->rotation_x = angle(data->rotation_x.deg + 5);
	else if (key == KEY_L)
		data->rotation_x = angle(data->rotation_x.deg - 5);
	else if (key == KEY_I)
		isometric_projection(data);
	else if (key == KEY_O)
		top_projection(data);
	else if (key == KEY_P)
		side_projection(data);
}

int	deal_key(int key, t_wireframe *data)
{
	if (KEY_LEFT <= key && key <= KEY_DOWN)
		key_move(key, data);
	else if (key == KEY_W || key == KEY_S || key == KEY_Z || key == KEY_X)
		key_scale(key, data);
	else if (KEY_H <= key && key <= KEY_P)
		key_rotation(key, data);
	else if (key == KEY_ESC)
		shutdown(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}