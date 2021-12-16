/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:22:01 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/16 17:13:39 by faguilar         ###   ########.fr       */
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

void	init_window(t_wireframe *data, char *file_name)
{
	char	*title;
	int		size;

	title = ft_strjoin("FDF - ", file_name);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, SCR_WIDTH, SCR_HEIGHT, title);
	isometric_projection(data);
	size = data->width + data->height;
	data->zoom = (SCR_HEIGHT * 1) / (size * data->angle.cos);
	data->z_scale = 2;
	data->center = point(SCR_WIDTH / 2, SCR_HEIGHT / 2, 0, 0);
	data->position = point(SCR_WIDTH * data->height / size, \
		SCR_HEIGHT * 0.1, 0, 0);
}

int	main(int argc, char **argv)
{
	t_wireframe	*data;

	if (argc != 2)
		return (0);
	data = (t_wireframe *)malloc(sizeof(t_wireframe));
	read_wireframe(data, argv[1]);
	ft_print_data(data); // debug
	init_window(data, argv[1]);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	// mlx_expose_hook(data->win_ptr, deal_key, data);
	// sleep(5);
	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop(data->mlx_ptr);
	free(data);
	return (0);
}
