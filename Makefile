NAME        = cub3d

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
CPPFLAGS    = -I$(LIBFT_DIR)

OBJ_DIR     = obj
LIBFT_DIR   = src/libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        =							\
			src/cube3d.c				\
			src/parse_map.c				\
			src/utils/file_utils.c		\
			src/utils/free_utils.c		\
			src/utils/print_utils.c		\
			src/utils/colors_utils.c	\
			src/utils/str_utils.c		\
			src/check_map.c				\
			src/cub_format_checker.c	\
			src/utils/err_utils.c		\
			src/utils/read_utils.c		\
			src/gnl_cub.c 				\
			src/parse_textures.c		\
			src/parse_colors.c			\


OBJS        = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(sort $(dir $(SRCS)))

RM          = rm -f
MKDIR       = mkdir -p

YELLOW      = \033[1;33m
CYAN        = \033[1;36m
BLUE        = \033[1;34m
RED         = \033[1;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)
	@printf "$(YELLOW)✔ $(NAME) built successfully$(RESET)\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "$(CYAN)• Compiled:$(RESET) %s\n" "$<"

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLUE)✦ Object files removed$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@$(RM) $(NAME)
	@printf "$(RED)✦ Executable removed$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLUE)✦ Object files removed$(RESET)\n"

norm:
	@ERR_COUNT=$$(norminette src/ | grep "Error" | wc -l); \
	if [ $$ERR_COUNT -eq 0 ]; then \
		printf "$(YELLOW)Norminette: TOUT EST PARFAIT !$(RESET)\n"; \
	else \
		printf "$(RED)Norminette: ERREURS TROUVÉES :$(RESET)\n"; \
		norminette src/ | grep "Error"; \
	fi

re: fclean all

.PHONY: all clean fclean re norm