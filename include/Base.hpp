#ifndef BASE_HPP
#define BASE_HPP

#include "../include/FilaEncadeada.hpp"
#include "../include/FilaRobos.hpp"

class Base
{
public:
    Base();
    void SetBase(std::string **mapa, int x, int y, FilaEncadeada FilaDeComandos, FilaRobos Robos);
    void SetRobos(FilaRobos Robos);
    void setMapa(std::string mapa, int x, int y);

    FilaRobos Robos;
    FilaEncadeada FileDeComandos;
    std::string **mapa;
};

#endif