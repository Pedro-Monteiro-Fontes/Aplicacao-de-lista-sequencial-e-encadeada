#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

// Insere a disciplina no inicio da lista encadeada do aluno recebido

int inserirDisciplinas(Aluno *aluno, const char *nome){
 NoDisciplina *novo = (NoDisciplina *) malloc(sizeof(NoDisciplina));

 if(novo == NULL) return -1; // falha na alocação

 strncpy(novo->nome, nome, MAX_DISC - 1);
 novo->nome[MAX_DISC - 1] = '\0';

 novo->prox = aluno->disciplinas; // novo aponta para o antigo inicio
 aluno->disciplinas = novo; // cabeça da lista passa ser o novo nó

 return 0;
}

// Exibe as disciplinas dos alunos, percorre a lista do inicio ao fim

void listarDisciplinas(const Aluno *aluno){
  if( aluno->disciplinas == NULL){
    printf("        (sem disciplinas\n)");
    return;
  }
  NoDisciplina *atual = aluno->disciplinas;
  while (atual != NULL)
  {
    printf("       -%s \n", atual->nome);
    atual = atual->prox;
  }
  
}

void liberarDisciplinas(Aluno *aluno){
    NoDisciplina *atual = aluno->disciplinas;

    while (atual != NULL){
        NoDisciplina *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    aluno->disciplinas = NULL;
}