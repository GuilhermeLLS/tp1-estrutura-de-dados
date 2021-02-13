#ifndef BASE_HPP
#define BASE_HPP

#include "../include/FilaEncadeada.hpp"
#include "../include/ListaRobos.hpp"

class Base
{
public:
    Base();
    void SetBase(std::string **mapa, FilaEncadeada FilaDeComandos, ListaRobos Robos);
    void SetRobos(ListaRobos Robos);
    void setMapa(std::string **mapa);

    ListaRobos Robos;
    FilaEncadeada FilaDeComandos;
    std::string **mapa;
};

#endif