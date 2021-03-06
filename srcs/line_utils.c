/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:36:18 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/29 18:15:57 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	set_right_direction(t_point *bgn, t_point *end)
{
	float	temp;

	if (bgn->x > end->x)
	{
		temp = bgn->x;
		bgn->x = end->x;
		end->x = temp;
		temp = bgn->y;
		bgn->y = end->y;
		end->y = temp;
		temp = bgn->color;
		bgn->color = end->color;
		end->color = temp;
	}
}

void	set_down_direction(t_point *bgn, t_point *end)
{
	float	temp;

	if (bgn->y > end->y)
	{
		temp = bgn->x;
		bgn->x = end->x;
		end->x = temp;
		temp = bgn->y;
		bgn->y = end->y;
		end->y = temp;
		temp = bgn->color;
		bgn->color = end->color;
		end->color = temp;
	}
}

t_color	get_color_gradient(t_point bgn, t_point end)
{
	double	hypotenuse;
	t_color	bgn_c;
	t_color	end_c;
	t_color	step_c;

	hypotenuse = \
		sqrt(pow(end.x - bgn.x, 2) + pow(end.y - bgn.y, 2));
	bgn_c = color(bgn.color);
	end_c = color(end.color);
	step_c.r_step = (end_c.r - bgn_c.r) / (hypotenuse);
	step_c.g_step = (end_c.g - bgn_c.g) / (hypotenuse);
	step_c.b_step = (end_c.b - bgn_c.b) / (hypotenuse);
	return (step_c);
}

void	add_color_step(t_color *bgn, t_color step)
{
	bgn->r_step += step.r_step;
	bgn->g_step += step.g_step;
	bgn->b_step += step.b_step;
	bgn->r = bgn->r_step;
	bgn->g = bgn->g_step;
	bgn->b = bgn->b_step;
	bgn->value = bgn->r << 16 | bgn->g << 8 | bgn->b;
}

void	ft_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;
	int		img_x;
	int		img_y;
	int		offset;

	img_x = x * (img->bits_per_pixel / 8);
	img_y = y * img->line_lenght;
	if (0 < img_x && img_x < img->line_lenght)
	{
		if (0 < img_y && img_y < img->line_lenght * SCR_HEIGHT)
		{
			offset = img_x + img_y;
			dst = img->addr + offset;
			*(unsigned int *)dst = color;
		}
	}
}
