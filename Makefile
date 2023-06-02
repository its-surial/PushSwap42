# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: surkumar <surkumar@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 12:40:23 by lgollong          #+#    #+#              #
#    Updated: 2023/06/02 20:01:40 by surkumar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAMECR = checker

HDRS =	header/push_swap.h

MAIN_SRC = main.c

SRCS = ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_strlen.c ft_substr.c ft_strcmp.c \
            swap.c push.c reverse_rotate.c rotate.c \
            big_sort.c small_sort.c utils.c sorting.c utils2.c chunks.c \
            parsing.c error_msg.c manage_data.c \

SRCS_CR = checker.c get_next_line.c get_next_line_utils.c 

OBJ_MAIN = $(MAIN_SRC:.c=.o)
OBJ_DIR = obj/
OBJCR_DIR = checker_obj/
OBJ_FILES = $(SRCS:.c=.o)
OBJSCR = $(SRCS_CR:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
MAIN_OBJ = $(addprefix $(OBJ_DIR), $(OBJ_MAIN))
OBJS_CR = $(addprefix $(OBJCR_DIR), $(OBJSCR))

all: $(NAME)
$(NAME): obj $(OBJS) $(MAIN_OBJ)
	gcc -Wall -Wextra -Werror $(OBJS) $(MAIN_OBJ) -o $(NAME)

obj/%.o: src/%.c $(HDRS)
	gcc -c -Wall -Wextra -Werror $< -o $@

.PHONY: clean

checker: $(NAMECR)
$(NAMECR): checker_obj $(OBJS) $(OBJS_CR) 
	gcc -Wall -Wextra -Werror $(OBJS) $(OBJS_CR) -o $(NAMECR)

checker_obj/%.o: checker_src/%.c $(HDRS)
	gcc -c -Wall -Wextra -Werror $< -o $@

$(OBJ_DIR):
	mkdir -p obj

$(OBJCR_DIR):
	mkdir -p checker_obj

clean:
	@rm -rf $(OBJ_DIR) $(OBJCR_DIR)

fclean: clean
	@rm -f $(NAME) $(NAMECR)

re: fclean all
	
