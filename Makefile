NAME        = cub3d

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
MLX_DIR     = mlx
CPPFLAGS    = -Isrc/includes -I$(LIBFT_DIR) -I$(MLX_DIR)
MLX         = $(MLX_DIR)/libmlx.a
UNAME_S     := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
PLATFORM    = macOS
MLX_INC     = /opt/X11/include
LDFLAGS     = -L$(MLX_DIR) -L/opt/X11/lib -lmlx -lXext -lX11 -lm
else ifeq ($(UNAME_S),Linux)
PLATFORM    = Linux
MLX_INC     = /usr/include
LDFLAGS     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else
$(error Unsupported operating system: $(UNAME_S))
endif

OBJ_DIR     = obj
LIBFT_DIR   = src/libft
LIBFT_OBJ_DIR = $(OBJ_DIR)/libft
LIBFT       = $(LIBFT_DIR)/libft.a
LIBFT_SRCS  = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS  = $(patsubst $(LIBFT_DIR)/%.c,$(LIBFT_OBJ_DIR)/%.o,$(LIBFT_SRCS))

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
			src/utils/map_copy.c		\
			src/utils/point.c			\
			src/gnl_cub.c 				\
			src/parse_textures.c		\
			src/load_textures.c	     	\
			src/parse_colors.c			\
			src/flood_fill.c			\


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
	@printf "$(CYAN)Platform:$(RESET) $(PLATFORM)\n"

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)
	@printf "$(YELLOW)✔ $(NAME) built successfully$(RESET)\n"

$(LIBFT): $(LIBFT_OBJS)
	@ar rcs $@ $^


$(LIBFT_OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "$(CYAN)• Compiled:$(RESET) %s\n" "$<"

$(MLX):
	@$(MAKE) -C $(MLX_DIR) -f Makefile.mk INC=$(MLX_INC) all

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "$(CYAN)• Compiled:$(RESET) %s\n" "$<"

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLUE)✦ Object files removed$(RESET)\n"
	@$(RM) $(LIBFT) $(LIBFT_OBJS)
	@$(MAKE) -C $(MLX_DIR) -f Makefile.mk clean

fclean:
	@$(RM) $(NAME)
	@printf "$(RED)✦ Executable removed$(RESET)\n"
	@$(RM) $(LIBFT) $(LIBFT_OBJS)
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLUE)✦ Object files removed$(RESET)\n"
	@$(MAKE) -C $(MLX_DIR) -f Makefile.mk clean

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