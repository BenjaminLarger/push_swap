# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blarger <blarger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:47:17 by blarger           #+#    #+#              #
#    Updated: 2024/02/12 13:55:19 by blarger          ###   ########.fr        #
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

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJDIR = Objects
SRC = ./Source/0_atoi.c ./Source/0_utils_main.c ./Source/0_main.c ./Source/0_utils_list.c ./Source/1_utils_instructions2.c ./Source/1_utils_instructions.c ./Source/1_instructions.c ./Source/2_algo_for_small_dataset.c ./Source/3_get_ref_in_stack_c.c ./Source/3_algo_for_big_dataset.c ./Source/3_quick_sort_stack_c.c ./Source/3_push_b_to_a_utils.c ./Source/3_utils_chunk.c ./Source/0_utils.c
                                             
OBJ = $(SRC:./Source/%.c=$(OBJDIR)/%.o)
LIBFT = Ft_libft/libft.a
FT_PRINTF = Ft_printf/libftprintf.a
NAME = push_swap

$(shell mkdir -p $(OBJDIR))

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJ)
	@echo "👉 $(BLUE)$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(FT_PRINTF) $(LIBMLX) -o $(NAME)$(DEF_COLOR)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "$(GREEN)$(NAME) ✨ SO_LONG compiled!$(DEF_COLOR)"

$(OBJDIR)/%.o: ./Source/%.c
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./Ft_libft
	@echo "$(GREEN)libft compiled!$(DEF_COLOR)"	

$(FT_PRINTF):
	make -C ./Ft_printf
	@echo "$(GREEN)printf compiled!$(DEF_COLOR)"

clean:
	$(RM) $(OBJDIR)/*.o
	@echo "$(CYAN)Object cleaned.$(DEF_COLOR)"
	make -C ./Ft_libft clean
	@echo "$(CYAN)libft object cleaned.$(DEF_COLOR)"
	make -C ./Ft_printf clean
	@echo "$(CYAN)ft_printf object cleaned.$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(CYAN)so_long executable files cleaned!$(DEF_COLOR)"
	make -C ./Ft_libft fclean

re: fclean all