#include "../include/FilaRobos.hpp"
#include "../include/NodeRobo.hpp"

FilaRobos::FilaRobos(){
    frente = new NodeRobo();   
    fim = frente; 
}


void FilaRobos::Enfilera(Robo dado){
    NodeRobo *novo;
    novo = new NodeRobo();

    novo->dado = dado;
    fim->proximo = novo;
    fim = novo;
    tamanho++;
}

void FilaRobos::CreateRobos()
{
    Robo aux = Robo();
    for (int i = 0; i < 50; i++)
    {
        aux.SetNumRobo(i);
        Enfilera(aux);
    }
}


Robo FilaRobos::Desenfilera(){
    if(Vazia()){
        throw "ERRO: Fila esta vazia!";
    }
    Robo aux;
    NodeRobo *p;

    p = frente->proximo;
    frente->proximo = p->proximo;

    aux = p->dado;
    delete p;
    tamanho--;

    return aux;
}

void FilaRobos::Limpa(){
    if(Vazia()){
        throw "ERRO: Fila esta vazia!";
    }
    while(!Vazia()){
        Desenfilera();
    }
}