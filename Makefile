NAME = minitalk.a

SRCS = \
	server.c client.c
	
AR = ar rcs

OBJ = $(SRCS:.c=.o)
CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) server client

$(NAME): $(OBJ) $(LIBFT)
	$(AR) $(NAME) $(OBJ)

server: $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o server server.o $(LIBFT)

client: $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o client client.o $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	cd $(LIBFT_DIR) && $(MAKE)

clean:
	$(RM) $(OBJ) $(SERVER_OBJ) $(CLIENT_OBJ)
	cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME) server client
	cd $(LIBFT_DIR) && $(MAKE) fclean
	
re: fclean all

.PHONY: all server client clean fclean re
