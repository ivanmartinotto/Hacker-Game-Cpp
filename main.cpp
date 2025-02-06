#include "jogo_hacker.cpp"

int main() {
    srand(time(0));
    priority_queue<Task> taskQueue;
    int money = 0;
    int detectionRisk = 50;
    
    while (detectionRisk > 0) {
        cout << "\nSaldo: $" << money << " | Risco de Detecção: " << detectionRisk << "%\n";
        cout << "1. Adicionar tarefa aleatória\n2. Executar tarefa\n3. Sair\nEscolha: ";
        int choice;
        cin >> choice;
        
        if (detectionRisk < 100) {
            if (choice == 1) {
                addRandomTask(taskQueue);
                detectionRisk += 10;
            } else if (choice == 2) {
                processTasks(taskQueue, money, detectionRisk);
            } else {
                break;
            }
        } else {
            money = 0;
            cout << "Você foi detectado!!! Saldo final: $" << money << "\n";
            exit(0);
        }
    }
    
    cout << "Jogo encerrado. Saldo final: $" << money << "\n";
    return 0;
}
