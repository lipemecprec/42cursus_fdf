NAME = fdf
CC = gcc
# FLAGS = -Wall -Wextra -Werror

LIB_FLAGS = -Llibft -lft -Lmlx_linux -lmlx -lXext -lX11 -lm -lz
INCLUDE = -Iinclude
LIBS = libft/libft.a mlx_linux/libmlx.a

SRCS_PATH = ./srcs
SRCS = main.c \
		$(SRCS_PATH)/constructors.c \
		$(SRCS_PATH)/ft_draw.c \
		$(SRCS_PATH)/ft_line.c \
		$(SRCS_PATH)/ft_putpxl.c \
		$(SRCS_PATH)/ft_read_wireframe.c \
		$(SRCS_PATH)/ft_strline.c

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

.PHONY: all clean fclean re