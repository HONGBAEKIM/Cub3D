NAME	:= cub3D
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror
#CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3

LIBMLX	:= ./MLX42
LIBFT	:= ./libft


HEADERS	:= -I ./include -I $(LIBFT) -I $(LIBMLX)/include/MLX42
#HEADERS	:= -I ./include -I $(LIBFT) -I $(LIBMLX)/include/MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBF	:= $(LIBFT)/libft.a
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

libmlx:
	@if ! [ -d "./MLX42" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git MLX42; \
		cd $(LIBMLX); cmake -B build ; cmake --build build -j4; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): libmlx $(OBJS)
	make -C $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(LIBF) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	make clean -C $(LIBFT)
#rm -rf ./MLX42

fclean: clean
	@rm -f $(NAME)
	make fclean -C $(LIBFT)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
