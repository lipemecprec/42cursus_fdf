/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:23:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/02 11:31:56 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h" 

static void ft_print_data(t_wireframe *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->grid[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	deal_key(int key, t_wireframe *scr)
{
	write(1, ft_itoa(key), 4);
	if(key == KEY_ESC)
		return (1);
	else if (key == KEY_W)
		return (0);
	return (0);
}

int	main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_screen	scr;
	t_wireframe	*data;
	t_angle		ang;

	// if (argc != 2)
	// 	return(1);
	data = (t_wireframe *)malloc(sizeof(t_wireframe));
	ft_read_wireframe(data, argv[1]);
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1024, 1024, "FDF");
	scr.img = mlx_new_image(mlx_ptr, 4000, 4000);
	data->zoom = 50;
	scr.addr = mlx_get_data_addr(scr.img, &scr.bits_per_pixel, &scr.line_length,
								&scr.endian);
	ft_draw(&scr, data);
	ft_print_data(data); // debug
	mlx_put_image_to_window(mlx_ptr, mlx_win, scr.img, 0, 0);
	mlx_key_hook(mlx_win, deal_key, data);
	// mlx_expose_hook(mlx_win, &deal_key, &scr);
	mlx_loop(mlx_ptr);
	// mlx_clear_window(&mlx, &mlx_win);
	// mlx_destroy_window(&mlx, &mlx_win);

}
