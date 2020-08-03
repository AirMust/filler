# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: air_must <air_must@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 14:04:51 by slynell           #+#    #+#              #
#    Updated: 2020/08/03 01:39:55 by air_must         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = slynell.filler

CC = gcc

FLAGS = -Wall -Werror -Wextra -O2

SDIR = src

ODIR = obj

IDIR = header

LDIR = libft

SRCS = main.c
SRCS += filler_algoritm.c
SRCS += read_filler_support.c

INCS = filler.h

INCS += $(addprefix $(LDIR)/,$(addprefix $(IDIR)/,$(libft.h)))

SOURCES = $(addprefix $(SDIR)/,$(SRCS))

OBJECTS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

INCLUDES = $(addprefix $(IDIR)/,$(INCS))

LIBFT = $(addprefix $(LDIR)/,libft.a)


.PHONY: clean fclean all re

all : print $(LIBFT) $(NAME)
	@make -C $(LDIR) 2> tmp.log
	@2> tmp.log
	@@echo "Project $(NAME) build successfully \c" >> tmp.log
	@echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m"


print:
	@echo "Make \033[33m$(NAME)\033[0m\c"

$(LIBFT) :
	@make -C $(LDIR) 2> tmp.log

$(NAME) : $(OBJECTS) $(INCLUDES) $(LIBFT) Makefile
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -I $(IDIR) $(LIBFT)

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

re: fclean all
