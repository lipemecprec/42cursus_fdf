/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:28:03 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/03 15:12:39 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H

# define LIBFDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include "colors.h"
# include "keys.h"
# include <math.h>
# include <sys/types.h> // open
# include <sys/stat.h> // open
# include <fcntl.h>  // open
# include <unistd.h> // read, write, close
# include <stdlib.h> // malloc, free, exit
# include <stdio.h> // perror
# include <string.h> // strerror

# define PI 3.14159265
# define SCR_WIDTH 1024
# define SCR_HEIGHT 1024
# define IMG_WIDTH 1024
# define IMG_HEIGHT 1024

typedef struct s_coord {
	float	x;
	float	y;
	int		z;
	int		color;
}				t_coord;

typedef struct s_pair {
	t_coord	bgn;
	t_coord	end;
	int		color;
}				t_pair;

typedef struct s_angle {
	float	deg;
	float	rad;
	float	sin;
	float	cos;
	float	tan;
}				t_angle;

typedef struct s_screen {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	char	*mlx_win;
}				t_screen;

typedef struct s_wireframe {
	int		height;
	int		width;
	t_coord	**grid;
	int		zoom;
	t_coord	position;
	t_angle	angle;
}				t_wireframe;

typedef struct s_proj {
	int	x;
	int	y;
}				t_proj;

int		ft_read_wireframe(t_wireframe *data, char *file);
void	ft_putpxl(t_screen *data, int x, int y, int color);
t_coord	new_coord(int x, int y, int z);
t_pair	new_pair(t_coord bgn, t_coord end, int color);
t_pair	new_line(float x, float y, float x1, float y1);
t_pair	proj(t_pair *line, t_screen *img, t_wireframe *data);
void	perspective(float *x, float *y, int z, t_angle ang);
void	offset(float *x, float *y, int offset_x, int offset_y);
t_angle	new_angle(double deg);
t_coord new_proj(int x, int y, int z, t_angle a);
void	ft_line(t_screen *img, t_pair p);
void	ft_strline(t_screen *img, t_pair p);
void	ft_draw(t_screen *img, t_wireframe *data);

#endif