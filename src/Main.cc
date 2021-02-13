#include <fstream>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "../include/Command.hpp"
#include "../include/FilaEncadeada.hpp"
#include "../include/ListaRobos.hpp"
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

    bool shouldUpdateI = false;
    for (std::string line; getline(mapInput, line);)
    {
        int len = line.length();
        for (int positions = 0; positions < len; positions++)
        {
            char das = line[positions];
            if (das != ' ')
            {
                shouldUpdateI = true;
                map[i][j] = das;
                j++;
            }
        }
        j = 0;
        if (shouldUpdateI)
        {
            i++;
        }
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
    ListaRobos ListaDeRobosAux = ListaRobos();
    for (int i = 0; i < 50; i++)
    {
        Robo lul = Robo();
        lul.SetNumRobo(i);
        ListaDeRobosAux.InsereFinal(lul);
    }
    Base BaseEspacial = Base();
    BaseEspacial.SetBase(map, FilaDeComandos, ListaDeRobosAux);

    while (!BaseEspacial.FilaDeComandos.Vazia())
    {
        Command aux = BaseEspacial.FilaDeComandos.Desenfilera();
        int nRobs = aux.GetNumRoboCommand();
        std::string nomeComando = aux.GetNome();
        if (nomeComando == "ATIVAR")
        {
            BaseEspacial.Robos.SetRoboActive(nRobs);
        }
        if (nomeComando == "MOVER")
        {
            int linha = aux.GetLinhaX();
            int coluna = aux.GetColunaY();
            BaseEspacial.Robos.SetPosicoesRobo(linha, coluna, nRobs);
            std::string elemInPosition = BaseEspacial.mapa[linha][coluna];
            if (elemInPosition == "O")
            {
                BaseEspacial.Robos.UpdateRelatorio("IMPOSSIVEL MOVER PARA (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
            } else {
                BaseEspacial.Robos.UpdateRelatorio("MOVEU PARA (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
            }
        }
        if (nomeComando == "COLETAR") {
            int linha = BaseEspacial.Robos.GetLinhaXRobo(nRobs);
            int coluna = BaseEspacial.Robos.GetColunaYRobo(nRobs);
            std::string elemInPosition = BaseEspacial.mapa[linha][coluna];
            if(elemInPosition == "R" ) {
                BaseEspacial.Robos.UpdateRelatorio("RECURSOS COLETADOS EM (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
                BaseEspacial.Robos.UpdateTotalRecursos(1, nRobs);
                BaseEspacial.mapa[linha][coluna] = ".";
            } else {
                BaseEspacial.Robos.UpdateRelatorio("IMPOSSIVEL COLETAR RECURSOS EM (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
            }
        }
        if(nomeComando == "ELIMINAR") {
            int linha = BaseEspacial.Robos.GetLinhaXRobo(nRobs);
            int coluna = BaseEspacial.Robos.GetColunaYRobo(nRobs);
            std::string elemInPosition = BaseEspacial.mapa[linha][coluna];
            if(elemInPosition == "H") {
                BaseEspacial.Robos.UpdateRelatorio("ALIEN ELIMINADO EM (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
                BaseEspacial.Robos.UpdateTotalAliens(1, nRobs);
                BaseEspacial.mapa[linha][coluna] = ".";
            } else {
                BaseEspacial.Robos.UpdateRelatorio("IMPOSSIVEL ELIMINAR ALIEN EM (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
            }
        }
    }
    BaseEspacial.Robos.Imprime();
    // for (int a = 0; a < linhas; a++)
    // {
    // for (int b = 0; b < colunas; b++)
    // {
    // std::cout << BaseEspacial.mapa[a][b];
    // }
    // std::cout << std::endl;
    // }
    //
    free(map);
    return 0;
}