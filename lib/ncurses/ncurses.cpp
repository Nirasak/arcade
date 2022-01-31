/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-nicolas.allain
** File description:
** ncurses
*/

#include <unistd.h>
#include "ncurses.hpp"

extern "C"
{
    IGraphicLib *loadLibrary(void)
    {
        return (new ncurses);
    }
}

ncurses::ncurses()
{
    this->createWindow();
    start_color();
    init_pair(0, 0, 0);
    init_pair(1, 11, 0);
    init_pair(2, 27, 0);
    init_pair(3, 9, 0);
    init_pair(4, 10, 0);
    init_pair(5, 11, 0);
}

std::string ncurses::getLibName(void)
{
    return ("ncurses");
}

void ncurses::createWindow(void)
{
    this->window = initscr();
    noecho();
    nodelay(this->window, TRUE);
    curs_set(false);
    keypad(stdscr, TRUE);
    clear();
    refresh();
}

int ncurses::eventWindow()
{
    int save = 0;

    this->input = -1;
    while ((save = getch()) != -1) {
        this->input = save;
    }
    if (this->input == 'p') {
        this->input = PREVIOUS;
    } else if (this->input == 'n') {
        this->input = NEXT;
    } else if (this->input == 'q') {
        this->input = QUIT;
    } else if (this->input == 27) {
        this->input = ESCAPE;
    } else if (this->input == KEY_UP) {
        this->input = UP;
    } else if (this->input == KEY_LEFT) {
        this->input = LEFT;
    } else if (this->input == KEY_RIGHT) {
        this->input = RIGHT;
    } else if (this->input == KEY_DOWN) {
        this->input = DOWN;
    }
    return (0);
}

int ncurses::getInput(void)
{
    return (this->input);
}

void ncurses::displayMenu(int line, std::string str, int color)
{
    if (color == 1) {
        attron(COLOR_PAIR(1));
        mvprintw(LINES / 2 + line, COLS / 2 - 8, ">");
    }
    mvprintw(LINES / 2 + line, COLS / 2 - 6, str.c_str());
    if (color == 1) {
        attroff(COLOR_PAIR(1));
    }
}

int ncurses::menu(void)
{
    if (this->input == ESCAPE) {
        clear();
    }
    this->eventWindow();
    if (this->input == DOWN || this->input == UP) {
        clear();
    }
    if (this->input == UP && this->menuButton > 1) {
        this->menuButton--;
    }
    if (this->input == DOWN && this->menuButton < 3) {
        this->menuButton++;
    }
    if ((char)this->input == '\n') {
        return (this->menuButton);
    }
    this->displayMenu(-2, "Nibbler", this->menuButton == 1);
    this->displayMenu(0, "Pacman", this->menuButton == 2);
    this->displayMenu(2, "Exit", this->menuButton == 3);
    if (this->input == DOWN || this->input == UP) {
        refresh();
    }
    return (0);
}

void ncurses::displayGame(std::vector<std::string> map, int x, std::string actScore)
{
    int line = 0;

    (void)x;
    clear();
    for (size_t i = 0; i < map.size(); ++i) {
        for (size_t x = 0; x < map[i].size(); ++x) {
            if (map[i][x] == '#')
                attron(COLOR_PAIR(2));
            if (map[i][x] == 'o' || map[i][x] == '.' || map[i][x] == 'O')
                attron(COLOR_PAIR(3));
            if (map[i][x] == '<' || map[i][x] == '>' || map[i][x] == '^' || map[i][x] == 'v' || map[i][x] == '|' || map[i][x] == '-')
                attron(COLOR_PAIR(4));
            if (map[i][x] == 'P') {
                attron(COLOR_PAIR(5));
            }
            mvprintw(LINES / 2 - 15 + line, COLS / 2 - 14 + x, &map[i][x]);
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4));
            attroff(COLOR_PAIR(5));
        }
        line += 1;
    }
    mvprintw(0, 0, "score: ");
    mvprintw(0, 7, actScore.c_str());
    refresh();
}

void ncurses::closeWindow()
{
    clear();
    refresh();
    endwin();
}