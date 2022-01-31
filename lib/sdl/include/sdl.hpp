/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-nicolas.allain
** File description:
** sdl_manager
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "IGraphicLib.hpp"
#include "exception.hpp"

class SDL_TextureObj {
    public:
        SDL_TextureObj() = default;
        SDL_TextureObj(SDL_Renderer *renderer, const std::string& path) {load(renderer, path);};
        ~SDL_TextureObj() {close();};
        SDL_TextureObj& operator=(const SDL_TextureObj&) = delete;
        SDL_TextureObj(const SDL_TextureObj&) = delete;

        SDL_Texture *get() {return this->obj;};
        void close() noexcept
        {
            if (this->obj != nullptr) {
                SDL_DestroyTexture(this->obj);
                this->obj = nullptr;
            }
        };
        void load(SDL_Renderer *renderer, const std::string& path)
        {
            close();
            if (renderer)
                this->obj = IMG_LoadTexture(renderer, path.c_str());
            if (!this->obj) {
                throw Arcade::exception("error: could not load texture");
            }
        };
    private:
        SDL_Texture *obj = nullptr;
};

class sdl : public IGraphicLib {
    public:
        sdl();
        ~sdl() override = default;
        sdl& operator=(const sdl&) = delete;
        sdl(const sdl&) = delete;

        void createWindow(void) override;
        void closeWindow(void) override;
        int eventWindow(void) override;
        std::string getLibName(void) override;
        int menu(void) override;
        void displayGame(std::vector<std::string> map, int x, std::string actScore) override;
        int changeRectButtonsMenu(void);
        void animPlayer(int x);
        void drawSnake(char c, SDL_Rect pos);
        int getInput(void) override;
    private:
        SDL_Window *window{};
        SDL_Renderer *renderer{};
        SDL_TextureObj tMenu{};
        SDL_TextureObj tButtons{};
        SDL_Rect rNibbler{};
        SDL_Rect rPacman{};
        SDL_Rect rExit{};
        SDL_Rect rPos{};
        int xMouse = 0;
        int yMouse = 0;
        SDL_TextureObj tPlayer{};
        SDL_TextureObj tPlayerSnake{};
        SDL_TextureObj tWall{};
        SDL_TextureObj tLittlePiece{};
        SDL_TextureObj tBigPiece{};
        SDL_TextureObj tFruit{};
        SDL_Rect rPlayer{};
        SDL_Rect rPlayerSnake{};
        int cBegin = 0;
        int cCurrent = 0;
        TTF_Font *font{};
        SDL_Surface* surfMessage{};
        SDL_Texture *textMessage{};
        int input = 0;
};

#endif /* !SDL_HPP_ */
