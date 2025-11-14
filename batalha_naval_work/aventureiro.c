#include <stdio.h>

#define TAM_TABULEIRO 10  // Tamanho do tabuleiro 
#define TAM_NAVIO      3  // Partes por navio
#define NAVIO          3  // Valor ocupado 
#define VAZIO          0  // Água/vazio

// Posicionar navio: deltas + validação anti-colisão!
void posicionar_navio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
            int inicio_linha, int inicio_coluna,
            int delta_linha, int delta_coluna) {
        int linha = inicio_linha;
        int coluna = inicio_coluna;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha >= 0 && linha < TAM_TABULEIRO &&
            coluna >= 0 && coluna < TAM_TABULEIRO &&
            tabuleiro[linha][coluna] == VAZIO) {  //Anti-colisão!
            tabuleiro[linha][coluna] = NAVIO;
        } else {
            printf("AVISO: Colisão ou fora em (%d,%d)!\n", linha, coluna);
        }
        linha += delta_linha;
        coluna += delta_coluna;
    }
}

// Mostrar tabuleiro: Alinhado + contador bonus!
void mostrar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    int total_navios = 0;  // Conta partes

    printf("=== 🏴‍☠️ TABULEIRO DE BATALHA NAVAL 🏴‍☠️ ===\n");
    printf("(0 = Água | 3 = Navio)\n\n");

    // Cabeçalho colunas
    printf("   ");
    for (int col = 0; col < TAM_TABULEIRO; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    // Linhas + soma navios
    for (int lin = 0; lin < TAM_TABULEIRO; lin++) {
        printf("%2d ", lin);
        for (int col = 0; col < TAM_TABULEIRO; col++) {
            printf("%2d ", tabuleiro[lin][col]);
            if (tabuleiro[lin][col] == NAVIO) total_navios++;
        }
        printf("\n");
    }
    printf("\nTotal de partes de navios: %d (esperado: %d)\n", total_navios, 4 * TAM_NAVIO);
}

int main() {
    printf("🚀 Iniciando o Jogo de Batalha Naval...\n");
    printf("Bem-vindo, Almirante! Sua frota está pronta:\n\n");

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};  // Zera TUDO!

    // Frota posicionada (sem colisões!)
    posicionar_navio(tabuleiro, 0, 0,  0,  1);  // Horizontal ➡️
    posicionar_navio(tabuleiro, 3, 0,  1,  0);  // Vertical ⬇️
    posicionar_navio(tabuleiro, 1, 1,  1,  1);  // Diagonal / ➡️⬇️
    posicionar_navio(tabuleiro, 6, 3,  1, -1);  // Diagonal \ ⬅️⬇️

    mostrar_tabuleiro(tabuleiro);  // Exibe o tabuleiro

    return 0;
}