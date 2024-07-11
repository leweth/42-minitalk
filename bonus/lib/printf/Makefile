CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf_bonus.c ft_putchar_bonus.c ft_putstr_bonus.c ft_putpercent_bonus.c ft_putaddress_bonus.c ft_puthexa_bonus.c \
ft_puthexa_Xup_bonus.c ft_puthexa_x_bonus.c ft_putint_bonus.c ft_putunint_bonus.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a


%.o: %.c ft_printf_bonus.h
	${CC} ${CFLAGS} -c $< -o $@


${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all