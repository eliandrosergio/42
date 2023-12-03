
NAME = rush-02

UTILS = utils/main.c utils/ft_util.c utils/ft_rush02.c

OBJS = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror

all:	${NAME}

${NAME}: ${OBJS}
		cc -o ${NAME} ${UTILS} -Iincludes ${FLAGS}

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean