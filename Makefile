CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBRARY = libminitalk.a
SRC = server.c client.c
SRCB = server_bonus.c client_bonus.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
AR = ar rcs

all: server client

server: server.c $(LIBRARY)
	$(CC) $(CFLAGS) -o server server.c -L. -lminitalk -Llibft -lft

client: client.c $(LIBRARY)
	$(CC) $(CFLAGS) -o client client.c -L. -lminitalk -Llibft -lft
 
$(LIBRARY): $(OBJ)
	@cd libft && $(MAKE)
	$(AR) $(LIBRARY) $(OBJ)

bonus: server_bonus client_bonus

server_bonus: server_bonus.c $(LIBRARY)
	$(CC) $(CFLAGS) -o server_bonus server_bonus.c -L. -lminitalk -Llibft -lft

client_bonus: client_bonus.c $(LIBRARY)
	$(CC) $(CFLAGS) -o client_bonus client_bonus.c -L. -lminitalk -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f server client server_bonus client_bonus $(OBJ) $(OBJB)
	@cd libft && $(MAKE) clean

fclean: clean
	rm -f $(LIBRARY)
	@cd libft && $(MAKE) fclean

re: fclean all

NAME: all