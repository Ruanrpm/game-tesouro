#include "funcoes.h"

using namespace std;

// função criar mapa;
vector<vector<char>> createMapa(const int linhas, const int colunas) {   
    vector<vector<char>> mapa(linhas, vector<char>(colunas, 79));
    int quantidadesMob = static_cast<int>(ceil((linhas * colunas) * 0.20));
    int diamantesTotal = static_cast<int>(ceil((linhas * colunas) * 0.40));
    // Adiciona mobs e armadilhas
    int aux = 0;
    while (aux < quantidadesMob) {
        int I = rand() % linhas;
        int J = rand() % colunas;
        int armadilha = 2 + (rand() % (4 - 2 + 1));

        if (mapa[I][J] == 79) {
            mapa[I][J] = armadilha;
            aux++;
        }
    }

    // Adiciona bufs e algo mais    
    aux = 0;
    while (aux < 2) {
        int I = rand() % linhas;
        int J = rand() % colunas;

        if (mapa[I][J] == 79) {
            mapa[I][J] = mapa[I][J] = 5;
            aux++;
        }
    }
    aux = 0;
    while (aux < diamantesTotal) {
        int I = rand() % linhas;
        int J = rand() % colunas;

        if (mapa[I][J] == 79) {
            mapa[I][J] = mapa[I][J] = 36;
            aux++;
        }
    }

    return mapa;
}

// função caso o jogador encontre uma mumia
void mumia(int &quilates, string players) {
    char luta;
    cout << players<< " Voce encontrou uma mumia quer tentar lutar com ela para roubar a sua bolsa de diamantes?(S)(N): ";
    cin >> luta;
    cout << endl;
    srand(time(0));

    if (luta == 'S') {
        int lutando = rand() % 10 + 1;
        if (lutando >= 5) {
            int tesouro = rand() % 50 +1;
            if (tesouro == 49) {
                cout << players<< " Voce derrotou a mumia e achou um mapa do tesouro na bolsa dela +10000000000 quilates adicionados ao inventario." << endl;
                quilates+=10000000000;
            }
            else {
                cout << players<< " Voce derrotou a mumia e na bolsa dela tinha 1 diamante de 20 quilates." << endl;
                    quilates+=20;
            }
        }
        else {
            if (quilates> 0){
                quilates=0;
                cout << players << " A mumia te derrotou e roubou todos os seus diamantes" << endl;
            }
            else{
                cout << players << " A mumia te derrotou" << endl;
            }
        }
    }
    else {
        cout << "A mumia se afastou" << endl;
    }
}

// função caso o jogador caia em uma armadilha de pedra
void pedra( string players, int &quilates) {
    if (quilates >= 7) {
        quilates-=7;
        cout << players << " Voce caiu em uma armadilha de pedra rolante e ela te esmagou. 7 quilates foram perdidos do seu inventario." << endl;
    }
    else if (quilates == 0) {
        cout << "Voce caiu em uma armadilha de pedra rolante." <<endl;
    }
    else {
        cout << players << " Voce perdeu todos os seus diamantes." << endl;
        quilates=0;
    }
    
}

// função para armadilha de espinhos;

void espinhos(string players, int &quilates) {
    if(quilates >= 5) {
        quilates-=5;
        cout << players << " Você caiu em uma armadilha de espinhos e sua bolsa furou. Cinco quilates caíram do seu inventario antes que você percebesse o furo." << endl;
    }
    else {
        quilates=0;
        cout << players << " Você caiu em uma armadilha de espinhos e sua bolsa furou. " << quilates << " quilates caíram do seu inventario antes que você percebesse o furo." <<endl;
    }
}

// função para achar diamantes

void diamante (int &quilates, string players) {

    int diamante = rand() % 10 + 1;
    cout << players << " Voce achou um diamante de " << diamante << " quilates." << endl;
    quilates += diamante;
}

// função para quando o jogador achar uma pista;

void pista(int const linhas, int const colunas, string players, vector<vector<char>> &mapa) {
    cout << players << " Voce achou um pergaminho!!!" << endl;
    for (int j = 0; j < linhas; j++) {
        for (int K = 0; K < colunas; K++) {
            char valorAtual = mapa[j][K];
            if (valorAtual == 2 || valorAtual == 3 || valorAtual == 4) {
                cout<<  "E nele diz que na linha: " << j << endl
                    << "E na coluna: " << K << endl 
                    << "Tem uma armadilha. Desative ela antes de explorar o local!!!\n" <<endl;
                mapa[j][K]= 'X';
                return;
            }
        }
    }
}