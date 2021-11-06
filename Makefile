CC = gcc
NAME = fdf.a
FLAGS = -Wall -Wextra -Werror

LIB_PATH = ./include
LIBS = -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
# LIBS = -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
INCLUDE = -I/usr/include -Imlx_linux -I $(LIB_PATH) -O3

SRCS_PATH = ./srcs
SRCS = $(SRCS_PATH)/ft_putpxl.c \
		$(SRCS_PATH)/constructors.c \
		$(SRCS_PATH)/ft_line.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) main.c
	$(CC) main.c $(SRCS) $(LIBS) $(INCLUDE) -o $(NAME)

.c.o:
	$(CC) -c $(FLAGS) $< -o $(<:.c=.o) $(INCLUDE)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

run: fclean $(OBJS) main.c
	$(CC) main.c $(SRCS) $(LIBS) $(INCLUDE) -o $(NAME) && ./$(NAME)