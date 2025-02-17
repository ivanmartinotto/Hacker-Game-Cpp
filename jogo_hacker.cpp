#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

struct Tarefa {
    string nome;
    int prioridade;
    int tempoRestante;
    int recompensa;

    Tarefa(string n, int p, int t, int r) : nome(n), prioridade(p), tempoRestante(t), recompensa(r) {}
};

class FilaDePrioridade {
private:
    vector<Tarefa> heap;

    void ajustarAcima(int indice) {
        while (indice > 0) {
            int pai = (indice - 1) / 2;
            if (heap[indice].prioridade <= heap[pai].prioridade)
                break;
            swap(heap[indice], heap[pai]);
            indice = pai;
        }
    }

    void ajustarAbaixo(int indice) {
        int filhoEsquerda, filhoDireita, maior;
        while (2 * indice + 1 < heap.size()) {
            filhoEsquerda = 2 * indice + 1;
            filhoDireita = 2 * indice + 2;
            maior = indice;

            if (filhoEsquerda < heap.size() && heap[filhoEsquerda].prioridade > heap[maior].prioridade)
                maior = filhoEsquerda;
            if (filhoDireita < heap.size() && heap[filhoDireita].prioridade > heap[maior].prioridade)
                maior = filhoDireita;
            
            if (maior == indice)
                break;

            swap(heap[indice], heap[maior]);
            indice = maior;
        }
    }

public:
    void inserir(Tarefa tarefa) {
        heap.push_back(tarefa);
        ajustarAcima(heap.size() - 1);
    }

    void remover() {
        if (heap.empty()) return;
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        ajustarAbaixo(0);
    }

    Tarefa topo() {
        if (!heap.empty()) return heap[0];
        return Tarefa("", -1, -1, -1); // Retorno inválido caso a fila esteja vazia
    }

    bool vazia() {
        return heap.empty();
    }

    void exibirTarefas() {
        if (heap.empty()) {
            cout << "Nenhuma tarefa pendente.\n";
            return;
        }
        cout << "\nLista de Tarefas:\n";
        cout << left << setw(25) << "Tarefa" << setw(12) << "Prioridade" << setw(15) << "Recompensa ($)" << "Tempo Restante" << "\n";
        cout << "----------------------------------------------------------\n";
        for (const auto& tarefa : heap) {
            cout << left << setw(25) << tarefa.nome << setw(12) << tarefa.prioridade << setw(15) << tarefa.recompensa << tarefa.tempoRestante << "\n";
        }
        cout << "----------------------------------------------------------\n";
    }
};

void adicionarTarefaAleatoria(FilaDePrioridade& filaTarefas) {
    vector<string> nomesTarefas = {"Invadir Servidor", "Roubar Dados", "Derrubar Rede", "Manipular Transação"};
    string nome = nomesTarefas[rand() % nomesTarefas.size()];
    int prioridade = rand() % 100 + 1;
    int tempoRestante = rand() % 10 + 3;
    int recompensa = rand() % 500 + 100;
    filaTarefas.inserir(Tarefa(nome, prioridade, tempoRestante, recompensa));
    cout << "Nova tarefa adicionada: " << nome << " (Prioridade: " << prioridade << ")\n";
}

void processarTarefas(FilaDePrioridade& filaTarefas, int& dinheiro, int& riscoDeteccao) {
    if (!filaTarefas.vazia()) {
        Tarefa tarefa = filaTarefas.topo();
        filaTarefas.remover();
        cout << "Executando: " << tarefa.nome << " - Recompensa: $" << tarefa.recompensa << "\n";
        dinheiro += tarefa.recompensa;
        riscoDeteccao -= rand() % 21;
    } else {
        cout << "Nenhuma tarefa pendente.\n";
    }
}