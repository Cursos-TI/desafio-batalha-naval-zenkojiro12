#include <stdio.h>

#define TAM_TABULEIRO 10  // Tamanho do tabuleiro 
#define CENTRO_L 5        // Linha central para padrões (0-9)
#define CENTRO_C 5        // Coluna central
#define RAIO 2            // Raio para octaedro/cone 
#define AFETADO 1         // Valor para área afetada
#define NAO_AFETADO 0     // Valor para não afetado

// Função genérica para zerar tabuleiro (boa prática: reutilizável)
void zerar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = NAO_AFETADO;
        }
    }
}
// Função para aplicar habilidade CONE (cresce para baixo do centro)
void aplicar_cone(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int c_l, int c_c) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {  // Loop linhas
        for (int j = 0; j < TAM_TABULEIRO; j++) {  // Loop colunas aninhado
            int dist_l = i - c_l;
            if (dist_l >= 0 && j >= c_c - dist_l && j <= c_c + dist_l) {
                if (i < TAM_TABULEIRO && j < TAM_TABULEIRO) {  // Validação limites
                    tabuleiro[i][j] = AFETADO;
                }
            }
        }
    }
}
// Função para aplicar habilidade CRUZ (horizontal + vertical)
void aplicar_cruz(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int c_l, int c_c) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (i == c_l || j == c_c) {  // Horizontal ou vertical
                tabuleiro[i][j] = AFETADO;
            }
        }
    }
}
// Função para aplicar habilidade OCTAEDRO (diamante com distância Manhattan)
void aplicar_octaedro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int c_l, int c_c, int raio) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            int dist = abs(i - c_l) + abs(j - c_c);  
            if (dist <= raio) {
                tabuleiro[i][j] = AFETADO;
            }
        }
    }
}
// Função para exibir tabuleiro (alinhado, como no exemplo com %d )
void mostrar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], const char* nome_habilidade) {
    printf("\n=== Tabuleiro com Habilidade %s ===\n", nome_habilidade);
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);  // Como no exemplo: %d seguido de espaço
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    printf("🚀 Iniciando o Jogo de Batalha Naval...\n");
    printf("Bem-vindo, Almirante! Sua frota está pronta:\n\n");

    // Aplicar e exibir CONE
    zerar_tabuleiro(tabuleiro);
    aplicar_cone(tabuleiro, CENTRO_L - RAIO, CENTRO_C);  
    mostrar_tabuleiro(tabuleiro, "Cone");

    // Aplicar e exibir CRUZ
    zerar_tabuleiro(tabuleiro);
    aplicar_cruz(tabuleiro, CENTRO_L, CENTRO_C);
    mostrar_tabuleiro(tabuleiro, "Cruz");

    // Aplicar e exibir OCTAEDRO
    zerar_tabuleiro(tabuleiro);
    aplicar_octaedro(tabuleiro, CENTRO_L, CENTRO_C, RAIO);
    mostrar_tabuleiro(tabuleiro, "Octaedro");

    return 0;
}