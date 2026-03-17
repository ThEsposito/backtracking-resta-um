#include <stdio.h>

#define LINHAS 7
#define COLUNAS 7

void resta_um(int tab[LINHAS][COLUNAS], int i) {
    if (i >= 31) return;
    if ()
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