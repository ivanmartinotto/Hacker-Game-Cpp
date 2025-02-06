#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Task {
    string name;
    int priority;
    int timeRemaining;
    int reward;
    
    Task(string n, int p, int t, int r) : name(n), priority(p), timeRemaining(t), reward(r) {}
    
    bool operator<(const Task& other) const {
        return priority < other.priority; // Ordem decrescente de prioridade
    }
};

void addRandomTask(priority_queue<Task>& taskQueue) {
    vector<string> taskNames = {"Invadir Servidor", "Roubar Dados", "Derrubar Rede", "Manipular Transação"};
    string name = taskNames[rand() % taskNames.size()];
    int priority = rand() % 100 + 1;
    int timeRemaining = rand() % 10 + 3;
    int reward = rand() % 500 + 100;
    taskQueue.push(Task(name, priority, timeRemaining, reward));
    cout << "Nova tarefa adicionada: " << name << " (Prioridade: " << priority << ")\n";
}

void processTasks(priority_queue<Task>& taskQueue, int& money, int& detectionRisk) {
    if (!taskQueue.empty()) {
        Task task = taskQueue.top();
        taskQueue.pop();
        cout << "Executando: " << task.name << " - Recompensa: $" << task.reward << "\n";
        money += task.reward;
        detectionRisk -= 5;
    } else {
        cout << "Nenhuma tarefa pendente.\n";
    }
}
