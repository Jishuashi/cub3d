NAME        = libft.a
.SILENT:

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
OBJ_DIR     = obj

SRCS        = \
	ft_isalpha.c \
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

OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
RED         = \033[1;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(GREEN)✔ $(NAME) built successfully$(RESET)\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(YELLOW)• Compiled:$(RESET) %s\n" "$<"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@printf "$(BLUE)✦ Object files removed$(RESET)\n"

fclean:
	@rm -f $(NAME)
	@printf "$(RED)✦ Executable removed$(RESET)\n"
	@$(MAKE) clean

re: fclean all

.PHONY: all clean fclean re