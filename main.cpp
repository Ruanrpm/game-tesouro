#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <utility> 

using namespace std;

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

// mapa que o player vai ver
vector<vector<char>> createPlayermap(const int linhas, const int colunas) {   
    vector<vector<char>> playerMap(linhas, vector<char>(colunas, 220));
    return playerMap;
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
                cout << players<< " Voce derrotou a mumia e achou um mapa do tesouro na bolsa dela que mostra aonde tem um diamante de 100 quilates." << endl;
                quilates+=100;
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
        cout << players << " Voce caiu em uma armadilha de espinhos e sua bolsa furou. Cinco quilates cairam do seu inventario antes que você percebesse o furo." << endl;
    }
    else {
        quilates=0;
        cout << players << " Voce caiu em uma armadilha de espinhos e sua bolsa furou. " << quilates << " quilates caíram do seu inventario antes que voce percebesse o furo." <<endl;
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
    char playerMap[linhas][colunas];
    for (int i = 0 ; i < linhas; i ++) {
        for (int j = 0 ; j < colunas; j ++) {
            cout << setw(3) << playerMap[i][j];
        }
        cout << endl;
    }
    vector<vector<char>> mapa = createMapa(linhas, colunas);
    vector<vector<char>> playermap = createPlayermap(linhas, colunas);

    for (int i = 0 ; i < linhas; i ++) {
        for (int j = 0 ; j < colunas; j ++) {
            cout << setw(3) << mapa[i][j];
        }
        cout << endl;
    }
    for (int i = 0 ; i < linhas; i ++) {
        for (int j = 0 ; j < colunas; j ++) {
            cout << setw(3) << playermap[i][j];
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
                playermap[line][colum]=(icon[i]);
                mapa[line][colum]=(icon[i]);
                break;
            case 3:
                pedra(players[i], quilates[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                playermap[line][colum]=(icon[i]);
                mapa[line][colum]=(icon[i]);
                break;
            case 4:
                espinhos(players[i], quilates[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                playermap[line][colum]=(icon[i]);
                mapa[line][colum]=(icon[i]);
                break;
            case 5:
                pista(linhas, colunas , players[i] , mapa);
                playermap[line][colum]=(icon[i]);
                mapa[line][colum]=(icon[i]);
                break;
            case 36:
                diamante(quilates[i], players[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                playermap[line][colum]=(icon[i]);
                mapa[line][colum]=(icon[i]);
                break;
            case 79: 
                cout << "Voce olha para todos os lados e nao ve nada\n" <<endl;
                playermap[line][colum]=(icon[i]);
                mapa[line][colum]=(icon[i]);
                break;  
            case 88: 
                cout << "Voce desativou a armadilha que tinha aqui antes.\n" <<endl;
                playermap[line][colum]=(icon[i]);
                mapa[line][colum]=(icon[i]);
                break;  
            default:
                break;
            }
        }
        cout << "O mapa da rodada " << rodadas << " ficou assim..." << endl;
        for (int i = 0 ; i < linhas; i ++) {
            for (int j = 0 ; j < colunas; j ++) {
                cout << setw(3) << playermap[i][j];
            }
            cout << endl;
        }  
        cout << "\n" << endl;  
        rodadas++; 
    }
    // fazendo o ranking;
    string aux1;
    int aux2;
    for (int i = 1; i < jogadores+1; i++) {
        for (int j = 1; j < jogadores+1; j++) {
            if (quilates[i] <= quilates[j]) {
                aux1 = players[i];
                players[i] = players[j];
                players[j] = aux1;
                aux2 = quilates[i];
                quilates[i] = quilates[j];
                quilates[j] = aux2;
            }
        }
    }
    cout << "\n" << "O placar final ficou assim" <<endl;
    for (int i = 1; i < jogadores+1; i++) {
        cout << i << " lugar: " << players[i] << " com " << quilates[i] << " quilates" <<endl;
    }
}