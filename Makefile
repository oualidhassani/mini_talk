NAME = minitalk.a

SRCS = \
	server.c client.c

SRCS_BONUS = \
	server_bonus.c client_bonus.c

AR = ar rcs

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) server client

bonus: $(NAME) server_bonus client_bonus

$(NAME): $(OBJ) $(LIBFT)
	$(AR) $(NAME) $(OBJ)

server: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o server server.o $(LIBFT)

client: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o client client.o $(LIBFT)

server_bonus: $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o server_bonus server_bonus.o $(LIBFT)

client_bonus: $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o client_bonus client_bonus.o $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	cd $(LIBFT_DIR) && $(MAKE)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME) server client server_bonus client_bonus
	cd $(LIBFT_DIR) && $(MAKE) fclean
	
re: fclean all

.PHONY: all bonus server client server_bonus client_bonus clean fclean re

# NAME = minitalk.a

# SRCS = \
#     server.c client.c

# SRCS_BONUS = \
#     server_bonus.c client_bonus.c

# AR = ar rcs

# OBJ = $(SRCS:.c=.o)

# OBJ_BONUS = $(SRCS_BONUS:.c=.o)

# CC = gcc

# CFLAGS = -Wall -Werror -Wextra

# RM = rm -f

# LIBFT_DIR = libft

# LIBFT_TARGET = $(LIBFT_DIR)/libft.a

# all: libft $(NAME) server client

# bonus: libft $(NAME) server_bonus client_bonus

# $(NAME): $(OBJ)
# 	$(AR) $(NAME) $(OBJ)

# server: $(OBJ)
# 	$(CC) $(CFLAGS) -o server server.o $(LIBFT_TARGET)

# client: $(OBJ)
# 	$(CC) $(CFLAGS) -o client client.o $(LIBFT_TARGET)

# server_bonus: $(OBJ_BONUS)
# 	$(CC) $(CFLAGS) -o server_bonus server_bonus.o $(LIBFT_TARGET)

# client_bonus: $(OBJ_BONUS)
# 	$(CC) $(CFLAGS) -o client_bonus client_bonus.o $(LIBFT_TARGET)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_DIR)

# libft:
# 	cd $(LIBFT_DIR) && $(MAKE)

# clean:
# 	$(RM) $(OBJ) $(OBJ_BONUS)
# 	cd $(LIBFT_DIR) && $(MAKE) clean

# fclean: clean
# 	$(RM) $(NAME) server client server_bonus client_bonus
# 	cd $(LIBFT_DIR) && $(MAKE) fclean

# re: fclean all

# .PHONY: all bonus server client server_bonus client_bonus clean fclean re libft
