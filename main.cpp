#include "jogo_hacker.cpp"

int main() {
    srand(time(0));
    priority_queue<Task> taskQueue;
    int money = 0;
    int detectionRisk = 50;
    
    while (detectionRisk > 0) {
        if (detectionRisk > 99){
            cout << "GAME OVER! Você foi detectado e perdeu todo seu dinheiro.";
            exit(0);
        }
        cout << "\nSaldo: $" << money << " | Risco de Detecção: " << detectionRisk << "%\n";
        displayTasks(taskQueue);
        cout << "1. Adicionar tarefa aleatória\n2. Executar tarefa\n3. Sair\nEscolha: ";
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            addRandomTask(taskQueue);
            detectionRisk += rand() % 11;
        } else if (choice == 2) {
            processTasks(taskQueue, money, detectionRisk);
        } else {
            break;
        }
    }
    
    cout << "Jogo encerrado. Saldo final: $" << money << "\n";
    return 0;
}