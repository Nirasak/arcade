##
## EPITECH PROJECT, 2021
## Epitech
## File description:
## Makefile
##

CXX			?=	g++

RM			?=	rm -f

CXXFLAGS	+=	-Wall -Wextra -Weffc++

CPPFLAGS	=	-rdynamic -iquote include/ -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system -lSDL2 -lncurses

NAME	=	arcade

SRC		=	src/IManager/game.cpp	\

MAIN	=	src/main.cpp

MOBJ	=	$(MAIN:.cpp=.o)

OBJ		=	$(SRC:.cpp=.o)

%.o:	%.cpp
	@$(CXX) -no-pie $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $< && \
	(echo -e "\033[92m[ OK ]\033[0m" $<) || \
	(echo -e "\033[91m[ NO COMPIL ]\033[0m" $<; false)

all:	$(NAME)

core:	$(NAME)

graphicals:	$(NAME)

games: $(NAME)

debug:  CXXFLAGS  +=      -ggdb3
debug:  all

$(NAME):	$(OBJ)	$(MOBJ)
	@$(CXX) -ldl -no-pie $(MOBJ) $(OBJ) -o $(NAME)
	make -sC lib/ncurses/
	make -sC lib/sdl/
	make -sC lib/sfml/
	make -sC game/snake/
	make -sC game/pacman/

clean:
	@echo -e "\033[91m[ RM ]\033[0m *.o"
	@$(RM) $(OBJ) $(MOBJ) $(TOBJ)
	make clean -sC lib/ncurses/
	make clean -sC lib/sdl/
	make clean -sC lib/sfml/
	make clean -sC game/snake/
	make clean -sC game/pacman/

fclean: clean
	@$(RM) $(NAME)
	@echo -e "\033[91m[ RM ]\033[0m Binary"
	make fclean -sC lib/ncurses/
	make fclean -sC lib/sdl/
	make fclean -sC lib/sfml/
	make fclean -sC game/snake/
	make fclean -sC game/pacman/

re: fclean all

.PHONY: all clean fclean re
