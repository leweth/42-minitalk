CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi_bonus.c ft_strlen_bonus.c send_data_bonus.c ft_calloc_bonus.c ft_bzero_bonus.c general_utils_bonus.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a


%.o: %.c libft_bonus.h
	${CC} ${CFLAGS} -c $< -o $@


${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
