SERVER = server
CLIENT = client

SERVER_SRCS = server.c
CLIENT_SRCS = client.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

CC = @cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
RELINK = libft/libft.h

RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
RESET = \033[0m

all: $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT) -lft -o $@
	@echo "$(GREEN)server created! ✅$(RESET)"

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT) -lft -o $@
	@echo "$(GREEN)client created! ✅$(RESET)"

$(SERVER_OBJS): %.o: %.c $(RELINK)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(CLIENT_OBJS): %.o: %.c $(RELINK)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT) --no-print-directory

clean:
	@make clean -C $(LIBFT) --no-print-directory
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	@echo "$(YELLOW)cleaning minitalk objects! 🧹✨$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT) --no-print-directory
	@rm -f $(SERVER) $(CLIENT)
	@echo "$(RED)server and client removed! ❌$(RESET)"

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
