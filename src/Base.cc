#include "../include/Base.hpp"
#include "../include/ListaRobos.hpp"
#include "../include/FilaEncadeada.hpp"
#include "../include/Robo.hpp"

Base::Base()
{
    this->FilaDeOrdensDiretas = FilaEncadeada();
    this->mapa;
    this->Robos = ListaRobos();
}

void Base::SetBase(std::string **mapa, FilaEncadeada FilaDeOrdensDiretas, ListaRobos Robos)
{
    this->mapa = mapa;
    this->FilaDeOrdensDiretas = FilaDeOrdensDiretas;
    this->Robos = Robos;
}

void Base::SetRobos(ListaRobos Robos)
{
    this->Robos = Robos;
}

void Base::SetRelatorio(std::string relatorio)
{
    this->relatorio = this->relatorio + relatorio + ";";
}

void Base::SetMapa(std::string **mapa) { this->mapa = mapa; }

void Base::ImprimeRelatorio()
{
    std::string relatorioAux = this->relatorio;
    std::cout << "TODO: IMPRIMIR RELATORIO" << std::endl;
}

int Base::GetTotalAliensBase() { return this->totalAliens; }

int Base::GetTotalRecursosBase() { return this->totalRecursos; }

void Base::UpdateTotalAliensBase(int valor) { this->totalAliens += valor; }

void Base::UpdateTotalRecursosBase(int valor) { this->totalRecursos += valor; }
