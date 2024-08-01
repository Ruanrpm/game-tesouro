#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

// função criar mapa;
vector<vector<char>> createMapa(int linhas, int colunas) {
    
    vector<vector<char>> mapa(linhas, vector<char>(colunas, 79));
    int aux = 0;

    srand(time(0));

    // Adiciona mobs e armadilhas
    while (aux < 6) {
        int I = rand() % linhas;
        int J = rand() % colunas;
        int armadilha = rand() % 4 + 2;

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
            mapa[I][J] = mapa[I][J] = 6;
            aux++;
        }
    }
    
    aux = 0;
    while (aux < 2) {
        int I = rand() % linhas;
        int J = rand() % colunas;

        if (mapa[I][J] == 79) {
            mapa[I][J] = mapa[I][J] = 4;
            aux++;
        }
    }
    aux = 0;
    while (aux < 3) {
        int I = rand() % linhas;
        int J = rand() % colunas;

        if (mapa[I][J] == 79) {
            mapa[I][J] = mapa[I][J] = 5;
            aux++;
        }
    }
    aux = 0;
    while (aux < 13) {
        int I = rand() % linhas;
        int J = rand() % colunas;

        if (mapa[I][J] == 79) {
            mapa[I][J] = mapa[I][J] = 36;
            aux++;
        }
    }

    return mapa;
}




int main() {
    int jogadores;
    char play;

    cout << "Digite S para jogar: "; 
    cin >> play;
    if (play != 'S') {
        return 1;
    }

    // introdução do game
    cout << "" <<endl;

    // escolher a quantidade de jogadores
    while (true) {
        int Q;

        cout << "Escolha a quantidade de jogadores: ";
        cin >> Q;
        jogadores = Q;

        if (jogadores >= 2 && jogadores <= 4) {
            break;
        }
        else {
            cout << "Sao permitidos um minimo de 2 e um maximo de 4 jogadores \n" <<endl;
        }      
    }

    // nomear jogador;
    string players[jogadores+1];
    string icon[jogadores+1];
    int quilates[jogadores+1];

    cin.get();
    for (int i = 1; i < jogadores+1; i++) {
        string name, icone;
        cout << "Digite o nome do jogador " << i << ": ";
        getline (cin, name);
        players[i] = name;
        cout << endl;

        cout << "Qual sera o icone do jogador " << i << " ?: ";
        getline (cin, icone);
        icon[i] = icone;
        cout << endl;
    }

    // Criando mapa;
    int linhas = 6;
    int colunas = 6;

    vector<vector<char>> mapa = createMapa(linhas, colunas);

    // corrida;

    for (int i = 0; i < linhas;) {
        for (int j = 0; j < colunas;) {

        //vetor do icone dos jogadores;
        for (int k = 1; k < jogadores+1;) { 
            int J = rand() %3 + 1;
            j+=J;
            if (j > 6) {
                i++;
                j=0;
            }
            if (mapa[i][j] == 79) {
                mapa[i][j] = icon[k];
            }
            else {
                //verificação se o jogador encontrou uma mumia;
                if (mapa[i][j] == 2){
                    char luta;
                    cout << "Voce encontrou uma mumia quer tentar lutar com ela para roubar a sua bolsa de diamantes?(S)(N): ";
                    cin >> luta;
                    cout << endl;

                    if (luta == 'S') {
                        int lutando = rand() % 10 + 1;
                        if (lutando >= 5) {
                            int tesouro = rand() % 100 +1;
                            if (tesouro == 100) {
                                cout << "Voce derrotou a mumuia e achou um mapa do tesouro na bolsa dela +10000000000 quilates adicionados ao inventario." << endl;
                                quilates[k]+=10000000000;
                            }
                            else {
                                cout << "Voce derrotou a mumia e na bolsa dela tinha 1 diamante de 10 quilates." << endl;
                                quilates[k]+=10;
                            }
                        }
                        else {
                            if (quilates[k] > 0){
                                quilates[k]=0;
                                cout << "A mumia te derrotou e roubou todos os seus diamantes" << endl;
                            }
                            else{
                                cout << "A mumia te derrotou" << endl;
                            }
                        }
                        k++;
                    }
                    else {
                        cout << "A mumia se afastou" << endl;
                        mapa[i][j] = icon[k];
                        k++;
                    }

                }
                if (mapa[i][j] == 3){

                }
            }
        }

        }
    }
    
    
}
    /*for (int i = 0 ; i < linhas; i ++) {
        for (int j = 0 ; j < colunas; j ++) {
            cout << setw(3) << mapa[i][j];
        }
        cout << endl;
    }*/