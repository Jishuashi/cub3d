# ╔═════════════════════════════════════════════════════════════════╗
# ║                          LIBFT MAKEFILE                           ║
# ╚═════════════════════════════════════════════════════════════════╝

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃ VARIABLES                                                         ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

NAME			= libft.a

# Source files
SRCS			= ft_isalpha.c \
				  ft_isdigit.c \
				  ft_isalnum.c \
				  ft_isascii.c \
				  ft_isprint.c \
				  ft_strlen.c \
				  ft_memset.c \
				  ft_bzero.c \
				  ft_memcpy.c \
				  ft_memmove.c \
				  ft_strlcpy.c \
				  ft_strlcat.c \
				  ft_toupper.c \
				  ft_tolower.c \
				  ft_strchr.c \
				  ft_strrchr.c \
				  ft_strncmp.c \
				  ft_memchr.c \
				  ft_memcmp.c \
				  ft_strnstr.c \
				  ft_atoi.c \
				  ft_calloc.c \
				  ft_strdup.c \
				  ft_substr.c \
				  ft_strjoin.c \
				  ft_strtrim.c \
				  ft_split.c \
				  ft_itoa.c \
				  ft_strmapi.c \
				  ft_striteri.c \
				  ft_putchar_fd.c \
				  ft_putstr_fd.c \
				  ft_putendl_fd.c \
				  ft_putnbr_fd.c \
				  ft_get_next_line.c \
				  ft_gnl_strchr.c \
				  ft_putstr.c \
				  ft_putnbr.c \
				  ft_putnbr_usigned.c \
				  ft_print_hex.c \
				  ft_print_addr.c \
				  ft_putchar.c \
				  ft_printf.c \
				  ft_putnbr_long.c \
				  ft_lstmap.c \
				  ft_lstnew.c \
				  ft_lstadd_front.c \
				  ft_lstsize.c \
				  ft_lstlast.c \
				  ft_lstadd_back.c \
				  ft_lstdelone.c \
				  ft_lstclear.c \
				  ft_lstiter.c

# Object files
OBJS			= $(SRCS:.c=.o)

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
ARFLAGS			= rcs

# Colors for output
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
NC				= \033[0m

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃ RULES                                                             ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

all: $(NAME)

$(NAME): $(OBJS)
	@ar $(ARFLAGS) $(NAME) $(OBJS)
	@printf "$(GREEN)✓ $(NAME) created successfully$(NC)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(BLUE)→ Compiling $<$(NC)\n"

clean:
	@rm -f $(OBJS)
	@printf "$(YELLOW)✓ Object files removed$(NC)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)✓ All files removed$(NC)\n"

re: fclean all

.PHONY: all clean fclean re