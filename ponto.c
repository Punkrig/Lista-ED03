#include "ponto.h"
#include <math.h>

float calcularArea(Ponto* pontos, int numVertices) {
    float area = 0.0;
    
    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;
        area += (pontos[i].X * pontos[j].Y - pontos[j].X * pontos[i].Y);
    }

    return 0.5 * fabs(area);
}
