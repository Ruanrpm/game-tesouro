#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

// função criar mapa;
vector<vector<char>> createMapa(const int linhas, const int colunas) {
    
    vector<vector<char>> mapa(linhas, vector<char>(colunas, 79));

    srand(time(0));

    // Adiciona mobs e armadilhas
    int aux = 0;
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

// função caso o jogador encontre uma mumia
void mumia(int i) {
    char luta;
    cout << "Voce encontrou uma mumia quer tentar lutar com ela para roubar a sua bolsa de diamantes?(S)(N): ";
    cin >> luta;
    cout << endl;
    srand(time(0));

    if (luta == 'S') {
        int lutando = rand() % 10 + 1;
        if (lutando >= 5) {
            int tesouro = rand() % 100 +1;
            if (tesouro == 99) {
                cout << "Voce derrotou a mumuia e achou um mapa do tesouro na bolsa dela +10000000000 quilates adicionados ao inventario." << endl;
                quilates[i]+=10000000000;
            }
            else {
                cout << "Voce derrotou a mumia e na bolsa dela tinha 1 diamante de 10 quilates." << endl;
                    quilates[i]+=10;
            }
        }
        else {
            if (quilates[i] > 0){
                quilates[i]=0;
                cout << "A mumia te derrotou e roubou todos os seus diamantes" << endl;
            }
            else{
                cout << "A mumia te derrotou" << endl;
            }
        }
    }
    else {
        cout << "A mumia se afastou" << endl;
    }
}

// função caso o jogador caia em uma armadilha de pedra
void pedra(int i) {
    if (quilates[i] >= 7) {
        quilates[i]-=7;
        cout << "Você caiu em uma armadilha de pedra rolante e ela te esmagou. 7 quilates foram perdidos do seu inventário." << endl;
    }
    else {
        cout << quilates[i] << " Foram perdidos de seu inventário" << endl;
        quilates[i] = 0;
    }
    
}

// função para armadilha de espinhos;

void espinhos(int i) {
    if(quilates[i] >= 5) {
        quilates[i]-=5;
        cout << "Você caiu em uma armadilha de espinhos e sua bolsa furou. Cinco quilates caíram do seu inventário antes que você percebesse o furo." << endl;
    }
    else {
        quilates[i]=0;
        cout << quilates[i] << " caíram do seu inventário." <<endl;
    }
}

// função para achar diamantes

void diamante (int i) {
    srand(time(0));

    int diamante = rand() % 10 + 1;
    cout << "Você achou um diamante de " << diamante << " quilates." << endl;
    quilates[i] += diamante;
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
    const int linhas = 6;
    const int colunas = 6;

    vector<vector<char>> mapa = createMapa(linhas, colunas);

    // corrida;
    int rodadas = 1;
    while (rodadas <= ((linhas*colunas)/jogadores)) {

        for (int i = 1; i < jogadores+1; i++) {
            // verifica se o jogador escolheu uma casa existente;
            bool coordenada = true;       
            int line;
            int colum;
            while (true) {
                cout << players[i] << " Escolha uma linha e uma coluna para explorar!!!" <<endl;
                cin >> "Escolha linha: " >> line;
                cin >> "Escolha coluna: " >> colum;
                if (line > 6 || line < 0 || colum > 6 || colum < 0) {
                    cout << "Escolha um numero de no maximo (5) e no minimo (0)" <<endl;
                }
                else {
                    // verifica se tem um jogador em determinada coordenada escolhida;
                    for (int i = 1; i < jogadores+1; i++) {
                        if (mapa[line][colum] == icon[i]) {
                            cout << "Ja tem um jogador nessa coordenada! Escolha outra." << endl;
                            coordenada = false;
                            break;
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
                mumia(i);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventário." <<endl;
                mapa[line][colum]=icon[i];
                break;
            case 3:
                pedra(i);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventário." <<endl;
                break;
            case 4:
                espinhos(i);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventário." <<endl;
                break;
            case 5:

                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventário." <<endl;
                break;
            case 36:
                diamante(i);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventário." <<endl;
                break;
            default:
                break;
            }
        }
        rodadas++;
    }
    
}
    // for (int i = 0 ; i < linhas; i ++) {
    //     for (int j = 0 ; j < colunas; j ++) {
    //         cout << setw(3) << mapa[i][j];
    //     }
    //     cout << endl;
    // }