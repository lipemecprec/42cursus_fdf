/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:27:22 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/04 21:29:27 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	free_wireframe_data(t_wireframe *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
		free(data->z_grid[i++]);
	free(data->z_grid);
}
