NAME = fdf
CC = clang
# FLAGS = -Wall -Wextra -Werror

LIBS = -Llibft -lft -Lmlx_linux -lmlx -lXext -lX11 -lm -lz
INCLUDE = -Iinclude

SRCS_PATH = ./srcs
SRCS = main.c \
		$(SRCS_PATH)/constructors.c \
		$(SRCS_PATH)/ft_draw.c \
		$(SRCS_PATH)/ft_line.c \
		$(SRCS_PATH)/ft_putpxl.c \
		$(SRCS_PATH)/ft_read_wireframe.c \
		$(SRCS_PATH)/ft_strline.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIBS) $(INCLUDE)

libs:
	make -C libft
	make -C mlx_linux

clean:
	# @make -C libft/ clean
	# @make -C mlx_linux/ clean
	rm -rf $(OBJS)

fclean: clean
	# @make -C libft/ fclean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re