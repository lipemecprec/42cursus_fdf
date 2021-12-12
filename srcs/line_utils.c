/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:36:18 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/12 12:31:33 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	set_right_direction(float *x1, float *y1, float *x2, float *y2)
{
	float	temp;

	if (*x1 > *x2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
		temp = *y1;
		*y1 = *y2;
		*y2 = temp;
	}
}

void	set_down_direction(float *x1, float *y1, float *x2, float *y2)
{
	float	temp;

	if (*y1 > *y2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
		temp = *y1;
		*y1 = *y2;
		*y2 = temp;
	}
}

t_color	get_color_gradient(t_point bgn, t_point end)
{
	double	hypotenuse;
	t_color	bgn_c;
	t_color	end_c;
	t_color	step_c;

	hypotenuse = \
		sqrt(pow(fabs(end.x - bgn.x), 2) + pow(fabs(end.y - bgn.y), 2));
	bgn_c = color(bgn.color);
	end_c = color(end.color);
	step_c.r_step = (end_c.r - bgn_c.r) / (hypotenuse);
	step_c.g_step = (end_c.g - bgn_c.g) / (hypotenuse);
	step_c.b_step = (end_c.b - bgn_c.b) / (hypotenuse);
	return (step_c);
}

int	add_color_step(int bgn, t_color step)
{
	bgn += step.r_step * pow(256, 2);
	bgn += step.g_step * 256;
	bgn += step.b_step;
	return (bgn);
}