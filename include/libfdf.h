/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:28:03 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/23 22:51:03 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H

# define LIBFDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <sys/types.h> // open
# include <sys/stat.h> // open
# include <fcntl.h>  // open
# include <unistd.h> // read, write, close
# include <stdlib.h> // malloc, free, exit
# include <stdio.h> // perror
# include <string.h> // strerror

# define PI 3.14159265

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_coord {
	int	x;
	int	y;
	int	z;
}				t_coord;

typedef struct s_proj {
	int	x;
	int	y;
}				t_proj;

typedef struct s_pair {
	t_coord	bgn;
	t_coord	end;
	int		color;
}				t_pair;

typedef struct s_angle {
	double	deg;
	double	rad;
	double	sin;
	double	cos;
	double	tan;
}				t_angle;

typedef struct s_wireframe {
	int	height;
	int	width;
	int	**z_grid;
}				t_wireframe;

enum e_colors{
	BLACK = 0x00000000,
	WHITE = 0x00FFFFFF,
	RED = 0x00FF0000,
	LIME = 0x0000FF00,
	BLUE = 0x000000FF,
	YELLOW = 0x00FFF000,
	CYAN = 0x0000FFFF,
	FUCHSIA = 0x00FF00FF,
	SILVER = 0x00C0C0C0,
	GREY = 0x00333333,
	GREEN = 0x00008000,
	PURPLE = 0x00800080,
	TEAL = 0x0008080
};

int		ft_read_wireframe(char *file, t_wireframe *data);
void	ft_putpxl(t_data *data, int x, int y, int color);
t_coord	new_coord(int x, int y, int z);
t_pair	new_pair(t_coord bgn, t_coord end, int color);
t_angle	new_angle(double deg);
t_coord new_proj(int x, int y, int z, t_angle a);
void	ft_line(t_data *img, t_pair p);
void	ft_strline(t_data *img, t_pair p);

#endif