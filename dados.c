// Created by caroles on 12/11/2018.

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

int ** cria_tabela (int n_dados, int resultado) {
    int ** tabela;
    tabela = malloc (sizeof(int *) * n_dados);
    for (int i = 0; i < n_dados; i++){
        *(tabela + i) = calloc(resultado, sizeof(int));
    }
    printf("tabela criada\n");
    return tabela;
}

int monta_tabela (int ** tabela, int n_dados, int resultado, int lados) {
    int i, contador_dados, contador_res, ocorrencias = 0;
    //inicializando a primeira linha
    for (i = 0; i <= lados && i <= resultado; i++) {
        *(*(tabela + 0) + i) = 1;
    }
    printf("linha inicializada\n");
    for (contador_dados = 1; contador_dados < n_dados; contador_dados++) {
        for (contador_res = 0; contador_res < resultado; contador_res++) {
            for (i = 0; i < lados && i < contador_res - 1; i++) {
                *(*(tabela + contador_dados) + contador_res) += *(*(tabela + contador_dados - 1) + contador_res - i);
            }
        }
    }
    printf("tabela montada\n");
    return *(*(tabela + n_dados - 1) + resultado - 1);
}

int rola_dados (int n_dados, int lados, int resultado) {

    printf("criando tabela\n");
    int ** tabela = cria_tabela(n_dados, resultado);
    printf("montando tabela\n");
    int ocorrencias =  monta_tabela(tabela, n_dados, resultado, lados);
    for (int i = 0; i < n_dados; i++){
        free(*(tabela + i));
    }
    free(tabela);
    return ocorrencias;
}