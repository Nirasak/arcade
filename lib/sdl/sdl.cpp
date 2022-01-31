/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-nicolas.allain
** File description:
** createWindow
*/

#include "sdl.hpp"
#include "exception.hpp"

extern "C"
{
    IGraphicLib *loadLibrary(void)
    {
        return (new sdl);
    }
}

sdl::sdl()
{
    this->createWindow();
}

std::string sdl::getLibName(void)
{
    return ("sdl");
}

void sdl::createWindow(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "Erreur d'initialisation de la SDL : " << SDL_GetError() << "\n";
        throw Arcade::exception("error: can't init SDL");
    }
    this->window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        std::cout << "Could not create window: " << SDL_GetError() << "\n";
        throw Arcade::exception("error: can't create window in SDL");
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, 0);
    this->tMenu.load(this->renderer, "assets/menu.png");
    this->tButtons.load(this->renderer, "assets/menuButtons.png");
    this->rNibbler.x = 520;
    this->rNibbler.y = 0;
    this->rNibbler.h = 84;
    this->rNibbler.w = 520;
    this->rPacman.x = 1040;
    this->rPacman.y = 0;
    this->rPacman.h = 84;
    this->rPacman.w = 520;
    this->rExit.x = 0;
    this->rExit.y = 0;
    this->rExit.h = 84;
    this->rExit.w = 520;
    this->rPos.x = 700;
    this->rPos.y = 400;
    this->rPos.h = 84;
    this->rPos.w = 520;
    this->tPlayer.load(this->renderer, "assets/pacman.png");
    this->tPlayerSnake.load(this->renderer, "assets/snake.png");
    this->tWall.load(this->renderer, "assets/wall.png");
    this->tLittlePiece.load(this->renderer, "assets/littlePiece.png");
    this->tBigPiece.load(this->renderer, "assets/bigPiece.png");
    this->tFruit.load(this->renderer, "assets/Fruit.png");
    this->rPlayer.x = 0;
    this->rPlayer.y = 0;
    this->rPlayer.h = 30;
    this->rPlayer.w = 30;
    this->rPlayerSnake.x = 0;
    this->rPlayerSnake.y = 0;
    this->rPlayerSnake.h = 30;
    this->rPlayerSnake.w = 30;
    this->cBegin = SDL_GetTicks();
    this->xMouse = 0;
    this->yMouse = 0;
    TTF_Init();
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        throw Arcade::exception("error: can't init TTF SDL");
    }
    this->font = TTF_OpenFont("assets/arial.ttf", 50);
}

int sdl::eventWindow(void)
{
    SDL_Event event{};

    this->input = -1;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
            this->input = QUIT;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p) {
            this->input = PREVIOUS;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_n) {
            this->input = NEXT;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            this->input = ESCAPE;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q) {
            this->input = QUIT;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP) {
            this->input = UP;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT) {
            this->input = LEFT;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT) {
            this->input = RIGHT;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN) {
            this->input = DOWN;
        }
        if (event.type == SDL_MOUSEMOTION) {
            SDL_GetMouseState(&this->xMouse, &this->yMouse);
        }
    }
    return (0);
}

int sdl::getInput(void)
{
    return (this->input);
}

int sdl::changeRectButtonsMenu(void)
{
    if (this->xMouse >= this->rPos.x && this->xMouse <= this->rPos.x + this->rNibbler.w
        && this->yMouse >= 400 && this->yMouse <= 400 + this->rNibbler.h) {
        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            this->rNibbler.y = 180;
            return (1);
        } else {
            this->rNibbler.y = 90;
        }
    } else {
        this->rNibbler.y = 0;
    }
    if (this->xMouse >= this->rPos.x && this->xMouse <= this->rPos.x + this->rPacman.w
        && this->yMouse >= 499 && this->yMouse <= 499 + this->rPacman.h) {
        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            this->rPacman.y = 180;
            return (2);
        } else {
            this->rPacman.y = 90;
        }
    } else {
        this->rPacman.y = 0;
    }
    if (this->xMouse >= this->rPos.x && this->xMouse <= this->rPos.x + this->rExit.w
        && this->yMouse >= 598 && this->yMouse <= 598 + this->rExit.h) {
        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            this->rExit.y = 180;
            return (3);
        } else {
            this->rExit.y = 90;
        }
    } else {
        this->rExit.y = 0;
    }
    return (0);
}

