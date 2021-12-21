/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:27:22 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/21 13:54:44 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	set_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_wireframe_data(t_wireframe *data)
{
	int	i;

	ft_putstr_fd("Setting memory free.\n", 1);
	i = 0;
	while (i < data->height)
		set_free(data->z_grid[i++]);
	set_free(data->z_grid);
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
	// ft_putstr_fd("Destroing image...\n", 1);
	// mlx_destroy_image(data->mlx_ptr, data.);
	ft_putstr_fd("Clearing window...\n", 1);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_putstr_fd("Destroing window...\n", 1);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// mlx_destroy_display(data->mlx_ptr);
	ft_putstr_fd("Freeing win_ptr...\n", 1);
	mlx_loop_end(data->mlx_ptr);
	set_free(data->mlx_ptr);
	set_free(data);
	ft_putstr_fd("exit...\n", 1);
	message(code);
}
