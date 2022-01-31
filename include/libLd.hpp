/*
** EPITECH PROJECT, 2021
** zappy workspace (Workspace)
** File description:
** libLd
*/

#pragma once
#include "exception.hpp"

template <typename T>
class libLd {
    public:
        libLd() = default;
        ~libLd() {closeLib();};
        libLd& operator=(const libLd&) = delete;
        libLd(const libLd&) = delete;

        void openLib(const char *lib) {
            closeLib();
            m_handler = dlopen(lib, RTLD_NOW);
            if (!m_handler) {
                throw Arcade::exception(dlerror());
            }
            void *sym = dlsym(m_handler, "loadLibrary");
            if (!sym)
                throw Arcade::exception(dlerror());
            m_lib = reinterpret_cast<T *(*)()>(sym)();
        }

        void closeLib() noexcept {
            if (m_lib) {
                delete m_lib;
                m_lib = nullptr;
            }
            if (m_handler) {
                dlclose(m_handler);
                m_handler = nullptr;
            }
        }
        inline T *get() { return m_lib; };
    private:
        T* m_lib = nullptr;
        void *m_handler = nullptr;
};
