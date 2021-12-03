/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:23:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/03 15:51:39 by faguilar         ###   ########.fr       */
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

static t_screen init_screen(char *file_name, void *mlx_ptr, t_wireframe	*data)
{
	t_screen	scr;
	char 		*title;

	title = ft_strjoin("FDF - ", file_name);
	write(1, "mlx_new_window\n", 16);
	scr.mlx_win = mlx_new_window(mlx_ptr, SCR_HEIGHT, SCR_WIDTH, title);
	write(1, "mlx_new_image \n", 16);
	scr.img = mlx_new_image(mlx_ptr, IMG_HEIGHT, IMG_WIDTH);
	write(1, "mlx_get_data_a\n", 16);
	scr.addr = mlx_get_data_addr(scr.img, &scr.bits_per_pixel, &scr.line_length,
								&scr.endian);
	write(1, "ft_draw       \n", 16);
	ft_draw(&scr, data);
	write(1, "ft_print_data \n", 16);
	ft_print_data(data); // debug
	write(1, "mlx_put_image \n", 16);
	mlx_put_image_to_window(mlx_ptr, scr.mlx_win, scr.img, 0, 0);
	return (scr);
}

static t_wireframe	*init_wireframe(char *file_name)
{
	t_wireframe	*data;

	write(1, "init wireframe\n", 16);
	data = (t_wireframe *)malloc(sizeof(t_wireframe));
	data->zoom = 50;
	ft_read_wireframe(data, file_name);

	return (data);
}

int	main(int argc, char **argv)
{
	t_wireframe	*data;
	t_screen	scr;
	void		*mlx_ptr;
	t_angle		ang;

	if (argc != 2)
		return(1);
	data = init_wireframe(argv[1]);
	write(1, "mlx_init      \n", 16);
	mlx_ptr = mlx_init();
	printf("mlx_ptr: %p \n", mlx_init());
	scr = init_screen(argv[1], mlx_ptr, data);
	write(1, "mlx_key_hook  \n", 16);
	mlx_key_hook(scr.mlx_win, deal_key, data);
	// mlx_expose_hook(scr.mlx_win, &deal_key, &scr);
	write(1, "mlx_loop       \n", 16);
	mlx_loop(mlx_ptr);
	write(1, "end            \n", 16);
	// mlx_clear_window(&mlx, &scr.mlx_win);
	// mlx_destroy_window(&mlx, &scr.mlx_win);

}
