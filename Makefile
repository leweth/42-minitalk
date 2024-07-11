CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = minitalk

PRINTF = lib/printf/libftprintf.a

LIBFT = lib/libft/libft.a



$(NAME): ${LIBFT} ${PRINTF} client server 
	@echo "\033[1;33mBuilding targets...\033[0m"
	gcc -Wall -Wextra -Werror mandatory/client.c -L"mandatory/lib/libft" -lft -L"mandatory/lib/printf" -lftprintf -o client 
	gcc -Wall -Wextra -Werror mandatory/server.c -L"mandatory/lib/libft" -lft -L"mandatory/lib/printf" -lftprintf -o server
	@echo "\033[1;32mTargets Built Successfully!\033[0m"

bonus: ${LIBFT} ${PRINTF} client_bonus server_bonus
	@echo "\033[1;33mBuilding targets for bonus...\033[0m"
	gcc -Wall -Wextra -Werror bonus/client_bonus.c -L"bonus/lib/libft" -lft -L"bonus/lib/printf" -lftprintf -o client_bonus 
	gcc -Wall -Wextra -Werror bonus/server_bonus.c -L"bonus/lib/libft" -lft -L"bonus/lib/printf" -lftprintf -o server_bonus	 
	@echo "\033[1;32mTargets Built Successfully!\033[0m"


${LIBFT}:
	@echo "\033[1;33mBuilding Libft...\033[0m"
	cd mandatory/lib/libft && ${MAKE}
	cd bonus/lib/libft && ${MAKE}


${PRINTF}:
	@echo "\033[1;33mBuilding Printf...\033[0m"
	cd mandatory/lib/printf && $(MAKE)
	cd bonus/lib/printf && $(MAKE)


clean:
	@echo "\033[1;33mRemoving dependencies...\033[0m"
	cd mandatory/lib/printf && ${MAKE} clean
	cd mandatory/lib/libft && ${MAKE} clean
	cd bonus/lib/printf && ${MAKE} clean
	cd bonus/lib/libft && ${MAKE} clean  


fclean:
	cd mandatory/lib/printf ; ${MAKE} fclean
	cd mandatory/lib/libft ; ${MAKE} fclean
	cd bonus/lib/printf && ${MAKE} fclean
	cd bonus/lib/libft && ${MAKE} fclean
	@echo "\033[1;33mBuilding targets...\033[0m"
	-rm client server
	-rm client_bonus server_bonus
	@echo "\033[1;32mFiles were cleaned Successfully!\033[0m"

re: fclean ${NAME}

.PHONY: client server client_bonus server_bonus