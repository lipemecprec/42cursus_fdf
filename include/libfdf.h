/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:24:44 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/07 22:56:44 by faguilar         ###   ########.fr       */
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
# define SCR_WIDTH 2560
# define SCR_HEIGHT 1200
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

typedef struct	s_wireframe
{
	int		width;
	int		height;
	t_point	**z_grid;
	int		zoom;
	t_angle	angle;
	int		z_scale;
	t_point	position;
	t_point	center;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_wireframe;

// Create new point
t_point	point(float x, float y, float z, int color);
// Create new angle
t_angle	angle(double deg);
// Read fdf file and write data to matrix
void	read_wireframe(t_wireframe *data, char *file_name);
// Simplified implementation of bresenham algorithm to draw a line
void	bresenham(t_point bgn, t_point end, t_wireframe *data);
// Function for straight lines
void	strline(t_point bgn, t_point end, t_wireframe *data);
// Draw wireframe
void	draw(t_wireframe *data);
void	shutdown(t_wireframe *data);



#endif