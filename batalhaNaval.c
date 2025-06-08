/*
 * Jogo de Batalha Naval - Posicionamento de Navios
 * Autor: [Seu Nome]
 * Descricao: Este programa inicializa um tabuleiro 10x10 e posiciona dois navios de tamanho 3:
 *            um na horizontal e outro na vertical, garantindo que estejam dentro dos limites e
 *            nao se sobreponham. Também exibe exemplos de padrões de habilidades.
 */

#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se um navio pode ser posicionado no tabuleiro
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int horizontal) {
    if (horizontal) {
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] == NAVIO) return 0;
        }
    } else {
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int horizontal) {
    if (horizontal) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para exibir padrões de habilidade
void exibirPadrao(int padrao[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", padrao[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas no código)
    int linha_horizontal = 2, coluna_horizontal = 4;
    int linha_vertical = 5, coluna_vertical = 1;

    // Valida e posiciona o navio horizontal
    if (podePosicionar(tabuleiro, linha_horizontal, coluna_horizontal, 1)) {
        posicionarNavio(tabuleiro, linha_horizontal, coluna_horizontal, 1);
    } else {
        printf("Erro ao posicionar o navio horizontal.\n");
    }

    // Valida e posiciona o navio vertical
    if (podePosicionar(tabuleiro, linha_vertical, coluna_vertical, 0)) {
        posicionarNavio(tabuleiro, linha_vertical, coluna_vertical, 0);
    } else {
        printf("Erro ao posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    // Padrões de habilidades
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    printf("\nExemplo para habilidade em cone:\n");
    exibirPadrao(cone);

    printf("Exemplo para habilidade em octaedro:\n");
    exibirPadrao(octaedro);

    printf("Exemplo para habilidade em cruz:\n");
    exibirPadrao(cruz);

    return 0;
}
