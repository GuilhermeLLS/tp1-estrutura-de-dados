#include <fstream>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "../include/Command.hpp"
#include "../include/FilaEncadeada.hpp"
#include "../include/FilaRobos.hpp"
#include "../include/Robo.hpp"
#include "../include/Base.hpp"

int main(int argc, char *argv[])
{
    std::ifstream mapInput("./exemplos_extras/ex_0/mapa.txt");
    std::string x, y;
    mapInput >> x >> y;
    int linhas = stoi(x);
    int colunas = stoi(y);
    int i = 0, j = 0;
    std::string **map;
    map = (std::string **)malloc(sizeof(std::string *) * linhas);
    for (int i = 0; i < colunas; i++)
    {
        map[i] = (std::string *)malloc(sizeof(std::string) * colunas);
    }
    size_t pos = 0;
    std::string token;
    std::string delimiter = " ";
    for (std::string line; getline(mapInput, line);)
    {
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            map[i][j] = token;
            line.erase(0, pos + delimiter.length());
            i++;
        }
        i = 0;
        j++;
    }

    std::ifstream commandInput("./exemplos_extras/ex_0/comandos.txt");
    FilaEncadeada FilaDeComandos = FilaEncadeada();
    for (std::string line; getline(commandInput, line);)
    {
        int hasPositions = 0;
        Command item = Command();
        std::istringstream teste(line);
        std::string aux;
        while (teste >> aux)
        {
            if (hasPositions == 0)
            {
                item.setNome(aux);
                hasPositions++;
                continue;
            }
            if (hasPositions == 1)
            {
                item.setNumRobo(std::stoi(aux));
                hasPositions++;
                continue;
            }
            if (hasPositions == 2)
            {
                char linhaX = aux.at(1);
                char colunaY = aux.at(3);
                item.setLinhaX(linhaX - '0');
                item.setColunaY(colunaY - '0');
                hasPositions++;
                continue;
            }
            else
            {
                item.setLinhaX(-1);
                item.setColunaY(-1);
                hasPositions++;
            }
        }
        FilaDeComandos.Enfilera(item);
    }
    FilaRobos FilaDeRobosAux = FilaRobos();
    FilaDeRobosAux.CreateRobos();
    Base BaseEspacial = Base();
    BaseEspacial.SetBase(map, linhas, colunas, FilaDeComandos, FilaDeRobosAux);

    while (!BaseEspacial.FileDeComandos.Vazia())
    {
        Command aux = FilaDeComandos.Desenfilera();
        aux.Imprime();
        std::cout << "-----------------" << std::endl;
    }
    return 0;
}