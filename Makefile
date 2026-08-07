NAME        = cub3d

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
CPPFLAGS    = -I$(LIBFT_DIR) -I$(MLX_DIR)

OBJ_DIR     = obj
LIBFT_DIR   = src/libft
MLX_DIR     = src/minilibx-linux
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a
MLX_LIBS    = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

UNAME_S     = $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
MLX         =
MLX_LIBS    =
endif

ifeq ($(UNAME_S),Linux)
MLX_LIBS    += -lbsd
endif

SRCS        =							\
			src/cube3d.c				\
			src/init_mlx.c				\
			src/parse_map.c				\
			src/utils/file_utils.c		\
			src/utils/free_utils.c		\
			src/utils/init_texture.c		\
			src/utils/print_utils.c		\
			src/utils/colors_utils.c	\
			src/utils/str_utils.c		\
			src/utils/load_xpm.c		\

ifeq ($(UNAME_S),Darwin)
SRCS       += src/utils/mlx_compat.c
endif

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

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIBS) -o $(NAME)
	@printf "$(YELLOW)✔ $(NAME) built successfully$(RESET)\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "$(CYAN)• Compiled:$(RESET) %s\n" "$<"

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLUE)✦ Object files removed$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean:
	@$(RM) $(NAME)
	@printf "$(RED)✦ Executable removed$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
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