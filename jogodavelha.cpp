#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <conio.h>


using namespace std;

    //Área de definição de cabeçalhos de função

//char nomejogador_atual [60];

int menuInicial();

int Limpador(){
    system("CLS");
}

int iniciar_tabuleiro(char tabuleiro[3][3]){

    //Navega por cada posição do tabuleiro e coloca o símbolo de '-'
    int linha,coluna;
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }

}

int exibir_tabuleiro (char tabuleiro[3][3]){

     //Exibe o tabuleiro com suas linhas e colunas quebrando a linha ao sair de um for
    int linha,coluna;
    printf("\n");
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
           cout << tabuleiro[linha][coluna];

        }
        printf("\n");
    }

}

    //1 = X venceu, 2 = O venceu, 0 = Nada Aconteceu
int conferir_tabuleiro(char tabuleiro[3][3]){

        int linha, coluna;

        //Confere linhas
        for(linha = 0; linha < 3; linha++){
            if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 1;
            }else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 2;
            }
        }

        //Confere Colunas
        for(coluna = 0; coluna < 3; coluna++){
            if(tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 1;
            }else if(tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 2;
            }
        }

        //Diagonal Principal
        if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){

            if(tabuleiro[0][0] == 'X'){
               return 1;
            }else{
               return 2;
            }
        }

        //Diagonal Secundária
        if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){

            if(tabuleiro[0][2] == 'X'){
                return 1;
            }else{
               return 2;
            }
        }

        return 0;
}


int exibir_posicoes(){

    printf("\nMapa de Posicoes:");
    printf("\n 7 | 8 | 9");
    printf("\n 4 | 5 | 6");
    printf("\n 1 | 2 | 3");

}

