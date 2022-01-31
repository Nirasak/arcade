/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-nicolas.allain
** File description:
** snake
*/

#include "include/snake.hpp"

extern "C"
{
    IGameLib *loadLibrary(void)
    {
        return (new snake());
    }
}

snake::snake()
{
    this->setMap(this->stringToVector(this->getFileContent("game/snake/map.txt"), '\n'));
    this->dir = 2;
    this->nextDir = this->dir;
    this->x = 13;
    this->y = 23;
    this->score = 0;
    this->fruited = false;
    this->nTail = 1;
    this->isFirst = true;
    this->end = false;
}

void snake::moveUp(void)
{
    this->nextDir = 0;
}

void snake::moveLeft(void)
{
    this->nextDir = 1;
}

void snake::moveRight(void)
{
   this->nextDir = 2;
}

void snake::moveDown(void)
{
    this->nextDir = 3;
}

int snake::getDir(void)
{
    return (this->dir);
}

int snake::checkDir(char c)
{
    if (c == ' ') {
        return (1);
    }
    if (c == '-' || c == '|') {
        this->end = true;
        return (0);
    }
    if (c == 'o') {
        this->fruited = false;
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

void snake::move(void)
{
    this->tailX[0] = this->x;
    this->tailY[0] = this->y;
    if (this->nextDir == 0 && this->dir != 3 && this->y > 0 && checkDir(this->map[this->y - 1][this->x]))
        this->dir = 0;
    if (this->nextDir == 1 && this->dir != 2 && this->x > 0 && checkDir(this->map[this->y][this->x - 1]))
        this->dir = 1;
    if (this->nextDir == 2 && this->dir != 1 && checkDir(this->map[this->y][this->x + 1]))
        this->dir = 2;
    if (this->nextDir == 3 && this->dir != 0 && checkDir(this->map[this->y + 1][this->x]))
        this->dir = 3;
    if (this->dir == 0 && checkDir(this->map[this->y - 1][this->x])) {
        this->map[this->y - 1][this->x] = '^';
        this->y -= 1;
        this->logic();
    }
    if (this->dir == 1 && checkDir(this->map[this->y][this->x - 1])) {
        this->map[this->y][this->x - 1] = '<';
        this->x -= 1;
        this->logic();
    }
    if (this->dir == 2 && checkDir(this->map[this->y][this->x + 1])) {
        this->map[this->y][this->x + 1] = '>';
        this->x += 1;
        this->logic();
    }
    if (this->dir == 3 && checkDir(this->map[this->y + 1][this->x])) {
        this->map[this->y + 1][this->x] = 'v';
        this->y += 1;
        this->logic();
    }
}

int snake::getScore()
{
    return this->score;
}

void snake::logic()
{
    int randX = 0;
    int randY = 0;

    srand(time(NULL));
    if (!this->fruited && !this->isFirst) {
        this->score += 10;
        if (this->nTail < 99) {
            this->nTail += 1;
        }
    }
    for (int i = this->nTail; i > 0; i--) {
        if (this->tailX[i - 1] != this->tailX[i]) {
            this->map[this->tailY[i - 1]][this->tailX[i - 1]] = '-';
        } else {
            this->map[this->tailY[i - 1]][this->tailX[i - 1]] = '|';
        }
        this->tailX[i] = this->tailX[i - 1];
        this->tailY[i] = this->tailY[i - 1];
    }
    this->map[this->tailY[this->nTail]][this->tailX[this->nTail]] = ' ';
    if (!this->fruited) {
        while (this->map[randY][randX] != ' ') {
            randY = rand() % 25 + 1;
            randX = rand() % 17 + 1;
        }
        this->map[randY][randX] = 'o';
        this->fruited = true;
        this->isFirst = false;
    }
}

std::vector<std::string> snake::stringToVector(std::string list, char separator)
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

std::string snake::getFileContent(const std::string &path)
{
    std::string file_content;
    std::ifstream file_stream(path);
    std::getline(file_stream, file_content, '\0');
    return file_content;
}

std::vector <std::string> snake::getMap() const
{
    return (this->map);
}

void snake::setMap(std::vector <std::string> vec) {
    this->map = vec;
}

int snake::getEnd(void)
{
    return (this->end);
}