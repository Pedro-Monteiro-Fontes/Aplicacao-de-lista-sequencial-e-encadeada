#include <stdio.h>
#include <string.h>
#include "lista.h"

void inicializar(ListaAlunos *lista) {
    lista->tamanho = 0;
}

int inserirAluno(ListaAlunos *lista, int rgm, const char *nome) {
    if (lista->tamanho == MAX_ALUNOS) return -1;

    /* Verifica RGM duplicado e acha posição de inserção */
    int pos = 0;
    while (pos < lista->tamanho && lista->alunos[pos].rgm < rgm) {
        pos++;
    }

    if (pos < lista->tamanho && lista->alunos[pos].rgm == rgm) return -2;

    /* Abre espaço: desloca elementos à direita */
    for (int i = lista->tamanho; i > pos; i--) {
        lista->alunos[i] = lista->alunos[i - 1];
    }

    /* Preenche o novo aluno */
    lista->alunos[pos].rgm = rgm;
    strncpy(lista->alunos[pos].nome, nome, MAX_NOME - 1);
    lista->alunos[pos].nome[MAX_NOME - 1] = '\0';
    lista->alunos[pos].disciplinas = NULL;

    lista->tamanho++;
    return 0;
}

// Busca Binária por RGM 

int buscarAluno(const ListaAlunos *lista, int rgm) {
    int inicio = 0, fim = lista->tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista->alunos[meio].rgm == rgm) return meio;
        if (lista->alunos[meio].rgm < rgm)  inicio = meio + 1;
        else                                fim   = meio - 1;
    }
    return -1;
}

int removerAluno(ListaAlunos *lista, int rgm) {
    int pos = buscarAluno(lista, rgm);
    if (pos == -1) return -1;

    liberarDisciplinas(&lista->alunos[pos]); /*Libera a lista encadeada antes*/

    /* Desloca elementos à esquerda, sobrescrevendo a posição removida */
    for (int i = pos; i < lista->tamanho - 1; i++) {
        lista->alunos[i] = lista->alunos[i + 1];
    }

    lista->tamanho--;
    return 0;
}

void mostrarAlunos(const ListaAlunos *lista) {
    if (lista->tamanho == 0) {
        printf("  Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n  %-10s  %s\n", "RGM", "Nome");
    printf("  %-10s  %s\n", "----------", "--------------------");

    for (int i = 0; i < lista->tamanho; i++) {
        printf("  %-10d  %s\n",
               lista->alunos[i].rgm,
               lista->alunos[i].nome);
    }
}