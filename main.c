#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    FILE* arquivo;
    int numVertices;
    
    arquivo = fopen("C:\\Users\\Softex\\Desktop\\TP03\\poligono.txt.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &numVertices);

    Ponto* pontos = (Ponto*)malloc(numVertices * sizeof(Ponto));

    if (pontos == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(arquivo);
        return 1;
    }

    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &pontos[i].X, &pontos[i].Y);
    }

    fclose(arquivo);

    float area = calcularArea(pontos, numVertices);

    printf("A área do polígono é %.2f\n", area);

    free(pontos);

    return 0;
}
