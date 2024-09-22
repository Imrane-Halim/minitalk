INC		= inc.h
FLAGS	= -Wall -Wextra -Werror
LIBFT	= ./libft/libft.a

all: client server

client: ./srcs/client.o
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) ./srcs/client.o $(LIBFT) -fsanitize=leak -I INC -o client

server: ./srcs/server.o
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) ./srcs/server.o $(LIBFT) -fsanitize=leak -I INC -o server

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) ./srcs/*.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) client server