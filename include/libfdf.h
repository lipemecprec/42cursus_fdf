/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:24:44 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/29 22:38:35 by faguilar         ###   ########.fr       */
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

# include "../libft/libft.h"
# include "colors.h"
# include "keys.h"

# define PI 3.14159265
# define SCR_WIDTH 1028
# define SCR_HEIGHT 720
# define BG_COLOR GREY

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

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	float	r_step;
	float	g_step;
	float	b_step;
	int		value;
}		t_color;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_image;

typedef struct s_wireframe
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	img;
	int		width;
	int		height;
	t_point	**z_grid;
	t_point	position;
	t_point	center;
	float	z_scale;
	float	zoom;
	t_angle	angle;
	t_angle	rotation_z;
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
// Create new angle and calculates sin, cos, tan
t_angle	angle(double deg);
// Split a color integer into RGB
t_color	color(int value);
// puts pixels to image
void	ft_pixel_put(t_image *img, int x, int y, int color);
void	isometric_projection(t_wireframe *data);
// Read fdf file and write data to matrix
void	read_wireframe(t_wireframe *data, char *file_name);
void	set_right_direction(t_point *bgn, t_point *end);
void	set_down_direction(t_point *bgn, t_point *end);
t_color	get_color_gradient(t_point bgn, t_point end);
void	add_color_step(t_color *bgn, t_color step);
// Simplified implementation of bresenham algorithm to draw a line
void	bresenham(t_point bgn, t_point end, t_wireframe *data);
// Function for straight lines
void	strline(t_point bgn, t_point end, t_wireframe *data);
int		deal_key(int key, t_wireframe *data);
// Draw wireframe
void	draw(t_wireframe *data);
t_point	proj(int x, int y, t_wireframe *data);
void	isometric_projection(t_wireframe *data);
void	menu_title(t_wireframe *data);
void	menu_show(t_wireframe *data);
void	*mgrant(int size);
int		farewell(t_wireframe *data, int code);
void	set_free(void *ptr);
int		open_file(char *file_name);

#endif