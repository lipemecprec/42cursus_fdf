#include "libft.h"

void	e_sqr(t_screen *img, t_pair p)
{
	t_pair	top;
	t_pair	bot;
	t_pair	lft;
	t_pair	rgt;

	top = new_pair(new_coord(p.bgn.x, p.bgn.y, 0), new_coord(p.bgn.x, p.end.y, 0), p.color);
	bot = new_pair(new_coord(p.bgn.x, p.bgn.y, 0), new_coord(p.end.x, p.bgn.y, 0), p.color);
	lft = new_pair(new_coord(p.end.x, p.end.y, 0), new_coord(p.end.x, p.bgn.y, 0), p.color);
	rgt = new_pair(new_coord(p.end.x, p.end.y, 0), new_coord( p.bgn.x, p.end.y, 0),p.color);
	ft_line(img, top);
	ft_line(img, bot);
	ft_line(img, lft);
	ft_line(img, rgt);
}

t_coord	ft_rotate(t_angle ang, t_coord p)
{
	t_coord rotated;

	rotated.x = (int)(floor(p.x * ang.cos) + floor(p.y * ang.sin));
	rotated.y = (int)(floor(-p.x * ang.sin) + floor(p.y * ang.cos));
	return (rotated);
}

void	ft_grid(t_screen *img, t_pair v, t_angle ang, int d)
{
	int y0;
	t_coord	bgn;
	t_coord	end;
	t_pair	line;
	t_angle persp = new_angle(15);

	while (v.bgn.x <= v.end.x)
	{
		y0 = v.bgn.y;
		while (y0 <= v.end.y)
		{
			if (y0 < v.end.y)
			{
				bgn = ft_rotate(ang, new_coord(v.bgn.x, y0 , 0));
				end = ft_rotate(ang, new_coord(v.bgn.x, y0 + d, 0));
				// line = new_pair(bgn, end, GREY);
				// ft_line(img, line);
				bgn = new_proj(bgn.x, bgn.y, bgn.z, persp);
				end = new_proj(end.x, end.y, end.z, persp);
				line = new_pair(bgn, end, LIME);
				ft_line(img, line);
			}
			if (v.bgn.x < v.end.x)
			{
				bgn = ft_rotate(ang, new_coord(v.bgn.x, y0, 0));
				end = ft_rotate(ang, new_coord(v.bgn.x + d, y0, 0));
				// line = new_pair(bgn, end, GREY);
				// ft_line(img, line);
				bgn = new_proj(bgn.x, bgn.y, bgn.z, persp);
				end = new_proj(end.x, end.y, end.z, persp);
				line = new_pair(bgn, end, LIME);
				ft_line(img, line);
			}
			y0 += d;
		}
		v.bgn.x += d;
	}
}
