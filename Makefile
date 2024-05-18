NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC
LDFLAGS = -pie
RM = rm -f

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

HDRS_LST = minitalk.h

# Standard sources
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Bonus sources
SERVER_SRC_BONUS = server_bonus.c
CLIENT_SRC_BONUS = client_bonus.c

# Standard objects
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# Bonus objects
SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)
CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)

# Default target
all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(NAME_SERVER) -L$(LIBFT_DIR) -lft

$(NAME_CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(NAME_CLIENT) -L$(LIBFT_DIR) -lft

# Bonus rule
bonus: $(NAME_SERVER)_bonus $(NAME_CLIENT)_bonus

$(NAME_SERVER)_bonus: $(SERVER_OBJ_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SERVER_OBJ_BONUS) -o $(NAME_SERVER) -L$(LIBFT_DIR) -lft

$(NAME_CLIENT)_bonus: $(CLIENT_OBJ_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ_BONUS) -o $(NAME_CLIENT) -L$(LIBFT_DIR) -lft

# Pattern rule for object files
%.o: %.c $(HDRS_LST)
	@$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

# Libraries
$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus

