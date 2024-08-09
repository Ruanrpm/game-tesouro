#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <utility> 
#include <locale> 
#define linhas 6
#define colunas 6

using namespace std;

// função caso o jogador encontre uma mumia
int mumia(string players, int quilates) {
    char luta;
    int result = 0;
    cout << players << " Voce encontrou uma mumia quer tentar lutar com ela para roubar a sua bolsa de diamantes?(S)(N): ";
    cin >> luta;
    cout << endl;
    srand(time(0));

    if (luta == 'S') {
        int lutando = rand() % 10 + 1;
        if (lutando >= 5) {
            int tesouro = rand() % 50 +1;
            if (tesouro == 49) {
                cout << players<< " Voce derrotou a mumia e achou um mapa do tesouro na bolsa dela que mostra aonde tinha um diamante de 100 quilates. Voce vai la e pega ele..." << endl;
                result+=100;
            }
            else {
                cout << players<< " Voce derrotou a mumia e na bolsa dela tinha 1 diamante de 20 quilates." << endl;
                result+=20;
            }
        }
        else if (quilates> 0){
                char aposta;
                cout << "Quando voce se aproximava para atacar a mumia ela manda voce parar e pergunta se voce quer apostar... voce quer? (S)(N): ";
                cin >> aposta;
                cout << endl;
                if (aposta == 'S') {
                    cout << "Voce aceita, entao ela fala que quer jogar uma partida de poker valendo tudo oque voces 2 tem." << endl;
                    cout << "entao a partida comeca e apos algumas rodadas voce sai com um par de azes, entao como voce nao tem nocao de jogo, voce da allwin e a mumia aceita. \n" << endl;
                    int allwin = rand() % 10;
                    if (allwin >= 5) {
                        cout << "para a sua sorte vc faz um royal flush e ganha todos os diamantes da mumia." << endl; 
                        result+=quilates;
                    }
                    else {
                        cout << "a mumia faz um stright e leva todos os seus diamantes." << endl;
                        result-=quilates;
                    }
                }
                else {
                    cout << "Voce nega e a mumia se afasta triste." << endl;
                }
            }
            else{
                cout << players << " A mumia te derrotou" << endl;
            }
        }
    
    else {
        char aposta;
        cout << "Quando voce ia se afastando a mumia manda voce parar e pergunta se voce quer apostar... voce quer? (S)(N): ";
        cin >> aposta;
        cout << endl;
        if (aposta == 'S') {
            cout << "Voce aceita, entao ela fala que quer jogar uma partida de poker valendo tudo oque voces 2 tem." << endl;
            cout << "entao a partida comeca e apos algumas rodadas voce sai com um par de azes, entao como voce nao tem nocao de jogo voce da allwin." << endl;
            int allwin = rand() % 10;
            if (allwin >= 5) {
                cout << "Para a sua sorte vc faz um full House e ganha todos os diamantes da mumia." << endl; 
                result+=quilates;
            }
            else {
                cout << "a mumia faz um Quadra e leva todos os seus diamantes." << endl;
                result-=quilates;
            }
        }
        else {
            cout << "voce nega e a mumia se afasta triste." << endl;
        }
    }
    return result;
}

// função caso o jogador caia em uma armadilha de pedra
int pedra(string players, int quilates) {
    int result = 0;
    if (quilates > 7) {
        result-=7;
        char entrar;
        cout << players << " Voce caiu em uma armadilha de pedra rolante e ela te esmagou. 7 quilates foram perdidos do seu inventario." << endl;
        cout << "Porem quando voce levanta voce ve que a pedra fez um buraco na parede, grande o sulficiente para voce passar" << endl << "parece perigoso. Voce quer entrar la? (S)(N): ";
        cin >> entrar;
        cout << endl;

        if (entrar == 'S') {
            int perigo = rand() % 10;
            if (perigo <= 5) {
                cout << "Para a sua sorte nao havia nada la e voce encontra um diamante de 15 quilates." << endl;
                result+=15;
            }
            else {
                cout << "Voce encontra um guinomo la, e ele rouba todos os seus diamantes." << endl;
                result=-quilates;
            }
        }
        else {
            cout << "Voce vai embora\n" << endl;
        }
    }
    else if (quilates == 0) {
        char entrar;
        cout << players << " Voce caiu em uma armadilha de pedra rolante e ela te esmagou." << endl;
        cout << "Porem quando voce levanta voce ve que a pedra fez um buraco na parede, grande o sulficiente para voce passar" << endl << "parece perigoso. Voce quer entrar la? (S)(N): ";
        cin >> entrar;
        cout << endl;

        if (entrar == 'S') {
            int perigo = rand() % 10;
            if (perigo <= 5) {
                cout << "Para a sua sorte nao havia nada la e voce encontra um diamante de 15 quilates." << endl;
                result+=15;
            }
            else {
                cout << "Voce encontra um guinomo la, e ele jogou ovo podre em voce..." << endl;
            }
        }
        else {
            cout << "Voce vai embora\n" << endl;
        }
    }
    else {
        cout << players << "Voce caiu em uma armadilha de pedra rolante e perdeu todos os seus diamantes." << endl;
        result-=quilates;
    }
    return result;
}

// função para armadilha de espinhos;

int espinhos(string players, int quilates) {
    int result = 0;
    if(quilates >= 5) {
        result-=5;
        cout << players << " Voce caiu em uma armadilha de espinhos e sua bolsa furou. Cinco quilates cairam do seu inventario antes que você percebesse o furo." << endl;
    }
    else if (quilates > 0) {
        cout << players << " Voce caiu em uma armadilha de espinhos e sua bolsa furou. " << quilates << " quilates caíram do seu inventario antes que voce percebesse o furo." <<endl;
        result = quilates;
    }
    else {
        cout << "Voce caiu em uma armadilha de espinhos e machucou o seu pe." <<endl;
    }
    return result;
}

