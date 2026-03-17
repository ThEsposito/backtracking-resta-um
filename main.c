#include <stdio.h>

#define LINHAS 7
#define COLUNAS 7

int eh_movimento_valido(int tab[LINHAS][COLUNAS], int origem_x, int origem_y, int destino_x, int destino_y) {
    if (origem_x < 0 || origem_x > COLUNAS || destino_x < 0 || destino_y > LINHAS) return 0;
    if ((destino_x <= 1 || destino_x >= 4) && destino_y <= 1 || destino_x >= 4) return 0;
    if ()
    return 1;
}

void resta_um(int tab[LINHAS][COLUNAS], int i) {
    if (i > 31) return; // Passaram-se os 32 movimentos válidos
    // if ()
}

// Gravar em arquivo
void exibir_tabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        printf("#");
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c", tabuleiro[i][j]);
        }
        printf("#\n");
    }
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