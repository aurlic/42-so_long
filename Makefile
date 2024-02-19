NAME		=	so_long

CC			=	cc

FLAG		=	-g3 -Wall -Wextra -Werror

LIBFT_PATH	=	./libft

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

MLX_PATH	=	./minilibx-linux

MLX_FILE	=	libmlx.a

MLX_FLAGS	=	-lX11 -lXext

MLX_LIB		=	$(MLX_PATH)/$(MLX_FILE)

MLX_EX		=	$(MLX_LIB) $(MLX_FLAGS)

SRCS		=	srcs/main.c \
				srcs/error.c \
				srcs/check_file.c \
				srcs/check_map.c \
				srcs/check_map_utils.c \
				srcs/check_path.c \
				srcs/display.c \
				srcs/free.c \
				srcs/moves.c \
				srcs/hooks.c \
				srcs/init.c \
				srcs/enemy.c \

SRCS_BONUS	=	srcs/bonus/main_bonus.c \
				srcs/bonus/error_bonus.c \
				srcs/bonus/check_file_bonus.c \
				srcs/bonus/check_map_bonus.c \
				srcs/bonus/check_map_utils_bonus.c \
				srcs/bonus/check_path_bonus.c \
				srcs/bonus/display_bonus.c \
				srcs/bonus/free_bonus.c \
				srcs/bonus/moves_bonus.c \
				srcs/bonus/hooks_bonus.c \
				srcs/bonus/init_bonus.c \
				srcs/bonus/enemy_bonus.c \

INCLUDES	=	includes/ \

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

.c.o:
	@printf "\r\033[K[so_long] \033[0;32mBuilding : $<\033[0m"
	@$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

lib:
	@printf "\r\033[K[so_long] \033[4;32mBuilding libft: $<\033[0m\n"
	@make -C $(LIBFT_PATH)

mlx:
	@printf "\n\r\033[K[so_long] \033[4;32mBuilding minilibx: $<\033[0m\n"
	@make -sC $(MLX_PATH)
	@printf "\n"


$(NAME): lib mlx $(OBJS)
	@printf "\r\033[K[so_long] \033[4;32mBuilding so_long: $<\033[0m"
	@$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@printf "\r\033[K[so_long] \033[0;32mDone!\033[0m\n"

bonus: lib mlx $(OBJS_BONUS)
	@printf "\r\033[K[so_long_bonus] \033[4;32mBuilding so_long: $<\033[0m"
	@$(CC) $(OBJS_BONUS) $(LIBFT_LIB) $(MLX_EX) -o so_long_bonus
	@printf "\r\033[K[so_long_bonus] \033[0;32mDone!\033[0m\n"

clean:
	@printf "[so_long] \033[0;31mCleaning $(MLX_PATH)\033[0m\n"
	@make clean -sC $(MLX_PATH) > /dev/null 2>&1
	@printf "[so_long] \033[0;31mCleaning $(LIBFT_PATH)\033[0m\n"
	@make clean -sC $(LIBFT_PATH) > /dev/null 2>&1
	@printf "[so_long] \033[0;31mCleaning .o\033[0m\n"
	@rm -f $(OBJS)
	@printf "[so_long] \033[0;31mCleaned objects!\033[0m\n"

fclean: clean
	@printf "[so_long] \033[0;31mDeleting so_long executable\033[0m\n"
	@rm -f $(NAME)
	@rm -f so_long_bonus
	@make fclean -C $(LIBFT_PATH) > /dev/null 2>&1
	@printf "[so_long] \033[1;32mDone\033[0m\n\n"

re: fclean all

.PHONY: all clean fclean re
