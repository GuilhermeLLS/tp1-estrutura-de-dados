#include "../include/Base.hpp"
#include "../include/FilaRobos.hpp"
#include "../include/FilaEncadeada.hpp"
#include "../include/Robo.hpp"

Base::Base()
{
    this->FileDeComandos = FilaEncadeada();
    this->mapa;
    this->Robos = FilaRobos();
}

void Base::SetBase(std::string **mapa, int x, int y, FilaEncadeada FilaDeComandos, FilaRobos Robos)
{
    mapa = (std::string **)malloc(sizeof(std::string *) * x);
    for (int i = 0; i < y; i++)
    {
        mapa[i] = (std::string *)malloc(sizeof(std::string) * y);
    }
    this->mapa = mapa;
    this->FileDeComandos = FilaDeComandos;
    this->Robos = Robos;
}

void Base::SetRobos(FilaRobos Robos)
{
    this->Robos = Robos;
}