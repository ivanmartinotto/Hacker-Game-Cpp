#include "jogo_hacker.cpp"

int main() {
    srand(time(0));
    FilaDePrioridade filaTarefas;
    int saldo = 0;
    int riscoDeteccao = 50;
    
    while (riscoDeteccao > 0) {
        if (riscoDeteccao > 99){
            cout << "GAME OVER! Você foi detectado e perdeu todo seu dinheiro.";
            exit(0);
        }
        cout << "\nSaldo: $" << saldo << " | Risco de Detecção: " << riscoDeteccao << "%\n";
        filaTarefas.exibirTarefas();
        cout << "1. Adicionar tarefa aleatória\n2. Executar tarefa\n3. Sair\nEscolha: ";
        int escolha;
        cin >> escolha;
        
        if (escolha == 1) {
            adicionarTarefaAleatoria(filaTarefas);
            riscoDeteccao += rand() % 11;
        } else if (escolha == 2) {
                if(filaTarefas.vazia()){
                    cout << "Não há tarefas para executar. Escolha outra opção! \n" << endl;
                } else {
                    processarTarefas(filaTarefas, saldo, riscoDeteccao);
                }    
        } else {
            break;
        }
    }
    
    cout << "Jogo encerrado. Saldo final: $" << saldo << "\n";
    return 0;
}