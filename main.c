/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:22:01 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/26 17:50:26 by faguilar         ###   ########.fr       */
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
			printf("%3d", data->z_grid[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}

static t_wireframe	*init_wireframe(char *file_name)
{
	t_wireframe	*data;
	char		*title;
	int			size;

	data = malloc(sizeof(t_wireframe));
	read_wireframe(data, file_name);
	title = ft_strjoin("FDF - ", file_name);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, SCR_WIDTH, SCR_HEIGHT, title);
	free(title);
	isometric_projection(data);
	size = data->width + data->height;
	data->zoom = (SCR_HEIGHT * 1) / (size * data->angle.cos);
	data->z_scale = 2;
	data->center = point(SCR_WIDTH / 2, SCR_HEIGHT / 2, 0, 0);
	data->position = point(SCR_WIDTH * data->height / size, \
		SCR_HEIGHT * 0.1, 0, 0);
	data->up = 1;
	return (data);
}

static int	exposure(t_wireframe *data)
{
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_wireframe	*data;

	if (argc != 2)
		farewell(NULL, 1);
	data = init_wireframe(argv[1]);
	ft_print_data(data); // debug
	draw(data);
	mlx_key_hook(data->win_ptr, &deal_key, data);
	mlx_expose_hook(data->win_ptr, &exposure, data);
	mlx_loop(data->mlx_ptr);
}
