NAME = so_long

CC = cc 

FLAGS = -Wall -Werror -Wextra

SRCS = main.c so_long.h render_map.c get_next_line.c \
		get_next_line_utils.c check_map.c flood_fill.c \
		read_map.c 

AR = ar rcs

OBJS = $(SRCS:.c=.o)

MLX = -lmlx -lXext -lX11

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
	
$(NAME): $(OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all
