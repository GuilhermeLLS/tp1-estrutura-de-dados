#include "../include/Base.hpp"
#include "../include/ListaRobos.hpp"
#include "../include/FilaEncadeada.hpp"
#include "../include/Robo.hpp"

Base::Base()
{
    this->FilaDeComandos = FilaEncadeada();
    this->mapa;
    this->Robos = ListaRobos();
}

void Base::SetBase(std::string **mapa, FilaEncadeada FilaDeComandos, ListaRobos Robos)
{
    this->mapa = mapa;
    this->FilaDeComandos = FilaDeComandos;
    this->Robos = Robos;
}

void Base::SetRobos(ListaRobos Robos)
{
    this->Robos = Robos;
}