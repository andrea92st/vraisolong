NAME = so_long

DIR 	=  src/

FLAGS	= -Wall -Werror -Wextra -g3 -I. -I$(MLX_DIR)

SRCS 	=	src/main.c \
			src/render_map.c \
			src/get_next_line.c \
			src/get_next_line_utils.c \
			src/check_map.c \
			src/flood_fill.c \
			src/read_map.c \
			src/mov.c \
			src/utils.c \
			src/free_game.c \

MLX		 = -Lminilibx-linux -lmlx -lXext -lX11 -lm

CC       =	    cc

CFLAGS   =      -Wall -Wextra -Werror -g3 -I. -Iminilibx-linux -Iinc

OBJ_DIR	 =	    obj/

OBJ 	 =      $(patsubst src/%.c, $(OBJ_DIR)%.o, $(SRCS))

MAKE_DIR =      mkdir -p

SMAKE	 =      make --no-print-directory

$(OBJ_DIR)%.o:  src/%.c so_long.h
				@$(MAKE_DIR) $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@

all:	        $(NAME)

$(NAME):        $(OBJ) minilibx-linux/libmlx.a
				@$(CC) $(CFLAGS) $(OBJ) -o $@ $(MLX) -lreadline
				@echo "\033[1;92m======== project compiled ========\033[0m"

minilibx-linux/libmlx.a:
	@$(MAKE) -C minilibx-linux

clean:
				@rm -rf $(OBJ_DIR)
				@echo "\033[1;35m======== object files removed ========\033[0m"

fclean:         clean
				@$(RM) $(NAME)
				@echo "\033[1;36m======== executable removed  =======\033[0m"

re:             fclean all

.PHONY: clean fclean all re