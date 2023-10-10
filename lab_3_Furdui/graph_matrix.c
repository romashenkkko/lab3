#include <stdio.h>

int main() {
    int n; // Numărul de noduri în graf
    int i, j;

    // Citim numărul de noduri de la utilizator
    printf("Introduceti numărul de noduri: ");
    scanf("%d", &n);

    // Creăm o matrice de adiacentă cu n noduri
    int adjacencyMatrix[n][n];

    // Citim matricea de adiacentă de la utilizator (presupunem valori 0 sau 1)
    printf("Introduceti matricea de adiacentă (0 sau 1):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Afișăm matricea de adiacentă
    printf("Matricea de Adiacentă:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    // Creăm matricea de incidentă
    int incidentMatrix[n][n]; // Presupunem un număr maxim de n muchii

    // Initializăm matricea de incidentă
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            incidentMatrix[i][j] = 0;
        }
    }

    // Populăm matricea de incidentă pe baza matricei de adiacentă
    int edgeCount = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                incidentMatrix[i][edgeCount] = 1;
                incidentMatrix[j][edgeCount] = 1;
                edgeCount++;
            }
        }
    }

    // Afișăm matricea de incidentă
    printf("\nMatricea de Incidentă:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < edgeCount; j++) {
            printf("%d ", incidentMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
