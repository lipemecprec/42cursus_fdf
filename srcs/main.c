/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:22:01 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/28 10:23:14 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static t_wireframe	*init_wireframe(char *file_name)
{
	t_wireframe	*data;
	char		*title;
	int			size;

	data = mgrant(sizeof(t_wireframe));
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
	return (data);
}

static void	check_file(char *file_name)
{
	int		fd;
	char	*line;
	
	fd = open_file(file_name);
	line = get_next_line(fd);
	if (!line)
		farewell(NULL, 3);
	while (line)
	{
		set_free(line);
		line = get_next_line(fd);
	}
	set_free(line);
	close(fd);
}

static int	exposure(t_wireframe *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_wireframe	*data;

	if (argc != 2)
		farewell(NULL, 1);
	check_file(argv[1]);
	data = init_wireframe(argv[1]);
	mlx_key_hook(data->win_ptr, &deal_key, data);
	mlx_expose_hook(data->win_ptr, &exposure, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
