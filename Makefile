CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = minitalk 


PRINTF = ./lib/printf/libftprintf.a

LIBFT = ./lib/libft/libft.a




$(NAME): ${LIBFT} ${PRINTF} client server 


client:
	gcc -Wall -Wextra -Werror client.c -L. -lft -lftprintf -o client 


server:
	gcc -Wall -Wextra -Werror server.c -L. -lft -lftprintf -o server 


${LIBFT}:
	cd lib/libft && ${MAKE} && cp libft.a ../../


${PRINTF}:
	cd lib/printf && $(MAKE) && cp libftprintf.a ../../


clean:
	cd lib/printf && ${MAKE} clean && 
	cd lib/libft && ${MAKE} clean && 


fclean:
	cd lib/printf ; ${MAKE} fclean
	cd lib/libft ; ${MAKE} fclean
	rm client server
	rm *.a

re: fclean ${NAME}