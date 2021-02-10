#include <fstream>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "../include/Command.hpp"
#include "../include/FilaEncadeada.hpp"

int main(int argc, char *argv[])
{
    std::ifstream mapInput("./exemplos_extras/ex_0/mapa.txt");
    std::string x, y;
    mapInput >> x >> y;
    int i = 0, j = 0;
    std::string map[std::stoi(x)][std::stoi(y)];
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
        std::cout << teste.width() << std::endl;
        while(teste >> aux) {
            if (hasPositions == 1) {
                item.setNome(aux);
            }
            if (hasPositions == 2) {
                item.setNumRobo(std::stoi(aux));
            }
            if (hasPositions == 3) {
                int linhaX = aux.at(1);
                int colunaY = aux.at(3);
                item.setLinhaX(linhaX);
                item.setColunaY(colunaY);
            } else {
                item.setLinhaX(-1);
                item.setColunaY(-1);
            }
            hasPositions++;
        }
        FilaDeComandos.Enfilera(item);
        // std::cout << line << std::endl;

    }
    return 0;
}