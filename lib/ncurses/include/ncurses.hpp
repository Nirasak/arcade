/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-nicolas.allain
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <iostream>
#include <vector>
#include <ncurses.h>
#include "IGraphicLib.hpp"

class ncurses : public IGraphicLib {
    public:
        ncurses();
        ~ncurses() override = default;
        ncurses& operator=(const ncurses&) = delete;
        ncurses(const ncurses&) = delete;

        void createWindow(void) override;
        void closeWindow(void) override;
        int eventWindow(void) override;
        std::string getLibName(void) override;
        int menu(void) override;
        void displayMenu(int line, std::string str, int color);
        void displayGame(std::vector<std::string> map, int x, std::string actScore) override;
        int getInput(void) override;

    protected:
    private:
        WINDOW *window{};
        int input = 0;
        int menuButton = 1;
};

#endif /* !NCURSES_HPP_ */
