#ifndef ROBO_HPP
#define ROBO_HPP

#include <string>
#include <iostream>
#include <fstream>

class Robo
{
public:
    Robo();
    void SetRobo(int numRobo, int linhaX, int colunaY, bool ativo, std::string relatorio, int totalRecursos, int totalAliens);
    void SetNumRobo(int num);
    void SetCoordenadas(int linhaX, int colunaY);
    void SetAtivo();
    void SetRecursos();
    void SetAliens();
    void SetRelatorio(std::string relatorio);
    void ImprimeRelatorio();

protected:
    int numRobo;
    int linhaX;
    int colunaY;
    bool ativo;
    std::string relatorio;
    int totalRecursos;
    int totalAliens;
};

#endif
