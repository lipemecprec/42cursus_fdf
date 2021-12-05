/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:17:43 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/04 22:36:46 by faguilar         ###   ########.fr       */
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

static int	count_col(char *file)
{
	int		col;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	col = ft_wordcount(line, ' ');
	free(line);
	close(fd);
	return (col);
}

static int	count_row(char *file)
{
	int		row;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		row++;
		free(line);
	}
	close(fd);
	return (row);
}

static void	write_data(char *file, t_wireframe *data)
{
	int		fd;
	char	*line;
	char	**nums;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	i = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		nums = ft_split(line, ' ');
		j = 0;
		while (nums[j])
		{
			data->grid[i][j].z = ft_atoi(nums[j]);
			if(ft_strrchr(nums[j], ','))
				printf("%s\t", nums[j]);
			free(nums[j++]);
		}
		i++;
		free(nums);
		free(line);
	}
	close(fd);
}

int	ft_read_wireframe(t_wireframe *data, char *file)
{
	int i;

	data->height = count_row(file);
	data->width = count_col(file);
	data->grid = (t_coord **)malloc(sizeof(t_coord *) * (data->height + 1));
	i = 0;
	while(i <= data->height)
		data->grid[i++] = (t_coord *)malloc(sizeof(t_coord) * (data->width + 1));
	write_data(file, data);
	data->grid[data->height]=NULL;
	return (0);
}
