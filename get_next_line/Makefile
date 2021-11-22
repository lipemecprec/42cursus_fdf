CC = clang
FLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libgnl.a 
LIB = get_next_line.h
SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:%.c=%.o}

SIZE = 32

all: ${NAME}

${NAME}: ${OBJS} ${LIB}
	ar rc ${NAME} ${OBJS}

${OBJS}:
	${CC} -I . -c ${FLAGS} ${SRCS} 

clean:
	@${RM} ${OBJS} ${BONUSOBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re run
