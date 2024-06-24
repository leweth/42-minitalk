CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = minitalk 


PRINTF = ./printf/libftprintf.a

LIBFT = ./libft/libft.a




$(NAME): ${LIBFT} ${PRINTF} client server 


client:
	gcc -Wall -Wextra -Werror client.c -L. -lft -lftprintf -o client 


server:
	gcc -Wall -Wextra -Werror server.c -L. -lft -lftprintf -o server 


${LIBFT}:
	cd libft && ${MAKE} && cp libft.a ../


${PRINTF}:
	cd printf && $(MAKE) && cp libftprintf.a ../


clean:
	cd printf && ${MAKE} clean && 
	cd libft && ${MAKE} clean && 


fclean:
	cd printf ; ${MAKE} fclean
	cd libft ; ${MAKE} fclean
	rm client server
	rm *.a

re: fclean ${NAME}