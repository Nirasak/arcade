/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IGraphic_lib
*/

#ifndef IGRAPHIC_LIB_HPP_
#define IGRAPHIC_LIB_HPP_

#include "IGameLib.hpp"
#include "enum.hpp"

class IGraphicLib {
    public:
        virtual ~IGraphicLib() = default;

        virtual void createWindow(void) = 0;
        virtual void closeWindow(void) = 0;
        virtual int eventWindow(void) = 0;
        virtual std::string getLibName(void) = 0;
        virtual int menu(void) = 0;
        virtual void displayGame(std::vector<std::string> map, int x, std::string actScore) = 0;
        virtual int getInput(void) = 0;
};

#endif /* !IGRAPHIC_LIB_HPP_ */
