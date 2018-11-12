#include <stdlib.h>
#include <stdio.h>
#include "dados.h"

int main(int argc, char ** argv) {
    int n_dados, lados, resultado;
    printf("Informe o numero de dados, lados e a soma\n");
    scanf("%d %d %d", &n_dados, &lados, &resultado);
    int ocorrencias = rola_dados(n_dados, lados, resultado);

    printf("Há %d modos de se obter %d lançando %d dados com %d lados\n", ocorrencias, resultado, n_dados, lados);

    return 0;
}