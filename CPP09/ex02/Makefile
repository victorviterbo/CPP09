# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/15 15:55:45 by victorviter       #+#    #+#              #
#    Updated: 2025/11/09 12:37:03 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

INCLUDE = -I./include/

SRCS_MAIN_F =	main.cpp #FordJohnson_deque.cpp utils_deque.cpp FordJohnson_vec.cpp utils_vec.cpp

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