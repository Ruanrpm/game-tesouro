#include <iostream>

using namespace std;

int main() {
    char play, jogadores;

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

        cout << "Escolha a quantidade de jogadores";
        cin >> Q;
        jogadores = Q;

        if (jogadores >= 2 && jogadores <= 4) {
            break;
        }
        else {
            cout << " Sao permitidos um minimo de 2 e um maximo de 4 jogadores" <<endl;
        }      
    }

    char players[jogadores];
    char icon[jogadores];

    for (int i = 1; i <= jogadores; i++) {
        char name, icone;
        cout << "Digite o nome do jogador " << i << ": ";
        cin >> name;
        players[i] = name;

        cout << "Qual sera o icone do jogador " << i << " ?:";
        cin >> icone;
        icon[i] = icone;
    }
}#   g a m e - t e s o u r o  
 