/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:27:22 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/29 18:12:27 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	free_wireframe_data(t_wireframe *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->z_grid[i++]);
	free(data->z_grid);
}

static void	message(int code)
{
	if (code == 0)
		ft_putstr_fd("\033[0;36mFDF closed.\033[00m\n", 1);
	else if (code == 1)
		ft_putstr_fd \
		("\033[0;31mError - Wrong number of arguments.\033[00m\n", 1);
	else if (code == 2)
		ft_putstr_fd("\033[0;31mError - Out of Memory.\033[00m\n", 1);
	else if (code == 3)
		ft_putstr_fd("\033[0;31mError - Could not open file\033[00m\n", 1);
}

void	farewell(t_wireframe *data, int code)
{
	if (data)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img.img);
		mlx_destroy_display(data->mlx_ptr);
		free_wireframe_data(data);
		free(data->mlx_ptr);
		free(data);
	}
	message(code);
	exit(0);
}
