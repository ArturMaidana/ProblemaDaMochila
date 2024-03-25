#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacidade, int pesos[], int valores[], int n) {
    int i, w;
    int dp[n + 1][capacidade + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacidade; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (pesos[i - 1] <= w)
                dp[i][w] = max(valores[i - 1] + dp[i - 1][w - pesos[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacidade];
}

int main() {
    int n, capacidade;
    printf("Digite o numero de itens: ");
    scanf("%d", &n);

    int valores[n], pesos[n];

    printf("Digite os valores dos itens:\n");
    for (int i = 0; i < n; i++) {
        printf("Valor do item %d: ", i + 1);
        scanf("%d", &valores[i]);
    }

    printf("Digite os pesos dos itens:\n");
    for (int i = 0; i < n; i++) {
        printf("Peso do item %d: ", i + 1);
        scanf("%d", &pesos[i]);
    }

    printf("Digite a capacidade da mochila: ");
    scanf("%d", &capacidade);

    int resultado = knapsack(capacidade, pesos, valores, n);
    printf("Valor maximo que pode ser alcancado: %d\n", resultado);

    return 0;
}
