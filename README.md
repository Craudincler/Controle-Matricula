# Sistema de Gerenciamento de Alunos
Este projeto é um programa em C++ para gerenciar informações de alunos. Ele permite adicionar, buscar, ordenar, exibir e remover alunos de uma lista. O sistema é baseado em um array de estrutura Aluno e oferece várias funcionalidades úteis para manipular os dados.

# Funcionalidades
 Adicionar Alunos:
  - Insere um aluno na lista com os atributos: identificador, nome, média e status de aprovação.
  - Verifica se o identificador já existe antes de adicionar.
  - Calcula automaticamente o status de aprovação baseado na média (>= 7).
    
Buscar Alunos:
  - Busca alunos na lista por identificador usando dois métodos:
  - Busca Sequencial.
  - Busca Binária (requer lista ordenada).
    
Ordenar Alunos:
-Ordena os alunos por identificador usando:
  - Insertion Sort.
  - Selection Sort.
  - QuickSort.
    
Exibir Alunos:
  -Filtra e exibe alunos com base nos seguintes critérios:
    - Apenas aprovados.
    - Apenas reprovados.
    - Média maior ou igual a 9.
    - Média menor ou igual a 5.
  Todos os alunos.
  
Remover Matrículas:
  - Remove um aluno específico pelo identificador.
  - Remove todos os alunos da lista.
    
Interface Simples:

Menu interativo para facilitar a navegação e o uso das funcionalidades.
