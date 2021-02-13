#include "../include/Command.hpp"

Command::Command()
{
    this->nome = "";
    this->numRobo = -1;
    this->linhaX = -1;
    this->colunaY = -1;
}

Command::Command(std::string nome, int numRobo, int linhaX, int colunaY)
{
    this->nome = nome;
    this->numRobo = numRobo;
    this->linhaX = linhaX;
    this->colunaY = colunaY;
}

int Command::GetNumRoboCommand()
{
    return this->numRobo;
}

int Command::GetLinhaX()
{
    return this->linhaX;
}

int Command::GetColunaY()
{
    return this->colunaY;
}

std::string Command::GetNome()
{
    return this->nome;
}

Command Command::GetCommand()
{
    std::string nome = this->nome;
    int numRobo = this->numRobo;
    int linhaX = this->linhaX;
    int colunaY = this->colunaY;
    return Command(nome, numRobo, linhaX, colunaY);
}
void Command::setNome(std::string nome) { this->nome = nome; }
void Command::setNumRobo(int numRobo) { this->numRobo = numRobo; }
void Command::setLinhaX(int linhaX) { this->linhaX = linhaX; }
void Command::setColunaY(int colunaY) { this->colunaY = colunaY; }

void Command::SetCommand(std::string nome, int numRobo, int linhaX, int colunaY)
{
    this->nome = nome;
    this->numRobo = numRobo;
    this->linhaX = linhaX;
    this->colunaY = colunaY;
}

void Command::Imprime()
{
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "numRobo: " << this->numRobo << std::endl;
    std::cout << "linhaX: " << this->linhaX << std::endl;
    std::cout << "colunaY: " << this->colunaY << std::endl;
}