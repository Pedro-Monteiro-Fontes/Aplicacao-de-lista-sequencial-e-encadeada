#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/* Limpa o buffer do teclado após leituras com scanf */
static void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    ListaAlunos sala;
    inicializar(&sala);

    int opcao;

    do {
      printf("\n+------------------------------+\n");
      printf("|    GERENCIADOR DE TURMA      |\n");
      printf("+------------------------------+\n");
      printf("|  1. Incluir aluno            |\n");
      printf("|  2. Mostrar todos            |\n");
      printf("|  3. Buscar por RGM           |\n");
      printf("|  4. Remover aluno            |\n");
      printf("|  0. Sair                     |\n");
      printf("+------------------------------+\n");
      printf("  Opcao: ");
      scanf("%d", &opcao);
      limparBuffer();
      printf("\n");

        if (opcao == 1) {
            int rgm;
            char nome[MAX_NOME];

            printf("  RGM: ");
            scanf("%d", &rgm);
            limparBuffer();

            printf("  Nome: ");
            fgets(nome, MAX_NOME, stdin);
            nome[strcspn(nome, "\n")] = '\0';   /* remove o '\n' do fgets */

            int resultado = inserirAluno(&sala, rgm, nome);

            if (resultado ==  0) printf("  Aluno cadastrado com sucesso!\n");
            if (resultado == -1) printf("  Sala cheia (limite de %d alunos).\n", MAX_ALUNOS);
            if (resultado == -2) printf("  RGM %d ja cadastrado.\n", rgm);

        } else if (opcao == 2) {
            mostrarAlunos(&sala);

        } else if (opcao == 3) {
            int rgm;
            printf("  RGM: ");
            scanf("%d", &rgm);
            limparBuffer();

            int idx = buscarAluno(&sala, rgm);
            if (idx == -1) {
                printf("  Aluno com RGM %d nao existe.\n", rgm);
            } else {
                printf("  Encontrado: [%d] %s\n",
                       sala.alunos[idx].rgm,
                       sala.alunos[idx].nome);
            }

        } else if (opcao == 4) {
            int rgm;
            printf("  RGM: ");
            scanf("%d", &rgm);
            limparBuffer();

            int resultado = removerAluno(&sala, rgm);
            if (resultado == -1) {
                printf("  Aluno com RGM %d nao existe.\n", rgm);
            } else {
                printf("  Aluno removido. Lista atual:\n");
                mostrarAlunos(&sala);
            }

        } else if (opcao != 0) {
            printf("  Opcao invalida.\n");
        }

    } while (opcao != 0);

    printf("\n  Encerrando...\n");
    return 0;
}