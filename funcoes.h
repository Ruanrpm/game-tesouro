#ifndef FUNCOES_H
#define FUNCOES_H
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// função criar mapa;
vector<vector<char>> createMapa(const int, const int);

// função caso o jogador encontre uma mumia
void mumia(int &, string );

// função caso o jogador caia em uma armadilha de pedra
void pedra( string , int &);

// função para armadilha de espinhos;

void espinhos(string, int &);

// função para achar diamantes

void diamante (int &, string );

// função para quando o jogador achar uma pista;

void pista(int const, int const, string, vector<vector<char>> &);

#endif