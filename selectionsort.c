#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NUM 5000
#define ARQ_ENTRADA "arq_teste.txt"
#define ARQ_SAIDA "tempos_selection.txt"

int vet_base[MAX_NUM];

int ler_arq(int vetor[], const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "rt");
    if (arq == NULL) {
        fprintf(stderr, "erro na abertura do arquivo de entrada %s", nome_arquivo);
        return 0;
    }

    int i = 0;
    while (i < MAX_NUM && fscanf(arq, "%d", &vetor[i]) == 1) {
        i++;
        fscanf(arq, ",");
    }

    fclose(arq);
    return i;
}

void selection_sort(int vetor[], int n) {
    int i, j, menor;

    for (i = 0; i < n - 1; i++) {
        menor = i;
        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = vetor[menor];
            vetor[menor] = vetor[i];
            vetor[i] = temp;
        }
    }
}

void imprimir_vet(int vetor[], int n) {
    printf("\nelementos ordenados na primeira execução(pra visualização):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d", vetor[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int i, R, N;
    int elementos_lidos;

    elementos_lidos = ler_arq(vet_base, ARQ_ENTRADA);
    
    if (elementos_lidos == 0) {
        return 1;
    }

    printf("digite a quantidade de elementos para ordenar(max: %d): ", elementos_lidos);
    scanf("%d", &N);

    printf("digite o numero de vezes para execucar(ex: 1k): ");
    scanf("%d", &R);
    
    int *vet_aux = (int*)malloc(N * sizeof(int));
    if (vet_aux == NULL) {
        fprintf(stderr, "erro na alocacao\n");
        return 1;
    }

    FILE *arq_saida = fopen(ARQ_SAIDA, "wt");
    if (arq_saida == NULL) {
        fprintf(stderr, "erro na criação do arquivo de saida %s\n", ARQ_SAIDA);
        free(vet_aux);
        return 1;
    }

    printf("\ncomeço de %d execucoes do selectionsort em %d elementos\n", R, N);

    for (i = 0; i < R; i++) {
        for (int j = 0; j < N; j++) {
            vet_aux[j] = vet_base[j];
        }

        clock_t begin = clock();
        selection_sort(vet_aux, N);
        clock_t end = clock();
        
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        fprintf(arq_saida, "%.6f\n", time_spent);

        if (i == 0) {
            imprimir_vet(vet_aux, N);
            printf("resultados serao salvos em: %s\n", ARQ_SAIDA);
        }
    }

    fclose(arq_saida);
    free(vet_aux);
    printf("\nexecucoes concluidas! tempos estao no arquivo %s.\n", ARQ_SAIDA);

    return 0;
}