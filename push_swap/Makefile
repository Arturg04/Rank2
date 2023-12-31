# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 08:42:34 by ade-pinh          #+#    #+#              #
#    Updated: 2023/11/06 22:37:28 by ade-pinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### ---------- TEXT FORMATTING AND COLORS ---------- ###

# Text Colors
Black					=\033[0;30m
Red						=\033[0;31m
Green					=\033[0;32m
Yellow					=\033[0;33m
Blue					=\033[0;34m
Magenta					=\033[0;35m
Cyan					=\033[0;36m
White					=\033[0;37m

# Bright Text Colors
Bright_Black			=\033[1;30m
Bright_Red				=\033[1;31m
Bright_Green			=\033[1;32m
Bright_Yellow			=\033[1;33m
Bright_Blue				=\033[1;34m
Bright_Magenta			=\033[1;35m
Bright_Cyan				=\033[1;36m
Bright_White			=\033[1;37m

# Background Colors
Background_Black		=\033[40m
Background_Red			=\033[41m
Background_Green		=\033[42m
Background_Yellow		=\033[43m
Background_Blue			=\033[44m
Background_Magenta		=\033[45m
Background_Cyan			=\033[46m
Background_White		=\033[47m

# Text Formatting Options
Reset					=\033[0m
Bold					=\033[1m
Dim						=\033[2m
Underline				=\033[4m
Blink					=\033[5m
Reverse					=\033[7m
Hidden					=\033[8m
StrikeThrough			=\033[9m
DoubleUnderline			=\033[21m
Framed					=\033[51m
Encircled				=\033[52m
Overlined				=\033[53m
Del 					=\033[1A\033[K
Clear					=\033[2K
Hide_cursor 			=\033[?25l
Show_cursor 			=\033[?25h
### ------------------------------ ###

### ---------- LINUX ---------- ###
CC_LIN			= cc
AR				= ar rsc
### ------------------------------ ###

### ---------- OTHERS ---------- ###
NAME			= push_swap
CFLAGS			= -Werror -Wextra -Wall -g # -fsanitize=address
INCLUDE			=
LIBS			= libft/libft.a
LIBS_DIR		= libft
### ------------------------------ ###

### ---------- FILES ---------- ###

SRC			=	push_swap.c push_swap_rotate.c push_swap_rotate_type.c push_swap_stack_utils.c\
				push_swap_check_args2.c push_swap_cost_utils.c push_swap_rotate_push.c push_swap_sort.c push_swap_swap.c\
				push_swap_check_args.c push_swap_cost_utils2.c push_swap_push.c push_swap_rotate_reverse.c push_swap_stack_utils_2.c push_swap_utils.c\


#SRC_BONUS	= server_bonus.c

#OBJ1_LIN = $(patsubst $(DIR_SRC1)/%.c, $(DIR_OBJ1)/%.o, $(SRC1))
#OBJ2_LIN = $(patsubst $(DIR_SRC2)/%.c, $(DIR_OBJ2)/%.o, $(SRC2))

### ---------- FUNCTIONS ---------- ###

all: $(LIBS) $(NAME)

$(LIBS):
	@echo "$(Bright_Green)$(Blink)Compiling libft...$(Reset)"
	@make -C $(dir $@) > /dev/null 2>&1
	@echo "$(Del)"
	@echo "$(Del)$(Bright_Green)libft compiled successfully.$(Reset)"

##				LIN
#LIN_LIB:$(OBJ1_LIN) $(OBJ2_LIN)
#	$(AR) $@ $^

$(NAME):
	@$(CC_LIN) $(SRC) $(CFLAGS) $(INCLUDE) $(LIBS) -o $@
	@echo "$(Bright_Green)$@ compiled successfully.$(Reset)"

##

# Object Compilation

##				LIN
$(DIR_OBJ1)/%.o: $(DIR_SRC1)/%.c
	$(CC_LIN) $(CFLAGS) $(INCLUDE) $(LIBS) -c $< -o $@
$(DIR_OBJ2)/%.o: $(DIR_SRC2)/%.c
	$(CC_LIN) $(CFLAGS) $(INCLUDE) $(LIBS) -c $< -o $@
##

clean:
	@make fclean -C $(LIBS_DIR) > /dev/null 2>&1
	@echo "$(Bright_Red)libft removed!$(Reset)"
	@rm -f *.o
	@echo "$(Bright_Red)Object files removed$(Reset)"


fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(Bright_Red)push_swap removed!$(Reset)"
	@echo "$(Bright_Green)All removed successfully$(Reset)"

re: fclean all

bonus_re: fclean bonus

teste:
	@echo "$(Black)Black$(Reset)"
	@echo "$(Red)Red$(Reset)"
	@echo "$(Green)Green$(Reset)"
	@echo "$(Yellow)Yellow$(Reset)"
	@echo "$(Blue)Blue$(Reset)"
	@echo "$(Magenta)Magenta$(Reset)"
	@echo "$(Cyan)Cyan$(Reset)"
	@echo "$(White)White$(Reset)"
	@echo "$(Bright_Black)Bright_Black$(Reset)"
	@echo "$(Bright_Red)Bright_Red$(Reset)"
	@echo "$(Bright_Green)Bright_Green$(Reset)"
	@echo "$(Bright_Yellow)Bright_Yellow$(Reset)"
	@echo "$(Bright_Blue)Bright_Blue$(Reset)"
	@echo "$(Bright_Magenta)Bright_Magenta$(Reset)"
	@echo "$(Bright_Cyan)Bright_Cyan$(Reset)"
	@echo "$(Bright_White)Bright_White$(Reset)"
	@echo "$(Background_Black)Background_Black$(Reset)"
	@echo "$(Background_Red)Background_Red$(Reset)"
	@echo "$(Background_Green)Background_Green$(Reset)"
	@echo "$(Background_Yellow)Background_Yellow$(Reset)"
	@echo "$(Background_Blue)Background_Blue$(Reset)"
	@echo "$(Background_Magenta)Background_Magenta$(Reset)"
	@echo "$(Background_Cyan)Background_Cyan$(Reset)"
	@echo "$(Background_White)Background_White$(Reset)"
	@echo "$(Bold)Bold$(Reset)"
	@echo "$(Dim)Dim$(Reset)"
	@echo "$(Underline)Underline$(Reset)"
	@echo "$(Blink)Blink$(Reset)"
	@echo "$(Reverse)Reverse$(Reset)"
	@echo "$(Hidden)Hidden$(Reset)"
	@echo "$(StrikeThrough)StrikeThrough$(Reset)"
	@echo "$(DoubleUnderline)DoubleUnderline$(Reset)"
	@echo "$(Framed)Framed$(Reset)"
	@echo "$(Encircled)Encircled$(Reset)"
	@echo "$(Overlined)Overlined$(Reset)"

.phony: all bonus fclean clean re bonus_re
