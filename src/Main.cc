#include <fstream>
#include <string>
#include <iostream>
#include "../include/Command.hpp"
#include "../include/FilaEncadeada.hpp"

int main(int argc, char *argv[])
{
    std::ifstream mapInput("./exemplos_extras/ex_0/mapa.txt");
    std::string x, y;
    mapInput >> x >> y;
    int i = 0, j = 0;
    std::string map[std::stoi(x)][std::stoi(y)];
    std::cout << x << " " << y << std::endl;
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
    return 0;

    std::ifstream commandInput("./exemplos_extras/ex_0/comandos.txt");
    FilaEncadeada FilaDeComandos = FilaEncadeada();
    for (std::string line; getline(commandInput, line);)
    {
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            std::cout << token << std::endl;
            line.erase(0, pos + delimiter.length());
        }
    }
}