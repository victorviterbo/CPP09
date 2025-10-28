# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/15 15:55:45 by victorviter       #+#    #+#              #
#    Updated: 2025/10/28 16:54:59 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Iter
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

INCLUDE = -I./include/

SRCS_MAIN_F =	ex01.cpp

SRCS = $(addprefix srcs/, $(SRCS_MAIN_F))

OBJS = $(patsubst srcs/%.cpp,objs/%.o,$(SRCS))

OBJS_DIRS = $(sort $(dir $(OBJS)))

all: folders $(NAME)

clean:
	@rm -rf objs/

fclean: clean
	@rm -f $(NAME)

re: fclean all

folders:
	@mkdir -p $(OBJS_DIRS)

objs/%.o: srcs/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled successfully"

.PHONY: all clean fclean re folders