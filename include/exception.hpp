/*
** EPITECH PROJECT, 2021
** zappy workspace (Workspace)
** File description:
** exception
*/

#pragma once

#include <exception>
#include <string>

namespace Arcade
{
    class exception : public std::exception {
        public:
            exception(std::string msg) : m_error(std::move(msg)) {};
            ~exception() = default;

            const char *what() const noexcept override { return m_error.c_str(); };
        private:
            const std::string m_error;
    };
}
