#include <stdio.h>

#define LINHAS 7
#define COLUNAS 7

typedef struct {
    int x;
    int y;
} Ponto;

typedef struct {
    Ponto origem;
    Ponto destino;
} Movimento;


void realizar_movimento(char tab[LINHAS][COLUNAS],  Ponto origem,  Ponto destino);

void exibir_tabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    printf("\n");
    for (int i = 0; i < LINHAS+2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("#");
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c", tabuleiro[i][j]);
        }
        printf("#\n");
    }
    for (int i = 0; i < LINHAS+2; i++) printf("#");
    printf("\n");
}

void exibir_solucao(char tabuleiro[LINHAS][COLUNAS], Movimento movimentos[31]) {
    for (int i = 0; i < 31; i++) {
        exibir_tabuleiro(tabuleiro);
        printf("\n");

        realizar_movimento(tabuleiro, movimentos[i].origem, movimentos[i].destino);
    }
    exibir_tabuleiro(tabuleiro);
}

// Tô levando em consideração que a origem já está validada (vai ser controlada no loop da função recursiva)
bool eh_movimento_valido(char tab[LINHAS][COLUNAS], Ponto origem,  Ponto destino) {
    if (destino.x < 0  destino.x >= COLUNAS  destino.y < 0  destino.y >= LINHAS) return false; // Validando índices
    if ((destino.y <= 1  destino.y >= 5) && (destino.x <= 1 || destino.x >= 5)) return false; // Eliminando cantos do tabuleiro

    Ponto meio = {(destino.x + origem.x)/2,(destino.y + origem.y)/2}; // posição entre origem e destino

    return tab[origem.y][origem.x] == 'o' && tab[meio.y][meio.x] == 'o' && tab[destino.y][destino.x] == ' ';
}


void desfazer_movimento(char tab[LINHAS][COLUNAS], Ponto origem, Ponto destino) { // Backtrack
    Ponto meio = {(destino.x + origem.x)/2,(destino.y + origem.y)/2};
    tab[meio.y][meio.x] = 'o';
    tab[origem.y][origem.x] = 'o';
    tab[destino.y][destino.x] = ' ';
}

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {
        {'#','#','o','o','o','#','#'},
        {'#','#','o','o','o','#','#'},
        {'o','o','o','o','o','o','o'},
        {'o','o','o',' ','o','o','o'},
        {'o','o','o','o','o','o','o'},
        {'#','#','o','o','o','#','#'},
        {'#','#','o','o','o','#','#'}
    };
    exibir_tabuleiro(tabuleiro);
    return 0;
}