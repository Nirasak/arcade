/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sfml_manager
*/

#include "sfml.hpp"
#include "exception.hpp"

extern "C"
{
    IGraphicLib *loadLibrary(void)
    {
        return (new sfml());
    }
}

sfml::sfml()
{
    this->createWindow();
    if (!this->tMenu.loadFromFile("assets/menu.png")
        || !this->tButtons.loadFromFile("assets/menuButtons.png")
        || !this->tPlayer.loadFromFile("assets/pacman.png")
        || !this->tPlayerSnake.loadFromFile("assets/snake.png")
        || !this->tWall.loadFromFile("assets/wall.png")
        || !this->tLittlePiece.loadFromFile("assets/littlePiece.png")
        || !this->tFruit.loadFromFile("assets/Fruit.png")
        || !this->tBigPiece.loadFromFile("assets/bigPiece.png")) {
        throw Arcade::exception("Error: loading asset failed");
    }
    this->sMenu.setTexture(this->tMenu);
    this->sMenu.setPosition(sf::Vector2f(0, 0));
    this->sNibbler.setTexture(this->tButtons);
    this->sPacman.setTexture(this->tButtons);
    this->sExit.setTexture(this->tButtons);
    this->pNibbler.x = 700;
    this->pNibbler.y = 400;
    this->pPacman.x = 700;
    this->pPacman.y = 499;
    this->pExit.x = 700;
    this->pExit.y = 598;
    this->rNibbler.left = 520;
    this->rNibbler.top = 0;
    this->rNibbler.height = 84;
    this->rNibbler.width = 520;
    this->rPacman.left = 1040;
    this->rPacman.top = 0;
    this->rPacman.height = 84;
    this->rPacman.width = 520;
    this->rExit.left = 0;
    this->rExit.top = 0;
    this->rExit.height = 84;
    this->rExit.width = 520;
    this->sNibbler.setTexture(this->tButtons);
    this->sPacman.setTexture(this->tButtons);
    this->sExit.setTexture(this->tButtons);
    this->sNibbler.setPosition(this->pNibbler);
    this->sPacman.setPosition(this->pPacman);
    this->sExit.setPosition(this->pExit);
    this->sNibbler.setTextureRect(this->rNibbler);
    this->sPacman.setTextureRect(this->rPacman);
    this->sExit.setTextureRect(this->rExit);
    this->sPlayer.setTexture(this->tPlayer);
    this->sPlayerSnake.setTexture(this->tPlayerSnake);
    this->sWall.setTexture(this->tWall);
    this->sFruit.setTexture(this->tFruit);
    this->sLittlePiece.setTexture(this->tLittlePiece);
    this->sBigPiece.setTexture(this->tBigPiece);
    this->rPlayer.left = 0;
    this->rPlayer.top = 0;
    this->rPlayer.width = 30;
    this->rPlayer.height = 30;
    this->sPlayer.setTextureRect(this->rPlayer);
    this->rPlayerSnake.left = 80;
    this->rPlayerSnake.top = 0;
    this->rPlayerSnake.width = 30;
    this->rPlayerSnake.height = 30;
    this->sPlayerSnake.setTextureRect(this->rPlayerSnake);
    this->font.loadFromFile("assets/arial.ttf");
}

std::string sfml::getLibName(void)
{
    return ("sfml");
}

int sfml::eventWindow(void)
{
    sf::Event event;

    this->input = -1;
    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->input = QUIT;
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                this->input = UP;
            } else if (event.key.code == sf::Keyboard::Left) {
                this->input = LEFT;
            } else if (event.key.code == sf::Keyboard::Right) {
                this->input = RIGHT;
            } else if (event.key.code == sf::Keyboard::Down) {
                this->input = DOWN;
            } else if (event.key.code == sf::Keyboard::Escape) {
                this->input = ESCAPE;
            } else if (event.key.code == sf::Keyboard::N) {
                this->input = NEXT;
            } else if (event.key.code == sf::Keyboard::P) {
                this->input = PREVIOUS;
            } else if (event.key.code == sf::Keyboard::Q) {
                this->input = QUIT;
            }
        }
    }
    return (0);
}

int sfml::getInput(void)
{
    return (this->input);
}

