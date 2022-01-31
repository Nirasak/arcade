##
## EPITECH PROJECT, 2021
## B-OOP-400-PAR-4-1-arcade-nicolas.allain
## File description:
## Makefile
##

CC	=	g++

RM	=	rm -f

SRC	=	sfml.cpp

OBJS	=	$(SRC:.cpp=.o)

NAME	=	arcade_sfml.so

CPPFLAGS	=	 -g -Wall -Wextra -Weffc++ -fPIC -I ../../include -I include -rdynamic

LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system -shared

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)
	mv $(NAME) ../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
