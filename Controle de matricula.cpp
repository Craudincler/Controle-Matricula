#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

struct Aluno {
    int identificador;
    string nome;
    float media;
    bool aprovado;
};

const int MAX_ALUNOS = 50;
Aluno alunos[MAX_ALUNOS];
int numAlunos = 0;

// Função para verificar se o vetor está ordenado
bool isOrdenado() {
    for (int i = 0; i < numAlunos - 1; i++) {
        if (alunos[i].identificador > alunos[i + 1].identificador) {
            return false;
        }
    }
    return true;
}

// Função para adicionar um aluno
void adicionarAluno() {
    if (numAlunos >= MAX_ALUNOS) {
        cout << "O vetor está lotado.\n";
        return;
    }

    int identificador;
    cout << "Digite o identificador do aluno: ";
    cin >> identificador;

    // Verificar se o aluno já existe
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].identificador == identificador) {
            cout << "Aluno já está presente no vetor.\n";
            return;
        }
    }

    Aluno novoAluno;
    novoAluno.identificador = identificador;
    cout << "Digite o nome do aluno: ";
    cin.ignore();
    getline(cin, novoAluno.nome);
    cout << "Digite a media do aluno: ";
    cin >> novoAluno.media;
    novoAluno.aprovado = novoAluno.media >= 7;

    alunos[numAlunos] = novoAluno;
    numAlunos++;
    cout << "Aluno adicionado com sucesso.\n";
}

// Função de busca sequencial
int buscaSequencial(int identificador) {
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].identificador == identificador) {
            return i;
        }
    }
    return -1;
}

// Função de busca binária
int buscaBinaria(int identificador, int esquerda, int direita) {
    if (direita >= esquerda) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (alunos[meio].identificador == identificador)
            return meio;
        if (alunos[meio].identificador > identificador)
            return buscaBinaria(identificador, esquerda, meio - 1);
        return buscaBinaria(identificador, meio + 1, direita);
    }
    return -1;
}

// Função para buscar um aluno
void buscarAluno() {
    int identificador;
    cout << "Digite o identificador do aluno: ";
    cin >> identificador;

    cout << "Escolha o método de busca:\n";
    cout << "1. Busca Sequencial\n";
    cout << "2. Busca Binária\n";
    int opcao;
    cin >> opcao;

    int posicao = -1;
    if (opcao == 1) {
        posicao = buscaSequencial(identificador);
    } else if (opcao == 2) {
        if (!isOrdenado()) {
            cout << "O vetor deve estar ordenado para busca binária.\n";
            return;
        }
        posicao = buscaBinaria(identificador, 0, numAlunos - 1);
    }

    if (posicao == -1) {
        cout << "Aluno não encontrado.\n";
    } else {
        cout << "Aluno encontrado:\n";
        cout << "Identificador: " << alunos[posicao].identificador << "\n";
        cout << "Nome: " << alunos[posicao].nome << "\n";
        cout << "Media: " << alunos[posicao].media << "\n";
        cout << "Aprovado: " << (alunos[posicao].aprovado ? "Sim" : "Não") << "\n";
    }
}

// Funções de ordenação
void insertionSort() {
    for (int i = 1; i < numAlunos; i++) {
        Aluno key = alunos[i];
        int j = i - 1;
        while (j >= 0 && alunos[j].identificador > key.identificador) {
            alunos[j + 1] = alunos[j];
            j = j - 1;
        }
        alunos[j + 1] = key;
    }
}

void selectionSort() {
    for (int i = 0; i < numAlunos - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numAlunos; j++) {
            if (alunos[j].identificador < alunos[minIndex].identificador) {
                minIndex = j;
            }
        }
        Aluno temp = alunos[minIndex];
        alunos[minIndex] = alunos[i];
        alunos[i] = temp;
    }
}

void quickSort(int low, int high) {
    if (low < high) {
        int pivot = alunos[high].identificador;
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (alunos[j].identificador <= pivot) {
                i++;
                Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
        Aluno temp = alunos[i + 1];
        alunos[i + 1] = alunos[high];
        alunos[high] = temp;
        int pi = i + 1;

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

// Função para ordenar alunos
void ordenarAlunos() {
    if (isOrdenado()) {
        cout << "O vetor já está ordenado.\n";
        return;
    }

    cout << "Escolha o método de ordenação:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Quicksort\n";
    int opcao;
    cin >> opcao;

    switch (opcao) {
        case 1:
            insertionSort();
            break;
        case 2:
            selectionSort();
            break;
        case 3:
            quickSort(0, numAlunos - 1);
            break;
        default:
            cout << "Opção inválida.\n";
            return;
    }
    cout << "Alunos ordenados com sucesso.\n";
}

// Função para exibir alunos
void exibirAlunos() {
    cout << "Escolha o critério de exibição:\n";
    cout << "1. Alunos aprovados\n";
    cout << "2. Alunos reprovados\n";
    cout << "3. Alunos com média >= 9\n";
    cout << "4. Alunos com média <= 5\n";
    cout << "5. Todos os alunos\n";
    int opcao;
    cin >> opcao;

    for (int i = 0; i < numAlunos; i++) {
        bool exibir = false;
        switch (opcao) {
            case 1:
                if (alunos[i].aprovado) exibir = true;
                break;
            case 2:
                if (!alunos[i].aprovado) exibir = true;
                break;
            case 3:
                if (alunos[i].media >= 9) exibir = true;
                break;
            case 4:
                if (alunos[i].media <= 5) exibir = true;
                break;
            case 5:
                exibir = true;
                break;
            default:
                cout << "Opção inválida.\n";
                return;
        }

        if (exibir) {
            cout << "Identificador: " << alunos[i].identificador << "\n";
            cout << "Nome: " << alunos[i].nome << "\n";
            cout << "Media: " << alunos[i].media << "\n";
            cout << "Aprovado: " << (alunos[i].aprovado ? "Sim" : "Não") << "\n";
            cout << "-------------------\n";
        }
    }
}

// Função para remover uma matrícula específica
void removerMatricula(int identificador) {
    int index = buscaSequencial(identificador);
    if (index == -1) {
        cout << "Matrícula não encontrada.\n";
        return;
    }
    for (int i = index; i < numAlunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    numAlunos--;
    cout << "Matrícula removida com sucesso.\n";
}

// Função para remover todas as matrículas
void removerTodasMatriculas() {
    numAlunos = 0;
    cout << "Todas as matrículas foram removidas com sucesso.\n";
}

// Função principal
int main() {
    int opcao;
    do {
        cout << "Escolha uma opção:\n";
        cout << "1. Adicionar Aluno\n";
        cout << "2. Buscar Aluno\n";
        cout << "3. Ordenar Alunos\n";
        cout << "4. Exibir Alunos\n";
        cout << "5. Remover uma Matrícula\n";
        cout << "6. Remover todas as Matrículas\n";
        cout << "7. Sair\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarAluno();
                break;
            case 2:
                buscarAluno();
                break;
            case 3:
                ordenarAlunos();
                break;
            case 4:
                exibirAlunos();
                break;
            case 5: {
                int identificador;
                cout << "Digite o identificador do aluno a ser removido: ";
                cin >> identificador;
                removerMatricula(identificador);
                break;
            }
            case 6:
                removerTodasMatriculas();
                break;
            case 7:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 7);

    return 0;
}
