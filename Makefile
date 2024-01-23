NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c

OBJ_SERVER = $(SRCS_SERVER:.c=.o)
OBJ_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

LIBFT_DIR = libft
LIBFT_TARGET = $(LIBFT_DIR)/libft.a


all: libft $(NAME_SERVER) $(NAME_CLIENT)

bonus: libft $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

build: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) $(NAME_CLIENT): % : %.o
	$(CC) $(CFLAGS) -o $@ $< $(LIBFT_TARGET)

$(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS): % : %.o
	$(CC) $(CFLAGS) -o $@ $< $(LIBFT_TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_DIR)

libft:
	@cd $(LIBFT_DIR) && $(MAKE)

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	cd $(LIBFT_DIR) && $(MAKE) fclean

re: fclean all

.PHONY: all bonus build clean fclean re libft