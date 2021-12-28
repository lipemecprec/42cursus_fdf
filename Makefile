NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB_FLAGS = -Llibft -lft -Lmlx_linux -lmlx -lXext -lX11 -lm -lz -g
INCLUDE = -Iinclude -Imlx_linux
LIBS = include/*.h libft/libft.a mlx_linux/libmlx.a

SRCS_PATH = ./srcs
SRCS = $(SRCS_PATH)/main.c \
		$(SRCS_PATH)/constructors.c \
		$(SRCS_PATH)/draw_3d.c \
		$(SRCS_PATH)/draw.c \
		$(SRCS_PATH)/keys.c \
		$(SRCS_PATH)/line_utils.c \
		$(SRCS_PATH)/line.c \
		$(SRCS_PATH)/read_wireframe.c \
		$(SRCS_PATH)/shutdown.c \
		$(SRCS_PATH)/utils.c \

all: $(NAME)

$(NAME): $(SRCS) $(LIBS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIB_FLAGS) $(INCLUDE)

$(LIBS):
	make -C libft
	make -C mlx_linux

clean:
	make -C libft/ clean
	make -C mlx_linux/ clean
	rm -rf $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re