CC = gcc
NAME = fdf.a
FLAGS = -Wall -Wextra -Werror

LIB_PATH = -I ./include
LIBS = -Lmlx_linux -Llibft -Lget_next_line -lmlx -L/usr/lib -lXext -lX11 -lm -lz
INCLUDE = -I/usr/include -Imlx_linux -Ilibft -Iget_next_line $(LIB_PATH) -O3

SRCS_PATH = ./srcs
SRCS = \
		$(SRCS_PATH)/constructors.c \
		$(SRCS_PATH)/ft_line.c \
		$(SRCS_PATH)/ft_putpxl.c \
		$(SRCS_PATH)/ft_strline.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) main.c
	# @make -C libft
	# @make -C get_next_line
	# @make -C mlx_linux
	$(CC) main.c $(SRCS) $(LIBS) $(INCLUDE) -o $(NAME)

.c.o:
	$(CC) -c $(FLAGS) $< -o $(<:.c=.o) $(INCLUDE)

clean:
	# @make -C libft/ clean
	# @make -C get_next_line/ clean
	# @make -C mlx_linux/ clean
	rm -rf $(OBJS)

fclean: clean
	# @make -C libft/ fclean
	rm $(NAME)

re: fclean all

run: fclean $(OBJS) main.c
	$(CC) main.c $(SRCS) $(LIBS) $(INCLUDE) -o $(NAME) && ./$(NAME)

.PHONY: $(NAME), all, clean, fclean, re