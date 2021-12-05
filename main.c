/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:23:11 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/04 17:16:32 by faguilar         ###   ########.fr       */
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

void shutdown(void *mlx_ptr, void *win_ptr)
{
	mlx_clear_window(mlx_ptr, win_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_loop_end(mlx_ptr);
} 

int	deal_key(int key, t_screen *scr)
{
	// write(2, ft_itoa(key), 4);
	if(key == KEY_ESC)
		shutdown(scr->mlx_ptr, scr->mlx_win);
	else if (key == KEY_W)
		scr->data->position.x += 10;
	// mlx_clear_window(scr->mlx_ptr, scr->mlx_win);
	ft_render(scr, scr->data);
	return (0);
}

static t_screen *init_screen(char *file_name, void *mlx_ptr, t_wireframe *data)
{
	t_screen	*scr;
	char 		*title;
	void		*mlx_win;

	scr->mlx_ptr = mlx_ptr;
	scr->data = data;
	title = ft_strjoin("FDF - ", file_name);
	write(1, "mlx_new_window\n", 16);
	mlx_win = mlx_new_window(scr->mlx_ptr, SCR_HEIGHT, SCR_WIDTH, title);
	scr->mlx_win = mlx_win;
	write(1, "mlx_new_image \n", 16);
	scr->img = mlx_new_image(mlx_ptr, IMG_HEIGHT, IMG_WIDTH);
	write(1, "mlx_get_data_a\n", 16);
	scr->addr = mlx_get_data_addr(scr->img, &scr->bits_per_pixel, 
								&scr->line_length, &scr->endian);
	write(1, "ft_draw       \n", 16);
	ft_draw(scr, data);
	write(1, "ft_print_data \n", 16);
	ft_print_data(data); // debug
	write(1, "mlx_put_image \n", 16);
	mlx_put_image_to_window(scr->mlx_ptr, scr->mlx_win, scr->img, 0, 0);
	return (scr);
}

static t_wireframe	*init_wireframe(char *file_name)
{
	t_wireframe	*data;

	write(1, "init wireframe\n", 16);
	data = (t_wireframe *)malloc(sizeof(t_wireframe));
	data->zoom = 30;
	data->angle = new_angle(45);
	data->position = new_coord(200, 150, 0);
	ft_read_wireframe(data, file_name);

	return (data);
}

int	main(int argc, char **argv)
{
	t_wireframe	*data;
	t_screen	*scr;
	void		*mlx_ptr;
	t_angle		ang;

	if (argc != 2)
		return(1);
	data = init_wireframe(argv[1]);
	mlx_ptr = mlx_init();
	scr = init_screen(argv[1], mlx_ptr, data);
	write(1, "mlx_key_hook  \n", 16);
	mlx_key_hook(scr->mlx_win, deal_key, &scr);
	mlx_clear_window(scr->mlx_ptr, scr->mlx_win);
	// mlx_expose_hook(scr.mlx_win, &deal_key, &scr);
	write(1, "mlx_loop       \n", 16);
	mlx_loop(scr->mlx_ptr);
	write(1, "end            \n", 16);
	free(data);
	return (0);
}
