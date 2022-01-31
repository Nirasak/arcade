/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-nicolas.allain
** File description:
** pacman
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include "IGameLib.hpp"

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

class pacman : public IGameLib {
    public:
        pacman();
        ~pacman() override = default;

        std::vector<std::string> getMap(void) const;
        std::vector<std::string> stringToVector(std::string list, char c);
        std::string getFileContent(const std::string &path);
        void setMap(std::vector<std::string> vec);
        void moveUp(void) override;
        void moveLeft(void) override;
        void moveRight(void) override;
        void moveDown(void) override;
        void move(void) override;
        int checkDir(char c) override;
        int getScore(void) override;
        int getDir(void) override;
        int getEnd(void) override;

    private:
        std::vector<std::string> map{};
        int x = 0;
        int y = 0;
        int nextDir = 0;
        int dir = 0;
        int score = 0;
        int end = 0;
};

#endif /* !PACMAN_HPP_ */
