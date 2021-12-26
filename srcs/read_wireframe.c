/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:17:43 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/26 17:50:36 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	size;
	size_t	words;

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
		else if(ft_isalnum(s[i]))
			size++;
		if (s[i] == '\0')
			break;
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
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		row++;
	}
	free(line);
	close(fd);
	return (row);
}

static int	count_col(char *file_name)
{
	int		col;
	int		fd;
	char	*line;
	char	*temp;

	fd = open(file_name, O_RDONLY, 1);
	temp = get_next_line(fd);
	line = ft_strtrim(temp, " ");
	free (temp);
	col = ft_wordcount(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (col);
}

static void	write_data(t_point *z_data, char *line)
{
	char	**nums;
	int		i;
	char	*color;
	char	*temp;

	temp = ft_strtrim(line, " \n");
	nums = ft_split(temp, ' ');
	free(temp);
	i = 0;
	while (nums[i])
	{
		z_data[i].z = ft_atoi(nums[i]);
		z_data[i].color = WHITE;
		color = ft_strrchr(nums[i], ',');
		if (color)
			z_data[i].color = ft_atohex(color);
		else if (z_data[i].z != 0)
			z_data[i].color = PINK;
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
	data->z_grid = (t_point **)malloc(sizeof(data->z_grid) * (data->height));
	i = 0;
	while (i < data->height)
		data->z_grid[i++] = (t_point *)malloc(sizeof(t_point) * (data->width));
	fd = open(file_name, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		write_data(data->z_grid[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}
