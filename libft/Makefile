NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_printf.c ft_printf_utils.c

BSRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror
CC = @cc

RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)libft.a created! ✅"

%.o: %.c libft.h ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS) $(BOBJS)
	@echo "$(YELLOW)cleaning objects! 🧹✨"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)libft.a removed! ❌"

re : fclean all

bonus : $(BOBJS)
	@ar rcs $(NAME) $(BOBJS)
	@echo "$(GREEN)Bonus added to libft.a! ✅"

.PHONY : all clean fclean re bonus