/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:17:43 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/19 03:47:25 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_count_col(int fd)
{
	char	*buf;
	int		col;
	int		flag;

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
		{
			flag = 1;
		}
		read(fd, buf, 1);
	}
	free(buf);
	if (flag == 1)
		col++;
	return (col);
}

static int	ft_count_row(int fd)
{
	char	*buf;
	int		row;

	buf = (char *)malloc(sizeof(char));
	*buf = 'x';
	row = 0;
	while (read(fd, buf, 1))
	{
		if (*buf == '\n')
		{
			row++;
		}
	}
	free(buf);
	return (row);
}

int	ft_read_map(char **file)
{
	int		fd;
	int		row;
	int		col;

	fd = open(*file, O_RDWR);
	close(fd);
	fd = open(*file, O_RDWR);
	close(fd);
	return (0);
}

int	main(void)
{
	char	*file;

	file = "test_maps/42.fdf";
	ft_read_map(&file);
	file = "test_maps/10-2.fdf";
	ft_read_map(&file);
	file = "test_maps/t2.fdf";
	ft_read_map(&file);
	return (0);
}
