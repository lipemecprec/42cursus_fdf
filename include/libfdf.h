/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:24:44 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/26 17:50:33 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H

# include "mlx.h"
# include <math.h>
# include <sys/types.h> // open
# include <sys/stat.h> // open
# include <fcntl.h>  // open
# include <unistd.h> // read, write, close
# include <stdlib.h> // malloc, free, exit
# include <stdio.h> // perror
# include <string.h> // strerror

# include "../libft/libft.h"
# include "colors.h"
# include "keys.h"

# define PI 3.14159265
# define SCR_WIDTH 1024
# define SCR_HEIGHT 1024
# define IMG_WIDTH 1024
# define IMG_HEIGHT 1024

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
	int		color;
}				t_point;

typedef struct s_angle {
	float	deg;
	float	rad;
	float	sin;
	float	cos;
	float	tan;
}				t_angle;

typedef struct s_wireframe
{
	int		width;
	int		height;
	t_point	**z_grid;
	t_point	position;
	t_point	center;
	int		z_scale;
	int		zoom;
	t_angle	angle;
	t_angle	rotation_x;
	t_angle	rotation_y;
	t_angle	rotation_z;
	void	*mlx_ptr;
	void	*win_ptr;
	int		up;
}				t_wireframe;

typedef struct s_bresenham {
	int		ddx;
	int		ddy;
	int		step;
	int		pz;
	char	axis;
}				t_bresenham;

// Create new point
t_point	point(float x, float y, float z, int color);
// Create new angle
t_angle	angle(double deg);
void	isometric_projection(t_wireframe *data);
// Read fdf file and write data to matrix
void	read_wireframe(t_wireframe *data, char *file_name);
void	set_right_direction(float *x1, float *y1, float *x2, float *y2);
void	set_down_direction(float *x1, float *y1, float *x2, float *y2);
t_color	get_color_gradient(t_point bgn, t_point end);
// Simplified implementation of bresenham algorithm to draw a line
void	bresenham(t_point bgn, t_point end, t_wireframe *data);
// Function for straight lines
void	strline(t_point bgn, t_point end, t_wireframe *data);
int		deal_key(int key, t_wireframe *data);
// Draw wireframe
void	draw(t_wireframe *data);
void	tridimensional(t_point *point, t_wireframe *data);
void	rotation_z(t_point *point, t_wireframe *data);
void	rotation_y(t_point *point, t_wireframe *data);
void	rotation_x(t_point *point, t_wireframe *data);
void	isometric_projection(t_wireframe *data);
void	farewell(t_wireframe *data, int code);
void	set_free(void *ptr);
void	free_wireframe_data(t_wireframe *data);

#endif