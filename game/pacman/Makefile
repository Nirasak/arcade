##
## EPITECH PROJECT, 2021
## B-OOP-400-PAR-4-1-arcade-nicolas.allain
## File description:
## Makefile
##

CC	=	g++

SRC	=	pacman.cpp

OBJS	=	$(SRC:.cpp=.o)

NAME	=	arcade_pacman.so

CPPFLAGS	=	 -g -Wall -Wextra -Weffc++ -fPIC -I ../../include -I include -rdynamic

LDFLAGS		=	 -shared

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)
	mv $(NAME) ../
	cp ../$(NAME) ../../lib

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)
	$(RM) ../../lib/$(NAME)

re: fclean all

.PHONY: all clean fclean re
