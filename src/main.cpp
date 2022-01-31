/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "core.hpp"
#include "IGraphicLib.hpp"
#include "exception.hpp"

core::core(int ac, char **)
{
    std::string pName;

    if (ac != 2)
        throw Arcade::exception("Usage: './arcade ./lib/arcade_XXXX.so'");
    std::cout << "Player name: ";
    std::cin >> pName;
    this->setPlayerName(pName);
}

int main(int ac, char **av)
{
    try {
        core arcade(ac, av);
        return (arcade.game(av[1]));
    } catch (const Arcade::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
}