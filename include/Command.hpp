#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>

class Command
{
public:
    Command();
    Command(std::string nome, int numRobo, int linhaX, int colunaY);
    Command GetCommand();
    void setNome(std::string nome);
    void setNumRobo(int numRobo);
    void setLinhaX(int linhaX);
    void setColunaY(int colunaY);
    void SetCommand(std::string nome, int numRobo, int linhaX, int colunaY);
    void Imprime();
    std::string GetNome();
    int GetLinhaX();
    int GetColunaY();
    int GetNumRoboCommand();
private:
    std::string nome;
    int numRobo;
    int linhaX;
    int colunaY;
};

#endif