# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slynell <slynell@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 14:04:51 by slynell           #+#    #+#              #
#    Updated: 2020/07/27 15:46:06 by slynell          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_push_swap.a

CHECKER = checker

PUSH_SWAP = push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra -O2

SDIR = src

ODIR = obj

IDIR = header

LDIR = libft

SRCS = ft_push_action2.c
SRCS += ft_push_action.c
SRCS += ft_push_ascent.c
SRCS += ft_push_basic.c
SRCS += ft_push_operation.c
SRCS += ft_push_print.c
SRCS += ft_push_read.c
INCS = push_swap.h

SRC_CHECKER = src/checker.c
SRC_PUSH_SWAP =	src/push_swap.c

INCS += $(addprefix $(LDIR)/,$(addprefix $(IDIR)/,$(libft.h)))

SOURCES = $(addprefix $(SDIR)/,$(SRCS))

OBJECTS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

INCLUDES = $(addprefix $(IDIR)/,$(INCS))

LIBFT = $(addprefix $(LDIR)/,libft.a)


.PHONY: clean fclean all re

all : print $(LIBFT) $(NAME)
	@make -C $(LDIR) 2> tmp.log
	@@echo "Project $(PUSH_SWAP) and $(CHECKER) build successfully" >> tmp.log
	@2> tmp.log
	@echo "Project $(PUSH_SWAP) and $(CHECKER) build successfully" >> tmp.log
	@echo "Project $(PUSH_SWAP) and $(CHECKER) build successfully \033[32m[OK]\033[0m"


print:
	@echo "Make \033[33m$(PUSH_SWAP)\033[0m and \033[33m$(CHECKER)\033[0m\c"

$(LIBFT) :
	@make -C $(LDIR) 2> tmp.log

$(NAME) : $(OBJECTS) $(INCLUDES) $(LIBFT) Makefile

	@$(CC) $(FLAGS) -o $(PUSH_SWAP) $(OBJECTS) $(SRC_PUSH_SWAP) -I $(IDIR) $(LIBFT)
	@$(CC) $(FLAGS) -o $(CHECKER) $(OBJECTS) $(SRC_CHECKER) -I $(IDIR) $(LIBFT)

$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES) Makefile
	@mkdir -p $(ODIR) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

clean:
	@make clean -C $(LDIR) 2> tmp.log
	@rm -rf $(OBJS) 2> tmp.log
	@rm -rf $(ODIR) 2> tmp.log

fclean: clean
	@make fclean -C $(LDIR) 2> tmp.log
	@rm -rf $(NAME) 2> tmp.log
	@rm -rf $(PUSH_SWAP) 2> tmp.log
	@rm -rf $(CHECKER) 2> tmp.log

re: fclean all