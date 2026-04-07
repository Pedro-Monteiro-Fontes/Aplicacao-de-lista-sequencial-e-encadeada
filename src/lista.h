#ifndef LISTA_H
#define LISTA_H

// Constantes

#define MAX_ALUNOS   60
#define MAX_NOME     100
#define MAX_DISC     80

// Nó de DisciplinaCada nó guarda o nome de uma disciplinae um ponteiro para o próximo nó.

typedef struct NoDisciplina {
    char nome[MAX_DISC];
    struct NoDisciplina *prox;
} NoDisciplina;

// AlunoCada aluno tem RGM, nome e um ponteiropara o início da sua lista de disciplinas.
typedef struct {
    int rgm;
    char nome[MAX_NOME];
    NoDisciplina *disciplinas;
} Aluno;

// SalaVetor estático de alunos + contagem atual.

typedef struct {
    Aluno alunos[MAX_ALUNOS];
    int tamanho;
} ListaAlunos;

// Protótipos / Funções

void inicializar(ListaAlunos *lista);
int  inserirAluno(ListaAlunos *lista, int rgm, const char *nome);
int  buscarAluno(const ListaAlunos *lista, int rgm);
int  removerAluno(ListaAlunos *lista, int rgm);
void mostrarAlunos(const ListaAlunos *lista);
int inserirDisciplinas(Aluno *aluno, const char *nome);
void listarDisciplinas(const Aluno *aluno);
void liberarDisciplinas(Aluno *aluno);

#endif