int sdl::menu(void)
{
    int ret = this->changeRectButtonsMenu();

    this->eventWindow();
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
    SDL_RenderCopy(this->renderer, this->tMenu.get(), NULL, NULL);
    this->rPos.y = 400;
    SDL_RenderCopy(this->renderer, this->tButtons.get(), &this->rNibbler, &this->rPos);
    this->rPos.y += 99;
    SDL_RenderCopy(this->renderer, this->tButtons.get(), &this->rPacman, &this->rPos);
    this->rPos.y += 99;
    SDL_RenderCopy(this->renderer, this->tButtons.get(), &this->rExit, &this->rPos);
    SDL_RenderPresent(this->renderer);
    return (ret);
}

void sdl::animPlayer(int x)
{
    this->rPlayer.y += 40;
    if (this->rPlayer.y > 80) {
        this->rPlayer.y = 0;
    }
    if (x == 0) {
        this->rPlayer.x = 120;
    } else if (x == 1) {
        this->rPlayer.x = 80;
    } else if (x == 2) {
        this->rPlayer.x = 0;
    } else if (x == 3) {
        this->rPlayer.x = 40;
    }
}

void sdl::drawSnake(char c, SDL_Rect pos)
{
    if (c == '^') {
        this->rPlayerSnake.x = 0;
        this->rPlayerSnake.y = 0;
    } else if (c == '<') {
        this->rPlayerSnake.x = 40;
        this->rPlayerSnake.y = 0;
    } else if (c == '>') {
        this->rPlayerSnake.x = 80;
        this->rPlayerSnake.y = 0;
    } else if (c == 'v') {
        this->rPlayerSnake.x = 120;
        this->rPlayerSnake.y = 0;
    } else if (c == '|') {
        this->rPlayerSnake.x = 160;
        this->rPlayerSnake.y = 40;
    } else {
        this->rPlayerSnake.x = 160;
        this->rPlayerSnake.y = 0;
    }
    SDL_RenderCopy(this->renderer, this->tPlayerSnake.get(), &this->rPlayerSnake, &pos);
}

void sdl::displayGame(std::vector<std::string> map, int x, std::string actScore)
{
    SDL_Rect posWindow;
    SDL_Color white = {255, 255, 255, 0};
    std::string score("Score: ");
    SDL_Rect posScore = {0, 0, 200, 55};
    const char *line;
    int i = 0;

    this->animPlayer(x);
    posWindow.h = 30;
    posWindow.w = 30;
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
    this->surfMessage = TTF_RenderText_Blended(this->font, score.append(actScore).c_str(), white);
    this->textMessage = SDL_CreateTextureFromSurface(renderer, surfMessage);
    SDL_RenderCopy(this->renderer, this->textMessage, NULL, &posScore);
    for (auto x = map.begin(); x != map.end(); ++x) {
        line = x->c_str();
        for (int j = 0; line[j]; ++j) {
            posWindow.y = 50 + i * 30;
            posWindow.x = 540 + j * 30;
            if (line[j] == '#') {
                SDL_RenderCopy(this->renderer, this->tWall.get(), NULL, &posWindow);
            } else if (line[j] == '.') {
                SDL_RenderCopy(this->renderer, this->tLittlePiece.get(), NULL, &posWindow);
            } else if (line[j] == 'O') {
                SDL_RenderCopy(this->renderer, this->tBigPiece.get(), NULL, &posWindow);
            } else if (line[j] == 'P') {
                SDL_RenderCopy(this->renderer, this->tPlayer.get(), &this->rPlayer, &posWindow);
            } else if (line[j] == 'o') {
                SDL_RenderCopy(this->renderer, this->tFruit.get(), NULL, &posWindow);
            } else if (line[j] != ' ' && line[j] != 'T') {
                drawSnake(line[j], posWindow);
            }
        }
        ++i;
    }
    SDL_RenderPresent(this->renderer);
}

void sdl::closeWindow(void)
{
    this->tMenu.close();
    this->tPlayer.close();
    this->tPlayerSnake.close();
    this->tWall.close();
    this->tBigPiece.close();
    this->tButtons.close();
    this->tFruit.close();
    this->tLittlePiece.close();
    SDL_DestroyTexture(this->textMessage);
    TTF_CloseFont(this->font);
    TTF_Quit();
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    atexit(SDL_Quit);
}