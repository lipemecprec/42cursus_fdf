/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:23:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/02 14:37:39 by faguilar         ###   ########.fr       */
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
	write(2, ft_itoa(key), 4);
	if(key == KEY_ESC)
		return (1);
	else if (key == KEY_W)
		return (0);
	return (0);
}

// t_screen init_screen(t_screen **scr)
// {
// 	write(2, "init screeen\n", 14);
// 	write(2, "4", 1);
// 	*scr->mlx_ptr = mlx_init();
// 	write(2, "5", 1);
// 	scr->win_ptr = mlx_new_window(mlx_ptr, 1024, 1024, "FDF");
// 	write(2, "6", 1);
// 	scr.img = mlx_new_image(mlx_ptr, 4000, 4000);
// 	write(2, "7", 1);
// 	scr.addr = mlx_get_data_addr(scr.img, &scr.bits_per_pixel, &scr.line_length,
// 								&scr.endian);
// }

t_wireframe	*init_wireframe(char *file)
{
	t_wireframe	*data;

	write(2, "init wireframe\n", 16);
	data = (t_wireframe *)malloc(sizeof(t_wireframe));
	data->zoom = 50;
	ft_read_wireframe(data, file);

	return (data);
}

int	main(int argc, char **argv)
{
	t_wireframe	*data;
	t_screen	scr;
	void		*mlx_ptr;
	void		*mlx_win;
	t_angle		ang;

	if (argc != 2)
		return(1);
	data = init_wireframe(argv[1]);
	// data = (t_wireframe *)malloc(sizeof(t_wireframe));
	// ft_read_wireframe(data, argv[1]);
	// init_screen(&scr, argv[1]);
	write(2, "4", 1);
	mlx_ptr = mlx_init();
	write(2, "5", 1);
	mlx_win = mlx_new_window(mlx_ptr, SCR_HEIGHT, SCR_WIDTH, "FDF");
	write(2, "6", 1);
	scr.img = mlx_new_image(mlx_ptr, IMG_HEIGHT, IMG_WIDTH);
	write(2, "7", 1);
	write(2, "8", 1);
	scr.addr = mlx_get_data_addr(scr.img, &scr.bits_per_pixel, &scr.line_length,
								&scr.endian);
	write(2, "9", 1);
	ft_draw(&scr, data);
	write(2, "10", 2);
	ft_print_data(data); // debug
	write(2, "11", 2);
	mlx_put_image_to_window(mlx_ptr, mlx_win, scr.img, 0, 0);
	write(2, "12", 2);
	mlx_key_hook(mlx_win, deal_key, data);
	write(2, "13", 2);
	// mlx_expose_hook(mlx_win, &deal_key, &scr);
	mlx_loop(mlx_ptr);
	write(2, "14", 2);
	// mlx_clear_window(&mlx, &mlx_win);
	// mlx_destroy_window(&mlx, &mlx_win);

}
