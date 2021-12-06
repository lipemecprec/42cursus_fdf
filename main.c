/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:22:01 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/06 11:40:36 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void ft_print_data(t_wireframe *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void axis(t_wireframe *data)
{
	t_wireframe	*axis;

	axis = (t_wireframe *)malloc(sizeof(t_wireframe));
	read_wireframe(axis, "test_maps/axis.fdf");
	ft_print_data(axis); // debug
	axis->mlx_ptr = data->mlx_ptr;
	axis->win_ptr = data->win_ptr;
	axis->zoom = 20;
	axis->angle = data->angle;
	axis->z_scale = 10;
	axis->position = point(950, 950, 0, 0);
	draw(axis);
	free(axis);
}

int	deal_key(int key, t_wireframe *data)
{
	if (key == KEY_LEFT)
		data->position.x -= 10;
	if (key == KEY_UP)
		data->position.y -= 10;
	if (key == KEY_RIGHT)
		data->position.x += 10;
	if (key == KEY_DOWN)
		data->position.y += 10;
	if (key == KEY_W)
		data->zoom += 10;
	if (key == KEY_S)
		data->zoom -= 10;
	if (key == KEY_A)
		data->angle = angle(data->angle.deg + 5);
	if (key == KEY_D)
		data->angle = angle(data->angle.deg - 5);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	axis(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_wireframe	*data;

	data = (t_wireframe *)malloc(sizeof(t_wireframe));
	read_wireframe(data, argv[1]);
	ft_print_data(data); // debug
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, SCR_HEIGHT, SCR_WIDTH, "FDF");
	data->zoom = 20;
	data->angle = angle(45);
	data->z_scale = 5;
	data->position = point(150, 150, 0, 0);
	axis(data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}