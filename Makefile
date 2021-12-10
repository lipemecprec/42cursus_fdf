NAME = fdf
CC = gcc
# FLAGS = -Wall -Wextra -Werror

LIB_FLAGS = -Llibft -lft -Lmlx_linux -lmlx -lXext -lX11 -lm -lz -g
INCLUDE = -Iinclude
LIBS = include/*.h libft/libft.a mlx_linux/libmlx.a

SRCS_PATH = ./srcs
SRCS = main.c \
		$(SRCS_PATH)/constructors.c \
		$(SRCS_PATH)/draw.c \
		$(SRCS_PATH)/line.c \
		$(SRCS_PATH)/read_wireframe.c \
		$(SRCS_PATH)/shutdown.c \
		$(SRCS_PATH)/strline.c \

all: $(NAME)

$(NAME): $(SRCS) $(LIBS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIB_FLAGS) $(INCLUDE)

$(LIBS):
	make -C libft
	make -C mlx_linux

clean:
	@make -C libft/ clean
	@make -C mlx_linux/ clean
	rm -rf $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm $(NAME)

re: fclean all

MAPS = 10-2.fdf 100-6.fdf 42.fdf basictest.fdf elem-fract.fdf elem2.fdf mars.fdf plat.fdf

MAPS2 = pylone.fdf pyramide.fdf t2.fdf 10-70.fdf 20-60.fdf 50-4.fdf elem-col.fdf elem.fdf

MAPS3 = julia.fdf pentenegpos.fdf pnp_flat.fdf pyra.fdf t1.fdf t2.fdf 

test:
	$(foreach map,$(MAPS),echo $(map) && ./$(NAME) test_maps/$(map))

test2:
	$(foreach map,$(MAPS2),echo $(map) && ./$(NAME) test_maps/$(map))

test3:
	$(foreach map,$(MAPS3),echo $(map) && ./$(NAME) test_maps/$(map))

.PHONY: all clean fclean re