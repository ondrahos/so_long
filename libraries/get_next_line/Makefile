# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:23:23 by ohosnedl          #+#    #+#              #
#    Updated: 2023/12/08 14:55:29 by ohosnedl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libget_next_line.a

SOURCES = get_next_line.c get_next_line_utils.c\

OBJECTS = $(SOURCES:.c=.o)

CC 			= gcc

CFLAGS 		= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)

clean:		
			rm -rf $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
