/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:17:43 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/21 20:29:49 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	count_col(char *file)
{
	char	*buf;
	int		col;
	int		flag;

	fd = open(*file, O_RDONLY);
	buf = (char *)malloc(sizeof(char));
	read(fd, buf, 1);
	col = 0;
	flag = 0;
	while (*buf != '\n')
	{
		if (*buf == ' ' && flag == 1)
		{
			col++;
			flag = 0;
		}
		else
			flag = 1;
		read(fd, buf, 1);
	}
	free(buf);
	close(fd);
	if (flag == 1)
		col++;
	return (col);
}

static int	count_row(char *file)
{
	char	*buf;
	int		row;
	int		fd;

	fd = open(*file, O_RDONLY);
	buf = (char *)malloc(sizeof(char));
	*buf = NULL;
	row = 0;
	while (read(fd, buf, 1))
	{
		if (*buf == '\n')
		{
			row++;
		}
	}
	free(buf);
	close(fd);
	return (row);
}

void	write_data(char *file, t_wireframe *data)
{
	char	*buf;
	int		row;
	int		fd;

	fd = open(*file, O_RDONLY);
}

int	ft_read_wireframe(char *file, t_wireframe *data)
{
	int	fd;
	int	row;
	int	col;
	int i;

	data->h = count_row(file);
	data->w = count_col(file);
	data->z_grid = (int **)malloc(sizeof(int *) * (data->h + 1));
	i = 0;
	while(i < data->h)
		data->z_grid[i] = (int *)malloc(sizeof(int) * (data->w + 1));
	write_data(file, data);
	return (0);
}
