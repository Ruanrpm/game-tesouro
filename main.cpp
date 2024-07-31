#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#define N 6

using namespace std;

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
    int mapa[N][N] {0};
    int aux = 0;
    srand(time(0));
    // add mobs e armadilhas
    while (aux < 6){
        int I = rand() % 6;
        int J = rand() % 6;
        int armadilha = rand() % 3 + 1;

        if (mapa[I][J] < 1) {
            mapa[I][J] = armadilha;
            aux++;
        }
    }
    // add bufs e algo mais
    aux = 0;
    while (aux < 2){
        int I = rand() % 6;
        int J = rand() % 6;

        if (mapa[I][J] < 1) {
            mapa[I][J] = mapa[I][J] + 6;
            aux++;
        }
    }

    while (aux < 1){
        int I = rand() % 6;
        int J = rand() % 6;

        if (mapa[I][J] < 1) {
            mapa[I][J] = mapa[I][J] + 4;
            aux++;
        }
    }
    
    
    for (int i = 0 ; i < N; i ++) {
        for (int j = 0 ; j < N; j ++) {
            cout << setw(3) << mapa[i][j];
        }
        cout << endl;
    }

    
}