#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>

class Command
{
public:
    Command();
    Command(std::string nome, int numRobo, int linhaX, int colunaY);
    int GetChave();
    void SetChave(std::string nome, int numRobo, int linhaX, int colunaY);
    void Imprime();

private:
    std::string nome;
    int numRobo;
    int linhaX;
    int colunaY;
};

#endif