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
void mumia(int quilates, string players) {
    char luta;
    cout << players<< " Voce encontrou uma mumia quer tentar lutar com ela para roubar a sua bolsa de diamantes?(S)(N): ";
    cin >> luta;
    cout << endl;
    srand(time(0));

    if (luta == 'S') {
        int lutando = rand() % 10 + 1;
        if (lutando >= 5) {
            int tesouro = rand() % 100 +1;
            if (tesouro == 99) {
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
void pedra( string players, int quilates) {
    if (quilates >= 7) {
        quilates-=7;
        cout << players << " Você caiu em uma armadilha de pedra rolante e ela te esmagou. 7 quilates foram perdidos do seu inventário." << endl;
    }
    else {
        cout << players << " Voce perdeu todos os seus diamantes." << endl;
        quilates=0;
    }
    
}

// função para armadilha de espinhos;

void espinhos(string players, int quilates) {
    if(quilates >= 5) {
        quilates-=5;
        cout << players << " Você caiu em uma armadilha de espinhos e sua bolsa furou. Cinco quilates caíram do seu inventário antes que você percebesse o furo." << endl;
    }
    else {
        quilates=0;
        cout << players << " Você caiu em uma armadilha de espinhos e sua bolsa furou. " << quilates << " quilates caíram do seu inventário antes que você percebesse o furo." <<endl;
    }
}

// função para achar diamantes

void diamante (int quilates, string players) {
    srand(time(0));

    int diamante = rand() % 10 + 1;
    cout << players << "Você achou um diamante de " << diamante << " quilates." << endl;
    quilates += diamante;
}

// função para quando o jogador achar uma pista;

void pista(int const linhas, int const colunas, string players) {
    cout << players << " Você achou um pergaminho e nele dizia que na linha: ";
    vector<vector<char>> mapa = createMapa(linhas, colunas);
        for (int i = 0 ; i < linhas; i ++) {
        for (int j = 0 ; j < colunas; j ++) {
            cout << setw(3) << mapa[i][j];
        }
        cout << endl;
    }
    for (int j = 0; j < linhas; j++) {
        for (int K = 0; K < colunas; K++) {
            if (mapa[j][K] != 5 && mapa[j][K] != 36 && mapa[j][K] != 79) {
                cout << j << " e na coluna: " << K << " tem uma armadilha. Não va la!!!" <<endl;
            }
        }
    }
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

        for (int i = 1; i < jogadores+1; i++) {
            // verifica se o jogador escolheu uma casa existente;
            bool coordenada = true;       
            int line;
            int colum;
            while (true) {
                cout << players[i] << " Escolha uma linha e uma coluna para explorar!!!\n" <<endl;
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
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario." <<endl;
                mapa[line][colum]=(icon[i]);
                break;
            case 3:
                pedra(players[i], quilates[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario." <<endl;
                break;
            case 4:
                espinhos(players[i], quilates[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario." <<endl;
                break;
            case 5:
                pista(linhas, colunas , players[i]);
                break;
            case 36:
                diamante(quilates[i], players[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario." <<endl;
                break;
            case 79: 
                cout << "Voce olha para todos os lados e nao ve nada\n" <<endl;
                break;    
            default:
                break;
            }
        }
        rodadas++;
    }
    
}