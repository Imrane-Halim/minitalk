INC		= inc.h
FLAGS	= -Wall -Wextra -Werror
LIBFT	= ./libft/libft.a
PRINTF	= ./libft/printf/libftprintf.a

all: client server

client: ./src/client.o ./src/utils.o
	$(MAKE) -C ./libft
	$(MAKE) -C ./libft/printf
	$(CC) $(FLAGS) ./src/client.o ./src/utils.o $(LIBFT) $(PRINTF) -o client

server: ./src/server.o ./src/utils.o
	$(MAKE) -C ./libft
	$(MAKE) -C ./libft/printf
	$(CC) $(FLAGS) ./src/server.o ./src/utils.o $(LIBFT) $(PRINTF) -o server

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./libft/printf
	$(RM) ./src/*.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./libft/printf
	$(RM) client server