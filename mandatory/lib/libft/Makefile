CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_strlen.c send_data.c ft_calloc.c ft_bzero.c general_utils.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a


%.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@


${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