int sfml::menuEvent(void)
{
    sf::Vector2i pMouse = sf::Mouse::getPosition(this->window);

    if (pMouse.x >= this->pNibbler.x && pMouse.x <= this->pNibbler.x + this->rNibbler.width
    && pMouse.y >= this->pNibbler.y && pMouse.y <= this->pNibbler.y + this->rNibbler.height) {
        this->rNibbler.top = 90;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->rNibbler.top = 180;
            return (1);
        }
    } else {
        this->rNibbler.top = 0;
    }
    if (pMouse.x >= this->pPacman.x && pMouse.x <= this->pPacman.x + this->rPacman.width
    && pMouse.y >= this->pPacman.y && pMouse.y <= this->pPacman.y + this->rPacman.height) {
        this->rPacman.top = 90;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->rPacman.top = 180;
            return (2);
        }
    } else {
        this->rPacman.top = 0;
    }
    if (pMouse.x >= this->pExit.x && pMouse.x <= this->pExit.x + this->rExit.width
    && pMouse.y >= this->pExit.y && pMouse.y <= this->pExit.y + this->rExit.height) {
        this->rExit.top = 90;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->rExit.top = 180;
            return (3);
        }
    } else {
        this->rExit.top = 0;
    }
    return (0);
}

int sfml::menu(void)
{
    int ret = this->menuEvent();

    this->eventWindow();
    this->sNibbler.setTextureRect(this->rNibbler);
    this->sPacman.setTextureRect(this->rPacman);
    this->sExit.setTextureRect(this->rExit);
    this->window.clear();
    this->window.draw(this->sMenu);
    this->window.draw(this->sNibbler);
    this->window.draw(this->sPacman);
    this->window.draw(this->sExit);
    this->window.display();
    return (ret);
}

void sfml::animPlayer(int x)
{
    this->rPlayer.top += 40;
    if (this->rPlayer.top > 80) {
        this->rPlayer.top = 0;
    }
    if (x == 0) {
        this->rPlayer.left = 120;
    } else if (x == 1) {
        this->rPlayer.left = 80;
    } else if (x == 2) {
        this->rPlayer.left = 0;
    } else if (x == 3) {
        this->rPlayer.left = 40;
    }
    this->sPlayer.setTextureRect(this->rPlayer);
}

void sfml::drawSnake(char c, sf::Vector2f pos)
{
    if (c == '^') {
        this->rPlayerSnake.left = 0;
        this->rPlayerSnake.top = 0;
    } else if (c == '<') {
        this->rPlayerSnake.left = 40;
        this->rPlayerSnake.top = 0;
    } else if (c == '>') {
        this->rPlayerSnake.left = 80;
        this->rPlayerSnake.top = 0;
    } else if (c == 'v') {
        this->rPlayerSnake.left = 120;
        this->rPlayerSnake.top = 0;
    } else if (c == '|') {
        this->rPlayerSnake.left = 160;
        this->rPlayerSnake.top = 40;
    } else {
        this->rPlayerSnake.left = 160;
        this->rPlayerSnake.top = 0;
    }
    this->sPlayerSnake.setTextureRect(this->rPlayerSnake);
    this->sPlayerSnake.setPosition(pos);
    this->window.draw(this->sPlayerSnake);
}

void sfml::displayGame(std::vector<std::string> map, int x, std::string actScore)
{
    sf::Vector2f pos;
    const char *line;
    int i = 0;
    sf::Text text;
    text.setFont(font);
    text.setString("Score: " + actScore);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);

    this->animPlayer(x);
    this->window.clear();
    for (auto x = map.begin(); x != map.end(); ++x) {
        line = x->c_str();
        for (int j = 0; line[j]; ++j) {
            pos.y = 50 + i * 30;
            pos.x = 540 + j * 30;
            if (line[j] == '#') {
                this->sWall.setPosition(pos);
                this->window.draw(this->sWall);
            } else if (line[j] == '.') {
                this->sLittlePiece.setPosition(pos);
                this->window.draw(this->sLittlePiece);
            } else if (line[j] == 'O') {
                this->sBigPiece.setPosition(pos);
                this->window.draw(this->sBigPiece);
            } else if (line[j] == 'P') {
                this->sPlayer.setPosition(pos);
                this->window.draw(this->sPlayer);
            } else if (line[j] == 'o') {
                this->sFruit.setPosition(pos);
                this->window.draw(this->sFruit);
            } else if (line[j] != ' ' && line[j] != 'T') {
                this->drawSnake(line[j], pos);
            }
        }
        ++i;
    }
    this->window.draw(text);
    this->window.display();
}

void sfml::createWindow()
{
    this->window.create(sf::VideoMode(1920, 1080), "SFML Mode");
    this->window.clear();
    this->window.display();
}

void sfml::closeWindow()
{
    this->window.close();
}
