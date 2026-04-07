# Aplicacao de lista-sequencial e encadeada
O mini projeto consiste em desenvolver uma aplicação console em linguagem C que gerencia uma sala de até 60 alunos. Cada aluno é identificado pelo seu RGM e possui uma lista de disciplinas de tamanho variável
## 📚 Sobre 
Colocando em prática o estudo de Estrutura de Dados 1, matéria ministrada por Walace Sartori Bonfim no segundo semestre de Ciência da Computação na UNIPÊ.
## 🛠️ Tecnologias
- Linguagem C (C99)
## 🏛 Arquitetura 
ListaAlunos (lista SEQUENCIAL — vetor estático)
│
├── alunos[0]: RGM 100 | João   → [Cálculo] → [ED1] → NULL
├── alunos[1]: RGM 200 | Maria  → [APS] → NULL
└── alunos[2]: RGM 300 | Pedro  → [POO] → [BD] → [SO] → NULL

| Estrutura | Tipo | Alocação | Critério de ordem |
|---|---|---|---|
| Lista de alunos | Sequencial | Estática (vetor fixo 60) | RGM crescente |
| Lista de disciplinas | Encadeada | Dinâmica (malloc/free) | Inserção no início |
## 🏗 Estrutura do projeto 
projetolistas/
├── .gitignore
├── src/
│   ├── main.c        → menu interativo e ponto de entrada
│   ├── lista_seq.c   → operações da lista sequencial de alunos
│   ├── lista_enc.c   → operações da lista encadeada de disciplinas
│   └── lista.h       → structs, constantes e protótipos
└── docs/
└── arquitetura.md
## 👾 Como compilar e executar

Pré-requisito: **GCC** instalado (MinGW no Windows).
```bash
# Na raiz do projeto
cd src
gcc -Wall -o ../app main.c lista_seq.c lista_enc.c
cd ..
.\app
```
## 👤 Autor
Pedro Monteiro Fontes - https://github.com/Pedro-Monteiro-Fontes
