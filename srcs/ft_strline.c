/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:56:01 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/06 22:56:18 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_strline(t_data *img, t_pair p)
{
	if (p.bgn.x == p.end.x)
	{
		while (p.bgn.y <= p.end.y)
		{
			ft_putpxl(img, p.bgn.x, p.bgn.y, p.color);
			p.bgn.y++;
		}
	}
	else if (p.bgn.y == p.end.y)
	{
		while (p.bgn.x <= p.end.x)
		{
			ft_putpxl(img, p.bgn.x, p.bgn.y, p.color);
			p.bgn.x++;
		}
	}
}
