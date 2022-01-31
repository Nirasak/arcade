/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sfml_manager
*/

#ifndef SFML_MANAGER_HPP_
#define SFML_MANAGER_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "IGraphicLib.hpp"

class sfml : public IGraphicLib {
    public:
        sfml();
        ~sfml() override = default;

        void createWindow(void) override;
        void closeWindow(void) override;
        int eventWindow(void) override;
        std::string getLibName(void) override;
        int menu(void) override;
        int menuEvent(void);
        void animPlayer(int x);
        void displayGame(std::vector<std::string> map, int x, std::string actScore) override;
        void drawSnake(char c, sf::Vector2f pos);
        int getInput(void) override;

        protected:
        private:
            sf::Font font{};
            sf::RenderWindow window{};
            sf::Texture tMenu{};
            sf::Texture tButtons{};
            sf::IntRect rNibbler{};
            sf::IntRect rPacman{};
            sf::IntRect rExit{};
            sf::Sprite sMenu{};
            sf::Sprite sNibbler{};
            sf::Sprite sPacman{};
            sf::Sprite sExit{};
            sf::Vector2f pNibbler{};
            sf::Vector2f pPacman{};
            sf::Vector2f pExit{};
            sf::Texture tPlayerSnake{};
            sf::IntRect rPlayerSnake{};
            sf::Sprite sPlayerSnake{};
            sf::Texture tPlayer{};
            sf::IntRect rPlayer{};
            sf::Sprite sPlayer{};
            sf::Texture tWall{};
            sf::Sprite sWall{};
            sf::Texture tFruit{};
            sf::Sprite sFruit{};
            sf::Texture tLittlePiece{};
            sf::Sprite sLittlePiece{};
            sf::Texture tBigPiece{};
            sf::Sprite sBigPiece{};
            int input = 0;
};

#endif /* !SFML_MANAGER_HPP_ */
