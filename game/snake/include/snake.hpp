/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-nicolas.allain
** File description:
** snake
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <array>
#include "IGameLib.hpp"

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

class snake : public IGameLib {
    public:

        snake();
        ~snake() override = default;;

        std::vector<std::string> getMap(void) const;
        std::vector<std::string> stringToVector(std::string list, char c);
        std::string getFileContent(const std::string &path);
        void setMap(std::vector <std::string> vec);
        void moveUp(void) override;
        void moveLeft(void) override;
        void moveRight(void) override;
        void moveDown(void) override;
        void move(void) override;
        void logic(void);
        int checkDir(char c) override;
        int getScore(void) override;
        int getDir(void) override;
        int getEnd(void) override;

    private:
        std::array <int, 100> tailX{};
        std::array <int, 100> tailY{};
        int nTail = 0;
        std::vector<std::string> map{};
        int x = 0;
        int y = 0;
        int nextDir = 0;
        int dir = 0;
        int score = 0;
        int end = 0;
        bool isFirst = false;
        bool fruited = false;
};


#endif /* !SNAKE_HPP_ */