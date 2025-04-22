# Définition des variables
CX = cc
CXFLAGS = -Wall -Wextra -Werror

SRCS =	map.c \
		error.c \
		backtest.c \
		get_next_line/get_next_line_bonus.c \
		get_next_line/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
OUTPUT = so_long

LIB_PRINTF = ft_printf/libftprintf.a
LIB_MINILIBX = minilibx-linux/libmlx.a

all: $(OUTPUT) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIB_PRINTF):
	make -C ft_printf

$(LIB_MINILIBX):
	make -C minilibx-linux

$(OUTPUT): $(OBJS) $(LIB_PRINTF)
	$(CX) $(CXFLAGS) main.c $(OBJS) -o $(OUTPUT) -I includes $(LIB_PRINTF) -lX11 -lXext -lm

%.o: %.c
	$(CX) $(CXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C ft_printf
	make clean -C minilibx-linux

fclean: clean
	rm -f $(OUTPUT)
	rm -f $(LIB_PRINTF)
	rm -f $(LIB_MINILIBX)

re: fclean all

.PHONY: all clean fclean re bonus
