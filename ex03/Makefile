# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 03:06:06 by yeju              #+#    #+#              #
#    Updated: 2022/03/25 00:58:22 by yeju             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp
CFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Fixed.cpp Point.hpp Point.cpp bsp.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	clang++ $(CFLAGS) -c $(SRCS)
	clang++ $(CFLAGS) $(OBJS) -o $(NAME)

.PHONY : all clean fclean re