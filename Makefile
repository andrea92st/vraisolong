NAME = so_long

DIR 	=  src/

FLAGS	= -Wall -Werror -Wextra

SRCS 	=	main.c \
			so_long.h \
			render_map.c \
			get_next_line.c \
			get_next_line_utils.c \
			check_map.c \
			flood_fill.c \
			read_map.c \
			mov.c \
			utils.c \
			free_game.c \

MLX		 =		-lmlx -lXext -lX11

CC       =	    cc

CFLAGS   =	    -Wall -Wextra -Werror -g3 -I./inc 

OBJ_DIR	 =	    obj/

SRCS     =      $(SRC)

OBJ 	 =      $(patsubst src/%.c, $(OBJ_DIR)%.o, $(SRCS))

MAKE_DIR =      mkdir -p

SMAKE	 =      make --no-print-directory

$(OBJ_DIR)%.o:  src/%.c
				@$(MAKE_DIR) $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@

all:	        $(NAME)

$(NAME):        $(OBJ)
				@$(CC) $(CFLAGS) $(OBJ) -o $@ -lreadline
				@echo "\033[1;92m======== project compiled ========\033[0m"

clean:
				@rm -rf $(OBJ_DIR)
				@echo "\033[1;35m======== object files removed ========\033[0m"

fclean:         clean
				@$(RM) $(NAME)
				@echo "\033[1;36m======== executable removed  =======\033[0m"

re:             fclean all

.PHONY: clean fclean all re