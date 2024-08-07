#include <iostream>
#include <string>
#include <vector>
#include "funcoes.h"

using namespace std;


int main() {
    int jogadores;
    char play;
    srand(time(0));

    cout << "Digite S para jogar: "; 
    cin >> play;
    cout << "\n" << endl;
    if (play != 'S') {
        return 1;
    }

    // introdução do game
    cout << "Bem vindo a Maze Runner! Correr ou perder! Nesse jogo voce e seu/seus amigos estao dentro de uma Tumba Asteca no Mexico, com objetivo de ficarem ricos! E para ficar mais divertido, vcs decidem uma competicao entre vcs, quem tiver mais quilates de diamantes, ganha a competicao, entretanto... essa aposta nao vai ser facil dentro dessa tumba, pois ela possui diversas armadilhas, aranhas e escorpioes, para acabar sua esperanca.\n" <<endl;

    // escolher a quantidade de jogadores
    while (true) {
        cout << "Escolha a quantidade de jogadores: ";
        cin >> jogadores;
        cin.get();

        if (jogadores >= 2 && jogadores <= 4) {
            break;
        }
        else {
            cout << "Sao permitidos um minimo de 2 e um maximo de 4 jogadores \n" <<endl;
        }      
    }

    // nomear jogador;
    string players[jogadores+1];
    char icon[jogadores+1];
    int quilates[jogadores+1] {0};

    for (int i = 1; i < jogadores+1; i++) {
        string name;
        char icone;
        cout << "Digite o nome do jogador " << i << ": ";
        getline (cin, name);
        players[i] = name;

        cout << "Qual sera o icone do jogador " << i << " ?: ";
        cin >> icone;
        cin.get();
        icon[i] = icone;
        cout << endl;
    }

    // Criando mapa;
    const int linhas = 6;
    const int colunas = 6;

    vector<vector<char>> mapa = createMapa(linhas, colunas);
    for (int i = 0 ; i < linhas; i ++) {
        for (int j = 0 ; j < colunas; j ++) {
            cout << setw(3) << mapa[i][j];
        }
        cout << endl;
    }

    // corrida;
    int rodadas = 1;
    while (rodadas <= ((linhas*colunas)/jogadores)) {
        cout << "Rodada " << rodadas <<endl;
        for (int i = 1; i < jogadores+1; i++) {
            // verifica se o jogador escolheu uma casa existente;
            bool coordenada = true;       
            int line;
            int colum;
            while (true) {
                cout << players[i] << " Escolha uma linha e uma coluna para explorar!!!" <<endl;
                cout << "Escolha uma linha: ";
                cin >> line;
                cout << "Escolha uma coluna: ";
                cin >> colum;
                cout << "\n" << endl;
                if (line >= 6 || line < 0 || colum >= 6 || colum < 0) {
                    cout << "Escolha um numero de no maximo (5) e no minimo (0)" <<endl;
                    coordenada = false;
                }
                else {
                    // verifica se tem um jogador em determinada coordenada escolhida;
                    for (int i = 1; i < jogadores+1; i++) {
                        if ((mapa[line][colum]) == (icon[i])) {
                            cout << "Ja tem um jogador nessa coordenada! Escolha outra.\n" << endl;
                            coordenada = false;
                            break;
                        }
                        else {
                            coordenada = true;
                        }
                    }                    
                }
                if (coordenada) {
                    // verifica se a coordenada e valida
                    break;
                }
            }

            // eventos
            switch (mapa[line][colum]) {
            case 2:
                mumia(quilates[i], players[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                mapa[line][colum]=(icon[i]);
                break;
            case 3:
                pedra(players[i], quilates[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                mapa[line][colum]=(icon[i]);
                break;
            case 4:
                espinhos(players[i], quilates[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                mapa[line][colum]=(icon[i]);
                break;
            case 5:
                pista(linhas, colunas , players[i] , mapa);
                mapa[line][colum]=(icon[i]);
                break;
            case 36:
                diamante(quilates[i], players[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                mapa[line][colum]=(icon[i]);
                break;
            case 79: 
                cout << "Voce olha para todos os lados e nao ve nada\n" <<endl;
                mapa[line][colum]=(icon[i]);
                break;  
            case 88: 
                cout << "Voce desativou a armadilha que tinha aqui antes.\n" <<endl;
                mapa[line][colum]=(icon[i]);
                break;  
            default:
                break;
            }
        }
        cout << "O mapa da rodada " << rodadas << " ficou assim..." << endl;
        for (int i = 0 ; i < linhas; i ++) {
            for (int j = 0 ; j < colunas; j ++) {
                cout << setw(3) << mapa[i][j];
            }
            cout << endl;
        }    
        rodadas++; 
    }
}