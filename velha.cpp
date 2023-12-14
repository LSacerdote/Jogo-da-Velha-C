#include <stdio.h>

char tabuleiro[3][3]; 

void inicializarTabuleiro() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirTabuleiro() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void fazerMovimento(char jogador) {
    int x, y;
    printf("Jogador %c, insira a coordenada x: ", jogador);
    scanf("%d", &x);
    printf("Jogador %c, insira a coordenada y: ", jogador);
    scanf("%d", &y);
    tabuleiro[x][y] = jogador;
}

int verificarVitoria() {
    for(int i=0; i<3; i++) {
        if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return 1;
        }
        if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return 1;
        }
    }
    if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return 1;
    }
    if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return 1;
    }
    return 0;
}

int main() {
    inicializarTabuleiro();
    char jogadorAtual = 'X';
    while(!verificarVitoria()) {
        imprimirTabuleiro();
        fazerMovimento(jogadorAtual);
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }
    printf("O jogador %c venceu!\n", (jogadorAtual == 'X') ? 'O' : 'X');
    return 0;
}

