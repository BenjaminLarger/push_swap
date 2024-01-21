# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blarger <blarger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:47:17 by blarger           #+#    #+#              #
#    Updated: 2024/01/21 17:03:44 by blarger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

SRC = ./Source/0_atoi.c ./Source/0_main.c ./Source/0_utils_list.c ./Source/0_utils_main.c ./Source/1_instructions.c ./Source/1_utils_instructions.c ./Source/1_utils_instructions2.c ./Source/2_algo_for_small_dataset.c ./Source/3_algo_for_big_dataset.c ./Source/3_quick_sort_stack_c.c ./Source/3_get_ref_in_stack_c.c ./Source/3_utils_chunk.c
INCLUDE = ./Library/push_swap.h
OBJ = $(SRC:%.c=%.o)
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

%.o: %.c
			@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
			@${CC} ${CFLAGS} -c $< -o $@

RM = rm -f
LIBFT = Ft_libft/libft.a
FT_PRINTF = Ft_printf/libftprintf.a

.Phony: all clean fclean re

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	make -C ./Ft_libft

$(FT_PRINTF):
	make -C ./Ft_printf

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C ./Ft_libft clean
	make -C ./Ft_printf clean

fclean: clean
	$(RM) $(NAME)
	make -C ./Ft_libft fclean
	make -C ./Ft_printf fclean

re: fclean all