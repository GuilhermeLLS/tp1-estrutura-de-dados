#include "../include/Robo.hpp"

Robo::Robo()
{
    this->numRobo = 0;
    this->linhaX = 0;
    this->colunaY = 0;
    this->ativo = false;
    this->relatorio = "";
    this->totalRecursos = 0;
    this->totalAliens = 0;
}

void Robo::SetRobo(int numRobo, int linhaX, int colunaY, bool ativo, std::string relatorio, int totalRecursos, int totalAliens)
{
    this->numRobo = numRobo;
    this->linhaX = linhaX;
    this->colunaY = colunaY;
    this->ativo = ativo;
    this->relatorio = relatorio;
    this->totalRecursos = totalRecursos;
    this->totalAliens = totalAliens;
}

void Robo::SetNumRobo(int numRobo)
{
    this->numRobo = numRobo;
}

void Robo::SetCoordenadas(int linhaX, int colunaY)
{
    this->linhaX = linhaX;
    this->colunaY = colunaY;
}

void Robo::SetAtivo()
{
    this->ativo = !this->ativo;
}

void Robo::SetRecursos()
{
    this->totalRecursos++;
}

void Robo::SetAliens()
{
    this->totalAliens++;
}

void Robo::SetRelatorio(std::string relatorio)
{
    this->relatorio = this->relatorio + relatorio + ";";
}

void Robo::ImprimeRelatorio()
{
    std::string delimiter = ";";
    std::string aux = this->relatorio;
    size_t pos = 0;
    std::string token;
    std::ofstream file("saida.txt");
    while ((pos = aux.find(delimiter)) != std::string::npos)
    {
        token = aux.substr(0, pos);
        std::cout << token << std::endl;
        file << token;
        aux.erase(0, pos + delimiter.length());
    }
    file.close();
}