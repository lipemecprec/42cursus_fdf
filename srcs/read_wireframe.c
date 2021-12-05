/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:17:43 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/04 21:27:36 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	size;
	int	words;

	i = 0;
	words = 0;
	size = 0;
	while (1)
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (size > 0)
			{
				words++;
				size = 0;
			}
		}
		else
			size++;
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (words);
}

static int	count_row(char *file_name)
{
	int		row;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		row++;
		free(line);
	}
	close(fd);
	return (row);
}

static int	count_col(char *file_name)
{
	int		col;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	col = ft_wordcount(line, ' ');
	free(line);
	close(fd);
	return (col);
}

static void	write_data(int *z_data, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_data[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_wireframe(t_wireframe *data, char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	data->height = count_row(file_name);
	data->width = count_col(file_name);
	data->z_grid = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_grid[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		write_data(data->z_grid[i++], line);
		free(line);
	}
	data->z_grid[data->height] = NULL;
	close (fd);
}
