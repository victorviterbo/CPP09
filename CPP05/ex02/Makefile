# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 15:40:14 by vviterbo          #+#    #+#              #
#    Updated: 2025/07/31 10:05:59 by victorviter      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

INCLUDE = -I./include/

SRCS_MAIN_F =	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
				RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

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