#include <fstream>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <regex>
#include "../include/Command.hpp"
#include "../include/FilaEncadeada.hpp"
#include "../include/ListaRobos.hpp"
#include "../include/Robo.hpp"
#include "../include/Base.hpp"

bool temOrdemDireta(std::string linha)
{
    std::regex reg("(\\bATIVAR\\b|\\bEXECUTAR\\b|\\bRELATORIO\\b|\\bRETORNAR\\b)(.*)");
    return std::regex_match(linha, reg);
}

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

    // * READ FILE AND UPDATE MAP MATRIX.
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

    // cria filas de ordensDeComando e de ordensDiretas
    FilaEncadeada FilaDeComandos = FilaEncadeada();
    // FilaEncadeada FilaDeOrdensDiretas = FilaEncadeada();
    // Cria lista de robos
    ListaRobos ListaDeRobosAux = ListaRobos();
    for (int i = 0; i < 50; i++)
    {
        Robo lul = Robo();
        lul.SetNumRobo(i);
        ListaDeRobosAux.InsereFinal(lul);
    }

    // Cria base
    Base BaseEspacial = Base();
    BaseEspacial.SetBase(map, FilaDeComandos, ListaDeRobosAux);

    // * READ FILE AND UPDATE FILA DE COMANDOS AND FILA DE ORDENS DIRETAS
    std::ifstream commandInput("./exemplos_extras/ex_0/comandos.txt");
    bool isOrdemDireta;
    for (std::string line; getline(commandInput, line);)
    {
        int hasPositions = 0;
        Command item = Command();
        std::istringstream teste(line);
        std::string aux;
        isOrdemDireta = temOrdemDireta(line);
        while (getline(teste, aux, ' '))
        {
            // nome do comando
            if (hasPositions == 0)
            {
                item.setNome(aux);
                hasPositions++;
                continue;
            }
            // numero do robo
            if (hasPositions == 1)
            {
                item.setNumRobo(std::stoi(aux));
                hasPositions++;
                continue;
            }
            // coordenadas do comando (se existirem)
            if (hasPositions == 2)
            {
                std::istringstream coordenadas(aux);
                std::string coorAux;
                std::regex achaParenteses("(\\(|\\))");
                bool isLinha = true;
                int linhaX;
                int colunaY;
                while (getline(coordenadas, coorAux, ','))
                {
                    std::string result = std::regex_replace(coorAux, achaParenteses, "");
                    if (isLinha)
                    {
                        linhaX = stoi(result);
                        isLinha = false;
                    }
                    else
                    {
                        colunaY = stoi(result);
                    }
                }
                item.setLinhaX(linhaX);
                item.setColunaY(colunaY);
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
        if (isOrdemDireta)
        {
            // item.Imprime();
            // std::cout << "=================" << std::endl;
            BaseEspacial.FilaDeOrdensDiretas.Enfilera(item);
        }
        else
        {
            BaseEspacial.Robos.UpdateOrdensDeComando(item.GetNumRoboCommand(), item);
        }
    }

    // executa fila de ordens diretas
    std::cout << BaseEspacial.FilaDeOrdensDiretas.GetTamanho() << std::endl;
    int tamanhoOrdensDiretas = BaseEspacial.FilaDeOrdensDiretas.GetTamanho();
    while (tamanhoOrdensDiretas > 0)
    {
        std::cout << tamanhoOrdensDiretas << std::endl;
        Command aux = BaseEspacial.FilaDeOrdensDiretas.Desenfilera();
        aux.Imprime();
        int nRobs = aux.GetNumRoboCommand();
        std::string nomeOrdemDireta = aux.GetNome();
        if (nomeOrdemDireta == "ATIVAR")
        {
            BaseEspacial.Robos.SetRoboActive(nRobs);
            BaseEspacial.SetRelatorio("ROBO" + std::to_string(nRobs) + "SAIU EM MISSAO");
        }
        else if (nomeOrdemDireta == "RELATORIO")
        {
            BaseEspacial.Robos.ImprimeRelatorio(nRobs);
        }
        else if (nomeOrdemDireta == "RETORNAR")
        {
            if (BaseEspacial.Robos.isRoboAtivo(nRobs))
            {
                BaseEspacial.SetRelatorio("ROBO" + std::to_string(nRobs) + "RETORNOU" + std::to_string(BaseEspacial.Robos.GetTotalAliens(nRobs)) + "ALIENS" + "RECURSOS" + std::to_string(BaseEspacial.Robos.GetTotalRecursos(nRobs)));
            }
            else
            {
                BaseEspacial.SetRelatorio("ROBO" + std::to_string(nRobs) + "NAO ESTA EM MISSAO");
            }
        }
        // EXECUTA FILA DE ORDENS DE COMANDO
        else if (nomeOrdemDireta == "EXECUTAR")
        {
            FilaEncadeada ordensDeComando = BaseEspacial.Robos.GetOrdensDeComando(nRobs);
            Command *auxCom;
            // unfortunate gambiarra
            int tam = ordensDeComando.GetTamanho();
            std::cout << "ordens de comando tam: " << tam << std::endl;
            while (tam > 0)
            {
                std::cout << "entrei" << std::endl;
                if (tam == 0)
                {
                    std::cout << "bosta" << std::endl;
                    return -1;
                }
                std::cout << ordensDeComando.Vazia() << std::endl;
                // ! the line below line breaks everything
                // auxCom = ordensDeComando.Desenfilera();
                // seja o que deus quiser
                // if (nomeOrdemDireta == "MOVER")
                // {
                // int linha = auxCom.GetLinhaX();
                // int coluna = auxCom.GetColunaY();
                // BaseEspacial.Robos.SetPosicoesRobo(linha, coluna, nRobs);
                // std::string elemInPosition = BaseEspacial.mapa[linha][coluna];
                // if (elemInPosition == "O")
                // {
                // BaseEspacial.Robos.UpdateRelatorio("IMPOSSIVEL MOVER PARA (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
                // }
                // else
                // {
                // BaseEspacial.Robos.UpdateRelatorio("MOVEU PARA (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
                // }
                // }
                // if (nomeOrdemDireta == "COLETAR")
                // {
                // int linha = BaseEspacial.Robos.GetLinhaXRobo(nRobs);
                // int coluna = BaseEspacial.Robos.GetColunaYRobo(nRobs);
                // std::string elemInPosition = BaseEspacial.mapa[linha][coluna];
                // if (elemInPosition == "R")
                // {
                // BaseEspacial.Robos.UpdateRelatorio("RECURSOS COLETADOS EM (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
                // BaseEspacial.Robos.UpdateTotalRecursos(1, nRobs);
                // BaseEspacial.UpdateTotalRecursosBase(1);
                // BaseEspacial.mapa[linha][coluna] = ".";
                // }
                // else
                // {
                // BaseEspacial.Robos.UpdateRelatorio("IMPOSSIVEL COLETAR RECURSOS EM (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
                // }
                // }
                // if (nomeOrdemDireta == "ELIMINAR")
                // {
                // int linha = BaseEspacial.Robos.GetLinhaXRobo(nRobs);
                // int coluna = BaseEspacial.Robos.GetColunaYRobo(nRobs);
                // std::string elemInPosition = BaseEspacial.mapa[linha][coluna];
                // if (elemInPosition == "H")
                // {
                // BaseEspacial.Robos.UpdateRelatorio("ALIEN ELIMINADO EM (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
                // BaseEspacial.Robos.UpdateTotalAliens(1, nRobs);
                // BaseEspacial.UpdateTotalAliensBase(1);
                // BaseEspacial.mapa[linha][coluna] = ".";
                // }
                // else
                // {
                // BaseEspacial.Robos.UpdateRelatorio("IMPOSSIVEL ELIMINAR ALIEN EM (" + std::to_string(linha) + "," + std::to_string(coluna) + ")", nRobs);
                // }
                // }
                tam--;
            }
        }
        tamanhoOrdensDiretas--;
    }
    // BaseEspacial.Robos.Imprime();

    free(map);
    return 0;
}