int jogo(char nomejogador_1[60], char nomejogador_2[60], int pontuacaojogador1, int pontuacaojogador2){

    ///Variáveis Gerais
    string nomejogador_atual;//Nomes dos jogadores

    char tabuleiro[3][3];                                       //Tabuleiro do Jogo
    int linha,coluna;                                           //Auxiliares para tabuleiro
    int linhajogada,colunajogada,posicaojogada;                 //Posição em que o jogador posiciona sua marca
    int estadoDeJogo = 1;                                       //0 = Sem jogo,1 = Em Jogo
    int turno_jogador = 1;                                      //1 = X, 2 = O
    int rodada = 0;                                             //Quantas vezes os jogadores jogaram no total
    int opcao;                                                  //Opção de reinício
    bool posicionou_jogada;                                      //Verifica se o jogador colocou um marcador no tabuleiro

    //Coloca os '-' no tabuleiro para indicar o vazio
    iniciar_tabuleiro(tabuleiro);

    while(rodada < 9 && estadoDeJogo == 1){

        Limpador();

        printf("\nRodada:\n",rodada);
        cout << "Pontuacao:" << nomejogador_1 << " " << pontuacaojogador1 << " x " << pontuacaojogador2 << " " << nomejogador_2;

        //Exibe o tabuleiro na tela
        exibir_tabuleiro(tabuleiro);

        //Exibe qual numero corresponde a qual posicao
        exibir_posicoes();


        //Atualiza o nome do jogador atual


        if(turno_jogador == 1){

            nomejogador_atual = nomejogador_1;

        }else{

            nomejogador_atual = nomejogador_2;

        }

        posicionou_jogada = false;

        //Matriz de posicoes possíveis
        //                     0     1     2     3     4     5     6     7     8     9
        int posicoes[10][2] = {{9,9},{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};
        //// linha = 0 e coluna = 1
        while(posicionou_jogada == false){

            //Lê a jogada

            printf("\nRodada numero %d", rodada);

            //printf("\n%s Digite uma posicao conforme o mapa acima:", nomejogador_atual);
            cout << "\n" << nomejogador_atual << " Digite uma posicao conforme o mapa acima:";
            scanf("%d", &posicaojogada);

            //Passa a linha e coluna de acordo com a matriz de posições exibida no mapa
            linhajogada = posicoes[posicaojogada][0];
            colunajogada = posicoes[posicaojogada][1];

            //Verifica se a posição é vazia
            if(tabuleiro[linhajogada][colunajogada] == '-'){

                //Conseguiu posicionar um marcador
                posicionou_jogada = true;

                //Verifica de quem é a vez para posicionar o marcador
                if(turno_jogador == 1){

                    tabuleiro[linhajogada][colunajogada] = 'X';

                    turno_jogador = 2;

                }else{

                    tabuleiro[linhajogada][colunajogada] = 'O';

                    turno_jogador = 1;

                }

            }

        }

        //Confere se o jogo acabou
        if(conferir_tabuleiro(tabuleiro) == 1){
            printf("\nO jogador X venceu\n");
            pontuacaojogador1++;
            estadoDeJogo = 0;
        }else if(conferir_tabuleiro(tabuleiro) == 2){
            printf("\nO jogador O venceu\n");
            pontuacaojogador2++;
            estadoDeJogo = 0;
        }

        //Aumenta uma rodada
        rodada++;

    }

    exibir_tabuleiro(tabuleiro);
    printf("\n\nFim de jogo");
    printf("\nO que deseja fazer?");
    printf("\n1-Continuar Jogando");
    printf("\n2-Menu Inicial");
    printf("\n3-Sair\n\n\n\n");
    scanf("%d", &opcao);
    if(opcao == 1){
        jogo(nomejogador_1, nomejogador_2,pontuacaojogador1,pontuacaojogador2);
    }else if(opcao == 2){
        menuInicial();
    }

}

int menuInicial(){

    //Opção escolhida pelo usuário
    int opcao = 0;

    //Nome dos jogadores
    char nomejogador_1[60];
    char nomejogador_2[60];

    //Enquanto o jogador não digita uma opcao válida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
        Limpador();
        printf("          ##     ##    ###    ##     ##\n");
        printf("          ##     ##   ## ##   ###   ###\n");
        printf("          ##     ##  ##   ##  #### ####\n");
        printf("          ##     ## ##     ## ## ### ##\n");
        printf("          ##     ## ######### ##     ##\n");
        printf("          ##     ## ##     ## ##     ##\n");
        printf("           #######  ##     ## ##     ##\n\n\n");


        printf("Bem vindo ao Jogo da Velha");
        printf("\n1 - Jogar");
        printf("\n2 - instrucoes");
        printf("\n3 - Sair");
        printf("\nEscolha uma opcao e tecle ENTER:");


        //Faz a leitura da opcao
        //cin >> opcao;
        scanf("%d", &opcao);
        //Faz algo de acordo com a opcao escolhida
        switch(opcao){
            case 1:
                //Inicia o jogo
                printf("Jogo iniciado");
                printf("Digite o nome do jogador 1:");
                scanf("%s", &nomejogador_1);
                printf("Digite o nome do jogador 2:");
                scanf("%s", &nomejogador_2);
                jogo(nomejogador_1, nomejogador_2,0,0);
                break;
            case 2:

                //Mostra informacoes do Jogo
                printf("\nInformacoes do jogo\n");
                printf("\n1-Escreva o nome do jogador 1, logo apos, escreva o do jogador 2\n\n");
                printf("2-em seguida vai aparecer um mapa de posicoes do numero 1 ao 9, cada numero significa uma posicao,\no primeiro jogador escolhe um numero e ele correspondera a posicao escolhida, e o mesmo acontece com o jogador 2.\n\n");
                printf("3-O jogador que conseguir fazer uma sequencia de 3 simbolos, seja X ou O, sera o vencedor.\n\n\ ");
                printf("FIM DAS INSTUCOES\n\n\n\n\n");
                printf("digite 1 para voltar ao menu anterior e jogar, ou 2 para ir embora :( \n");
                scanf("%d", &opcao);
                if(opcao == 1){
                menuInicial();
                }else if(opcao == 2){
                printf("Muito obrigado, ate logo!\n\n");
                }
                break;
            case 3:
                printf("Ate mais!");
                break;

                }
        }

    }



int main(){
    system("color 60");
    menuInicial();
    return 0;
}
