#ifndef FILAROBOS_HPP
#define FILAROBOS_HPP

#include "NodeRobo.hpp"

class FilaRobos
{
public:
    FilaRobos();
    int GetTamanho() { return tamanho; };
    void CreateRobos();
    bool Vazia() { return tamanho == 0; };
    void Enfilera(Robo dado);
    Robo Desenfilera();
    void Limpa();

protected:
    int tamanho;

private:
    NodeRobo *frente;
    NodeRobo *fim;
};

#endif
