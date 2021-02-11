#include "../include/FilaEncadeada.hpp"
#include "../include/Node.hpp"

FilaEncadeada::FilaEncadeada(){
    frente = new Node();   
    fim = frente; 
}


void FilaEncadeada::Enfilera(Command dado){
    Node *novo;
    novo = new Node();

    novo->dado = dado;
    fim->proximo = novo;
    fim = novo;
    tamanho++;
}

Command FilaEncadeada::Desenfilera(){
    if(Vazia()){
        throw "ERRO: Fila esta vazia!";
    }
    Command aux;
    Node *p;

    p = frente->proximo;
    frente->proximo = p->proximo;

    aux = p->dado;
    delete p;
    tamanho--;

    return aux;
}

void FilaEncadeada::Limpa(){
    if(Vazia()){
        throw "ERRO: Fila esta vazia!";
    }
    while(!Vazia()){
        Desenfilera();
    }
}