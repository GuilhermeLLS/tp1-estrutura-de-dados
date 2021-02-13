#ifndef LISTAROBOS_HPP
#define LISTAROBOS_HPP

#include "Robo.hpp"

class ListaRobos
{
public:
    ListaRobos() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    void IncrementaTamanho() { tamanho++; };
    void DecrementaTamanho() { tamanho--; };
    bool Vazia() { return tamanho == 0; };
    Robo GetDado(int pos);
    void SetRoboActive(int pos);
    void SetDado(Robo dado, int pos);
    void InsereInicio(Robo dado);
    void InsereFinal(Robo dado);
    void InserePosicao(Robo dado, int pos);
    Robo RemoveInicio();
    Robo RemoveFinal();
    Robo RemovePosicao(int pos);
    void Imprime();
    Robo Pesquisa(int chave);
    void Limpa();
    void SetPosicoesRobo(int linha, int coluna, int pos);
    void UpdateRelatorio(std::string message, int pos);
    int GetLinhaXRobo(int pos);
    int GetColunaYRobo(int pos);
    void UpdateTotalRecursos(int valor, int pos);
    void UpdateTotalAliens(int valor, int pos);

protected:
    int tamanho;

private:
    static const int MAXTAM = 50;
    Robo dados[MAXTAM];
};

#endif