CC=gcc
NAME=fdf.a
FLAGS=-Wall -Wextra -Werror

LIB_PATH = ./include
INCLUDE=-I/usr/include -Imlx_linux -I ${LIB_PATH} -O3
LIBS=-Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# LIBS=-Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

.o.c:
	${CC} -c ${FLAGS} $< -o ${<:.c=.o} ${INCLUDE}

$(NAME): $(OBJ) main.c
	$(CC) main.c $(LIBS) ${INCLUDE} -o $(NAME) && ./$(NAME)