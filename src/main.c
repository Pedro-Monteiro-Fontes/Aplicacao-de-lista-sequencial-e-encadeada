#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/* Limpa o buffer do teclado após leituras com scanf */
static void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Loop de cadastro de disciplinas*/
static void cadastrarDisciplinas(Aluno *aluno) {
    char disc[MAX_DISC];
    char resposta;

    do {
        printf("    Nome da disciplina: ");
        fgets(disc, MAX_DISC, stdin);
        disc[strcspn(disc, "\n")] = '\0';

        if (inserirDisciplinas(aluno, disc) != 0) {
            printf("    Erro ao alocar disciplina.\n");
        }

        printf("    Mais disciplina? (s/n): ");
        scanf(" %c", &resposta);   /* espaço antes de %c consome o '\n' residual */
        limparBuffer();

    } while (resposta == 's' || resposta == 'S');
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

            if (resultado ==  0){
                printf("  Aluno inserido! Cadastre as disciplinas:\n");
                int idx = buscarAluno(&sala, rgm);
                cadastrarDisciplinas(&sala.alunos[idx]);
                printf("  Cadastro concluido!\n");
            }
            if (resultado == -1) printf("  Sala cheia (limite de %d alunos).\n", MAX_ALUNOS);
            if (resultado == -2) printf("  RGM %d ja cadastrado.\n", rgm);

        } else if (opcao == 2) {
           if (sala.tamanho == 0) {
                printf("  Nenhum aluno cadastrado.\n");
            } else {
                printf("  %-10s  %s\n", "RGM", "Nome");
                printf("  %-10s  %s\n", "----------", "--------------------");
                for (int i = 0; i < sala.tamanho; i++) {
                    printf("  %-10d  %s\n",
                           sala.alunos[i].rgm,
                           sala.alunos[i].nome);
                    listarDisciplinas(&sala.alunos[i]);
                }
            }
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