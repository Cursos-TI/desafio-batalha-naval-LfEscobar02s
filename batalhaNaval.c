/*
 * Jogo de Batalha Naval com Habilidades Especiais
 * Autor: [Seu Nome]
 * Descricao: Este programa posiciona quatro navios no tabuleiro 10x10 e adiciona habilidades
 * especiais (cone, cruz e octaedro) com áreas de efeito sobrepostas ao tabuleiro.
 */

#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HABILIDADE 5

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se um navio pode ser posicionado (horizontal, vertical ou diagonal)
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * deltaLinha;
        int c = coluna + i * deltaColuna;
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO) return 0;
        if (tabuleiro[l][c] == NAVIO) return 0;
    }
    return 1;
}

// Posiciona um navio (horizontal, vertical ou diagonal)
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * deltaLinha;
        int c = coluna + i * deltaColuna;
        tabuleiro[l][c] = NAVIO;
    }
}

// Aplica uma matriz de habilidade ao tabuleiro, centralizada na coordenada origem
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = origemLinha - offset + i;
            int coluna = origemColuna - offset + j;
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == AGUA) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Cria matriz de habilidade em forma de cone
void criarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 0 && j == TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else if (i == 1 && j >= 1 && j <= 3)
                matriz[i][j] = 1;
            else if (i == 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz de habilidade em forma de cruz
void criarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz de habilidade em forma de octaedro (losango)
void criarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posiciona navios: 2 normais e 2 diagonais
    if (podePosicionar(tabuleiro, 2, 2, 0, 1))  // Horizontal
        posicionarNavio(tabuleiro, 2, 2, 0, 1);

    if (podePosicionar(tabuleiro, 5, 1, 1, 0))  // Vertical
        posicionarNavio(tabuleiro, 5, 1, 1, 0);

    if (podePosicionar(tabuleiro, 0, 0, 1, 1))  // Diagonal principal
        posicionarNavio(tabuleiro, 0, 0, 1, 1);

    if (podePosicionar(tabuleiro, 0, 9, 1, -1))  // Diagonal secundária
        posicionarNavio(tabuleiro, 0, 9, 1, -1);

    // Matrizes de habilidade
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 6, 6);
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
