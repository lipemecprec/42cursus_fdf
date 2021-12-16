/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:27:22 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/16 17:08:56 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	free_wireframe_data(t_wireframe *data)
{
	int	i;

	i = 0;
	ft_putstr_fd("Setting memory free.\n", 1);
	while (i <= data->height)
		free(data->z_grid[i++]);
	free(data->z_grid);
	// free(data->mlx_ptr);
	// free(data->win_ptr);
}

static void message(int code)
{
	if (code == 0)
		ft_putstr_fd("FDF gracefully exited\n", 1);
}

void	shutdown(t_wireframe *data, int code)
{
	ft_putstr_fd("Closing FDF...\n", 1);
	free_wireframe_data(data);
	mlx_loop_end(data->mlx_ptr);
	ft_putstr_fd("Destroing window...\n", 1);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// ft_putstr_fd("Destroing image...\n", 1);
	// mlx_destroy_image(data->mlx_ptr, data->win_ptr);
	// ft_putstr_fd("Destroing display...\n", 1);
	// mlx_destroy_display(data->mlx_ptr);
	ft_putstr_fd("exit...\n", 1);
	message(code);
	exit(0);
}
