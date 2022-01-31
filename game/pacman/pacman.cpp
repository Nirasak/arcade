/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-nicolas.allain
** File description:
** pacman
*/

#include "include/pacman.hpp"

extern "C"
{
    IGameLib *loadLibrary(void)
    {
        return (new pacman());
    }
}

pacman::pacman()
{
    this->setMap(this->stringToVector(this->getFileContent("game/pacman/pacman.txt"), '\n'));
    this->dir = 2;
    this->nextDir = this->dir;
    this->x = 13;
    this->y = 23;
    this->score = 0;
    this->end = false;
}

void pacman::moveUp(void)
{
    this->nextDir = 0;
}

void pacman::moveLeft(void)
{
    this->nextDir = 1;
}

void pacman::moveRight(void)
 {
    this->nextDir = 2;
 }

void pacman::moveDown(void)
{
    this->nextDir = 3;
}

int pacman::getDir(void)
{
    return (this->dir);
}

int pacman::checkDir(char c)
{
    if (this->score >= 1946) {
        this->end = true;
        return (0);
    }
    if (c == '.') {
        this->score += 2;
    } else if (c == 'O') {
        this->score += 100;
    }
    if (c == '.' || c == ' ' || c == 'O') {
        return (1);
    }
    if (c == 'T' && this->dir == 1) {
        this->map[this->y][this->x] = ' ';
        this->x = 25;
    } else if (c == 'T') {
        this->map[this->y][this->x] = ' ';
        this->x = 2;
    }
    return (0);
}

void pacman::move(void)
{
    if (this->nextDir == 0 && this->y > 0 && checkDir(this->map[this->y - 1][this->x]))
        this->dir = 0;
    if (this->nextDir == 1 && this->x > 0 && checkDir(this->map[this->y][this->x - 1]))
        this->dir = 1;
    if (this->nextDir == 2 && checkDir(this->map[this->y][this->x + 1]))
        this->dir = 2;
    if (this->nextDir == 3 && checkDir(this->map[this->y + 1][this->x]))
        this->dir = 3;
    if (this->dir == 0 && checkDir(this->map[this->y - 1][this->x])) {
        this->map[this->y - 1][this->x] = 'P';
        this->map[this->y][this->x] = ' ';
        this->y -= 1;
    }
    if (this->dir == 1 && checkDir(this->map[this->y][this->x - 1])) {
        this->map[this->y][this->x - 1] = 'P';
        this->map[this->y][this->x] = ' ';
        this->x -= 1;
    }
    if (this->dir == 2 && checkDir(this->map[this->y][this->x + 1])) {
        this->map[this->y][this->x + 1] = 'P';
        this->map[this->y][this->x] = ' ';
        this->x += 1;
    }
    if (this->dir == 3 && checkDir(this->map[this->y + 1][this->x])) {
        this->map[this->y + 1][this->x] = 'P';
        this->map[this->y][this->x] = ' ';
        this->y += 1;
    }
}

int pacman::getScore()
{
    return this->score;
}

std::vector<std::string> pacman::stringToVector(std::string list, char separator)
{
   std::vector<std::string> array;
    std::string temp;
    size_t len = list.size();

    for (size_t i = 0; i < len; i++) {
        if (list[i] == separator) {
            if (!temp.empty()) {
                array.push_back(temp);
                temp.clear();
            }
        }
        else
            temp.push_back(list[i]);
    }
    if (!temp.empty())
        array.push_back(temp);
    return array;
}

std::string pacman::getFileContent(const std::string &path)
{
    std::string file_content;
    std::ifstream file_stream(path);
    std::getline(file_stream, file_content, '\0');
    return file_content;
}

std::vector <std::string> pacman::getMap() const
{
    return (this->map);
}

void pacman::setMap(std::vector <std::string> vec) {
    this->map = vec;
}

int pacman::getEnd(void)
{
    return (this->end);
}