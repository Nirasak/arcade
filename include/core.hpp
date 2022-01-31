/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** CORE
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <dlfcn.h>
#include <iostream>
#include <vector>

#include "IGraphicLib.hpp"
#include "IGameLib.hpp"
#include "libLd.hpp"
#include <time.h>
#include <utility>

class core {
    public:
        core(int ac, char **av);
        ~core() = default;

        int game(char *lib);
        void switchLibGraph(const char *lib);
        int checkGame(int x);
        std::vector<std::string> getLib(const std::string &directory);
        int gameLoop(void);
        int manageEvent(void);
        int checkSwitchLibGraph(void);
        void setPlayerName(std::string name);
        std::string getPlayerName(void);

    protected:
    private:
        std::string playerName{};
        libLd<IGraphicLib> graphicHandle{};
        libLd<IGameLib> gameHandle{};
        clock_t cBegin{};
        clock_t cCurrent{};
};

#endif /* !CORE_HPP_ */
