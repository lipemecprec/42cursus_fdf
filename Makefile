CC=gcc
NAME=fdf.a
FLAGS=-Wall -Wextra -Werror
INCLUDE=-I/usr/include -Imlx_linux -O3
LIBS=-Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# LIBS=-Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) main.c
	$(CC) main.c $(LIBS) -o $(NAME) && ./$(NAME)