// função para achar diamantes

int diamante (string players) {
    int diamante = rand() % 10 + 1;
    int result = 0;
    cout << players << " Voce achou um diamante de " << diamante << " quilates." << endl;
    result = diamante;
    return result;
}

// função para quando o jogador achar uma pista;

void pista(string players, char mapa[linhas][colunas], char playerMap[linhas][colunas]) {
    cout << players << " Voce achou um pergaminho!!!" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            char valorAtual = mapa[i][j];
            if (valorAtual == 2 || valorAtual == 3 || valorAtual == 4) {
                cout<< "E nele diz que na linha: " << i << endl
                    << "E na coluna: " << j << endl 
                    << "Tem uma armadilha. Desative ela antes de explorar o local!!!\n" <<endl;
                    mapa[i][j] = 'X';
                    playerMap[i][j] = 'X';
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
    char playerMap[linhas][colunas];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            playerMap[i][j] = 220;
        }
    }

    char mapa[linhas][colunas];
    int quantidadesMob = static_cast<int>(ceil((linhas * colunas) * 0.20));
    int diamantesTotal = static_cast<int>(ceil((linhas * colunas) * 0.40));

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            mapa[i][j] = 79;
        }
    }
    // Adiciona mobs e armadilhas
    int aux = 0;
    while (aux < quantidadesMob) {
        int I = rand() % linhas;
        int J = rand() % colunas;
        int armadilha = 2 + (rand() % (3));

        if (mapa[I][J] == 79) {
            mapa[I][J] = armadilha;
            aux++;
        }
    }
    // Adiciona bufs
    aux = 0;
    while (aux < 2) {
        int I = rand() % linhas;
        int J = rand() % colunas;

        if (mapa[I][J] == 79) {
            mapa[I][J] = 5;
            aux++;
        }
    }
    aux = 0;
    while (aux < diamantesTotal) {
        int I = rand() % linhas;
        int J = rand() % colunas;

        if (mapa[I][J] == 79) {
            mapa[I][J] = 36;
            aux++;
        }
    }

    // print mapas
    for (int i = 0 ; i < linhas; i ++) {
        for (int j = 0 ; j < colunas; j ++) {
            cout << setw(3) << playerMap[i][j];
        }
        cout << endl;
    }
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
                quilates[i]+=mumia(players[i], quilates[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                break;
            case 3:
                quilates[i]+=pedra(players[i], quilates[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                break;
            case 4:
                quilates[i]+=espinhos(players[i], quilates[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                break;
            case 5:
                pista(players[i] , mapa , playerMap);
                break;
            case 36:
                quilates[i]+=diamante(players[i]);
                cout << players[i] << " Agora tem " << quilates[i] << " em seu inventario.\n" <<endl;
                break;
            case 79: 
                cout << "Voce olha para todos os lados e nao ve nada\n" <<endl;
                break;  
            case 88: 
                cout << "Voce desativou a armadilha que tinha aqui antes.\n" <<endl;
                break;  
            default:
                break;
            }
            playerMap[line][colum]=(icon[i]);
            mapa[line][colum]=(icon[i]);
        }
        cout << "O mapa da rodada " << rodadas << " ficou assim..." << endl;
        // mapa para exemplo;
        for (int i = 0 ; i < linhas; i ++) {
            for (int j = 0 ; j < colunas; j ++) {
                cout << setw(3) << mapa[i][j];
            }
            cout << endl;
        }
        // mapa que o player ve;
        for (int i = 0 ; i < linhas; i ++) {
            for (int j = 0 ; j < colunas; j ++) {
                cout << setw(3) << playerMap[i][j];
            }
            cout << endl;
        }  
        cout << "\n" << endl;  
        rodadas++; 
    }
    int primeiro;
    int segundo;
    int terceiro;
    int quarto;
    string top1;
    string top2;
    string top3;
    string top4;
    for (int i = 1; i < jogadores+1; i++) {
        if (quilates[i] > primeiro) {
            quarto = terceiro;
            top4 = top3;
            terceiro = segundo;
            top3 = top2;
            segundo = primeiro;
            top2 = top1;
            top1 = players[i];
            primeiro = quilates[i];
        }
        else {
            // top2
            if (quilates[i] > segundo) {
                quarto = terceiro;
                top4 = top3;
                terceiro = segundo;
                top3 = top2;
                top2 = players[i];
                segundo = quilates[i];
            }
            else {
                // top 3
                if (quilates[i] > terceiro) {
                quarto = terceiro;
                top4 = top3;
                top3 = players[i];
                terceiro = quilates[i];
                }
                else {
                    // top4
                    if (quilates[i] > quarto) {
                        top4 = players[i];
                        quarto = quilates[i];
                    }
                }
            }
        }
    }
    int placar[4];
    string podio[4];
    placar[1] = primeiro;
    placar[2] = segundo;
    placar[3] = terceiro;
    placar[4] = quarto;
    podio [1] = top1;
    podio [2] = top2;
    podio [3] = top3;
    podio [4] = top4;

    cout << "O placar Final ficou assim...\n" << endl;
    for (int i = 1; i < jogadores+1; i++) {
        cout << i << " lugar: " << podio[i] << " com: " << placar[i] << " quilates" << endl;
    }
}