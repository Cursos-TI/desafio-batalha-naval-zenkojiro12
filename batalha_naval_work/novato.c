#include <stdio.h>
int main () {
    int horizontal_navio [3] [2] = { {0,0}, {0,1}, {0,2} };
// Navio na Horizontal 
    int vertical_navio [3] [2] = { {3,0}, {4,0}, {5,0} };
// Navio na Vertical
    printf("Navio Horizontal:\n"); // Exibir as cooredenadas do navio horizontal
    for (int i = 0; i < 3; i++) {
        printf("Posicao %d: Linha %d, Coluna %d\n", i+1, horizontal_navio[i][0], horizontal_navio[i][1]);
    }
    printf("Navio Vertical:\n"); // Exibir as cooredenadas do navio vertical
    for (int i = 0; i < 3; i++) {
        printf("Posicao %d: Linha %d, Coluna %d\n", i+1, vertical_navio[i][0], vertical_navio[i][1]);
    }
    return 0;
}