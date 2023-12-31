NAME = server
CLIENT = client

BSERVER = server_bonus
BCLIENT = client_bonus

SERVER_SRCS = server.c
CLIENT_SRCS = client.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

BSERVER_SRCS = server_bonus.c
BCLIENT_SRCS = client_bonus.c

BSERVER_OBJS = $(BSERVER_SRCS:.c=.o)
BCLIENT_OBJS = $(BCLIENT_SRCS:.c=.o)

CC = @cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
RELINK = libft/libft.h

RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
RESET = \033[0m

all: $(LIBFT) $(NAME) $(CLIENT)

bonus: $(LIBFT) $(BSERVER) $(BCLIENT)

$(NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT) -lft -o $@
	@echo "$(GREEN)server created! ✅$(RESET)"

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT) -lft -o $@
	@echo "$(GREEN)client created! ✅$(RESET)"

$(BSERVER): $(BSERVER_OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT) -lft -o $@
	@echo "$(GREEN)server_bonus created! ✅$(RESET)"

$(BCLIENT): $(BCLIENT_OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT) -lft -o $@
	@echo "$(GREEN)client_bonus created! ✅$(RESET)"

$(SERVER_OBJS): %.o: %.c $(RELINK)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(CLIENT_OBJS): %.o: %.c $(RELINK)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(BSERVER_OBJS): %.o: %.c $(RELINK)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(BCLIENT_OBJS): %.o: %.c $(RELINK)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT) --no-print-directory

clean:
	@make clean -C $(LIBFT) --no-print-directory
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(BSERVER_OBJS) $(BCLIENT_OBJS)
	@echo "$(YELLOW)cleaning minitalk objects! 🧹✨$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT) --no-print-directory
	@rm -f $(NAME) $(CLIENT) $(BSERVER) $(BCLIENT)
	@echo "$(RED)server and client removed! ❌$(RESET)"

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
