# Arquitetura da Solução

## Visão geral

A aplicação combina duas estruturas de dados para resolver o problema:

**Lista Sequencial** → armazena os alunos em um vetor estático de tamanho fixo (60),
mantido em ordem crescente de RGM a cada inserção.

**Lista Encadeada** → cada aluno possui um ponteiro para o início de sua própria
cadeia de nós de disciplinas, alocados dinamicamente.

## Diagrama de memória
[ ListaAlunos — vetor estático ]
Index  RGM    Nome      disciplinas
0    100    João   ──► [Cálculo|●]──► [ED1|NULL]
1    200    Maria  ──► [APS|NULL]
2    300    Pedro  ──► [POO|●]──► [BD|●]──► [SO|NULL]

↑ alocação estática        ↑ alocação dinâmica (heap)

## Decisões de projeto

| Decisão | Justificativa |
|---|---|
| Inserção ordenada por RGM | Permite busca binária O(log n) |
| Inserção de disciplina no início | O(1) — não precisa percorrer a cadeia |
| `liberarDisciplinas` antes de remover | Evita memory leak |
| `NULL` como sentinela da lista encadeada | Padrão universal para fim de cadeia |