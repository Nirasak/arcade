/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-nicolas.allain
** File description:
** start_game
*/

#include <dlfcn.h>
#include "core.hpp"

std::vector<std::string> core::getLib(const std::string &directory)
{
    std::string file;
	std::vector<std::string> lib;
	struct dirent *dirent;

    if (DIR *dir = opendir(directory.c_str())) {
        while ((dirent = readdir(dir)) != NULL) {
            file = "./" + directory  + "/" + dirent->d_name;
			if ((dirent->d_type & DT_REG) == DT_REG)
            			lib.insert(lib.end(), file);
            }
            closedir(dir);
        }
	return lib;
}

void core::switchLibGraph(const char *lib)
{
    graphicHandle.get()->closeWindow();
    graphicHandle.closeLib();
    this->graphicHandle.openLib(lib);
}

void core::setPlayerName(std::string name)
{
    this->playerName = name;
}

std::string core::getPlayerName(void)
{
    return this->playerName;
}

int core::checkGame(int x)
{
    if (x == 1) {
        this->gameHandle.openLib("game/arcade_nibbler.so");
    } else if (x == 2) {
        this->gameHandle.openLib("game/arcade_pacman.so");
    } else if (x == 3) {
        graphicHandle.get()->closeWindow();
        return (1);
    }
    return (0);
}

int core::checkSwitchLibGraph()
{
    if (this->graphicHandle.get()->getInput() == NEXT) {
        if (!this->graphicHandle.get()->getLibName().compare("ncurses")) {
            this->switchLibGraph("lib/arcade_sdl2.so");
        } else if (!this->graphicHandle.get()->getLibName().compare("sdl")) {
            this->switchLibGraph("lib/arcade_sfml.so");
        } else if (!this->graphicHandle.get()->getLibName().compare("sfml")) {
            this->switchLibGraph("lib/arcade_ncurses.so");
        }
    } else if (this->graphicHandle.get()->getInput() == PREVIOUS) {
        if (!this->graphicHandle.get()->getLibName().compare("ncurses")) {
            this->switchLibGraph("lib/arcade_sfml.so");
        } else if (!this->graphicHandle.get()->getLibName().compare("sdl")) {
            this->switchLibGraph("lib/arcade_ncurses.so");
        } else if (!this->graphicHandle.get()->getLibName().compare("sfml")) {
            this->switchLibGraph("lib/arcade_sdl2.so");
        }
    } else if (this->graphicHandle.get()->getInput() == QUIT) {
        this->graphicHandle.get()->closeWindow();
        if (gameHandle.get() != nullptr)
            std::cout << this->getPlayerName() << "'s score: " << gameHandle.get()->getScore() << std::endl;
        return (1);
    }
    return (0);
}

int core::manageEvent(void)
{
    if (this->graphicHandle.get()->getInput() == UP) {
        gameHandle.get()->moveUp();
    } else if (this->graphicHandle.get()->getInput() == LEFT) {
        gameHandle.get()->moveLeft();
    } else if (this->graphicHandle.get()->getInput() == RIGHT) {
        gameHandle.get()->moveRight();
    } else if (this->graphicHandle.get()->getInput() == DOWN) {
        gameHandle.get()->moveDown();
    } else if (this->graphicHandle.get()->getInput() == ESCAPE) {
        gameHandle.closeLib();
    } else if (this->graphicHandle.get()->getInput() == QUIT) {
        if (gameHandle.get() != nullptr)
            std::cout << this->getPlayerName() << "'s score: " << gameHandle.get()->getScore() << std::endl;
        this->graphicHandle.get()->closeWindow();
        return (1);
    } else {
        this->checkSwitchLibGraph();
    }
    return (0);
}

int core::gameLoop(void)
{
    std::vector<std::string> map = gameHandle.get()->getMap();

    this->graphicHandle.get()->eventWindow();
    if (this->manageEvent())
        return (1);
    if (gameHandle.get() == nullptr)
        return (0);
    gameHandle.get()->move();
    this->graphicHandle.get()->displayGame(map, gameHandle.get()->getDir(), std::to_string(gameHandle.get()->getScore()));
    this->cBegin = clock();
    if (gameHandle.get()->getEnd() == true) {
        this->graphicHandle.get()->closeWindow();
        std::cout << this->getPlayerName() << "'s score: " << gameHandle.get()->getScore() << std::endl;
        return (1);
    }
    return (0);
}

int core::game(char *lib)
{
    this->graphicHandle.openLib(lib);
    this->cBegin = clock();
    this->cCurrent = clock();
    while (1) {
        this->cCurrent = clock();
        if (gameHandle.get() == nullptr) {
            if (this->checkGame(this->graphicHandle.get()->menu()))
                return (0);
            if (this->checkSwitchLibGraph())
                return (0);
        } else if (this->cCurrent - this->cBegin > 150000) {
            if (this->gameLoop())
                return (0);
        }
    }
    return (0);
}
