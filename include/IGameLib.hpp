/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-nicolas.allain
** File description:
** IGameLib
*/

#include <iostream>
#include <vector>
#include "enum.hpp"

#ifndef IGAMELIB_HPP_
#define IGAMELIB_HPP_

class IGameLib {
    public:
        virtual ~IGameLib() = default;

        virtual std::vector<std::string> getMap(void) const = 0;
        virtual void moveUp(void) = 0;
        virtual void moveLeft(void) = 0;
        virtual void moveRight(void) = 0;
        virtual void moveDown(void) = 0;
        virtual void move(void) = 0;
        virtual int checkDir(char c) = 0;
        virtual int getScore(void) = 0;
        virtual int getDir(void) = 0;
        virtual int getEnd(void) = 0;
};

#endif /* !IGAMELIB_HPP_ */
