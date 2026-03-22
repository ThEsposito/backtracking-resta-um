#include <stdio.h>
#include <stdbool.h>

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
    if (destino.x < 0 || destino.x >= COLUNAS || destino.y < 0 || destino.y >= LINHAS) return false; // Validando índices
    if ((destino.y <= 1 || destino.y >= 5) && (destino.x <= 1 || destino.x >= 5)) return false; // Eliminando cantos do tabuleiro

    Ponto meio = {(destino.x + origem.x)/2,(destino.y + origem.y)/2}; // posição entre origem e destino

    return tab[origem.y][origem.x] == 'o' && tab[meio.y][meio.x] == 'o' && tab[destino.y][destino.x] == ' ';
}


void desfazer_movimento(char tab[LINHAS][COLUNAS], Ponto origem, Ponto destino) { // Backtrack
    Ponto meio = {(destino.x + origem.x)/2,(destino.y + origem.y)/2};
    tab[meio.y][meio.x] = 'o';
    tab[origem.y][origem.x] = 'o';
    tab[destino.y][destino.x] = ' ';
}

bool ganhou(char tab[LINHAS][COLUNAS]) {
    int qtde_pecas = 0;
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (tab[i][j] == 'o') qtde_pecas++;
        }
    }

    return qtde_pecas == 1 && tab[3][3] == 'o';
}

void realizar_movimento(char tab[LINHAS][COLUNAS],  Ponto origem,  Ponto destino) {
    Ponto meio = {(destino.x + origem.x)/2,(destino.y + origem.y)/2};
    tab[meio.y][meio.x] = ' ';
    tab[origem.y][origem.x] = ' ';
    tab[destino.y][destino.x] = 'o';
}

bool resta_um(char tab[LINHAS][COLUNAS], Movimento solucoes[31], int i) {
    if (ganhou(tab)) return true; // Jogo vencido!

    if (i == 31) return false; // Passaram-se os 31 movimentos limite

    for (int j = 0; j < LINHAS; j++) {
        for (int k = 0; k < COLUNAS; k++) {
            Ponto origem = {k, j};
            Ponto mov_cima = {origem.x, origem.y-2};
            Ponto mov_baixo = {origem.x, origem.y+2};
            Ponto mov_esq = {origem.x-2, origem.y};
            Ponto mov_dir = {origem.x+2, origem.y};

            Ponto moves[] = {mov_cima, mov_baixo, mov_esq, mov_dir};

            if (tab[j][k] == 'o') {
                for (int l = 0; l < 4; l++) {
                    if (eh_movimento_valido(tab, origem, moves[l])) {
                        solucoes[i].origem = origem;
                        solucoes[i].destino = moves[l];

                        realizar_movimento(tab, origem, moves[l]);
                        if (resta_um(tab, solucoes, i + 1)) return true;
                        desfazer_movimento(tab, origem, moves[l]);
                    }
                }
            }
        }
     }

    return false;
}

int main() {
    char tabuleiro[LINHAS][COLUNAS] = {
        {'#','#','o','o','o','#','#'},
        {'#','#','o','o','o','#','#'},
        {'o','o','o','o','o','o','o'},
        {'o','o','o',' ','o','o','o'},
        {'o','o','o','o','o','o','o'},
        {'#','#','o','o','o','#','#'},
        {'#','#','o','o','o','#','#'}
    };

    Movimento solucoes[31] = {};
    char tabuleiroAux[LINHAS][COLUNAS] = {
        {'#','#','o','o','o','#','#'},
        {'#','#','o','o','o','#','#'},
        {'o','o','o','o','o','o','o'},
        {'o','o','o',' ','o','o','o'},
        {'o','o','o','o','o','o','o'},
        {'#','#','o','o','o','#','#'},
        {'#','#','o','o','o','#','#'}
    };

    resta_um(tabuleiro, solucoes, 0);
    exibir_solucao(tabuleiroAux, solucoes);
    return 0;
}