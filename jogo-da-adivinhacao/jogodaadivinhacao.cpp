#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
using namespace std;

int main () {

    srand(time(NULL));
    bool jogar_novamente = true;

    while(jogar_novamente){
        
        cout << "\n*************************************" << endl;
        cout << "* Bem-vindos ao jogo da adivinhação! *" << endl;
        cout << "*************************************" << endl;

        int numero_de_tentativas;
        bool dificuldade_nao_valida = true;

        while(dificuldade_nao_valida){
            cout << "\nEscolha o seu nível de dificuldade: " << endl;
            cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

            char dificuldade;
            cin >> dificuldade;
            
            if(dificuldade == 'F' || dificuldade == 'f'){
                numero_de_tentativas = 15;
                dificuldade_nao_valida = false;
            } else if (dificuldade == 'M' || dificuldade == 'm') {
                numero_de_tentativas = 10;
                dificuldade_nao_valida = false;
            } else if (dificuldade == 'D' || dificuldade == 'd') {
                numero_de_tentativas = 5;
                dificuldade_nao_valida = false;
            } else {
                cout << "Por favor, digite F para Fácil, M para Médio ou D para Difícil!" << endl;
            }
        }
        
        // Gera um NOVO número secreto para cada partida
        const int NUMERO_SECRETO = rand() % 100;

        bool nao_acertou = true;
        int tentativas = 0;
        double pontos = 1000.0;

        for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){

            int chute;
            bool chute_valido = false;

            // Loop de validação do chute
            while(!chute_valido) {
                cout << "\nTentativa " << tentativas << endl;
                cout << "Qual seu chute? ";
                cin >> chute;

                // Verifica se a entrada foi válida (é um número)
                if(cin.fail()) {
                    // Limpa o estado de erro do cin
                    cin.clear();
                    // Descarta a entrada inválida do buffer
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida! Por favor, digite um número entre 0 e 99." << endl;
                } 
                // Verifica se o número está no intervalo válido
                else if(chute < 0 || chute > 99) {
                    cout << "Número fora do intervalo! Por favor, digite um número entre 0 e 99." << endl;
                } 
                else {
                    // Chute válido!
                    chute_valido = true;
                }
            }

            double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
            pontos = pontos - pontos_perdidos;
            
            cout << "O valor do seu chute é: " << chute << endl;

            bool acertou = chute == NUMERO_SECRETO;
            bool maior = chute > NUMERO_SECRETO;

            if(acertou){
                cout << "\nParabéns! Você acertou o número secreto!" << endl;
                nao_acertou = false;
                break;
            } 
            else if (maior) {
                cout << "Seu chute foi maior que o número secreto!" << endl;
            } 
            else {
                cout << "Seu chute foi menor que o número secreto!" << endl;
            }
        }

        if(nao_acertou){
            cout << "\nVocê perdeu! Tente novamente" << endl;
        } else {
            cout << "\nVocê acertou o número secreto com " << tentativas << " tentativas!" << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
        }  

        cout << "\nFim de jogo!" << endl;

        // Validação da resposta de jogar novamente
        bool resposta_valida = false;

        while(!resposta_valida) {
            cout << "\nDeseja jogar novamente? (S/N): ";
            char resposta;
            cin >> resposta;

            if(resposta == 'S' || resposta == 's') {
                resposta_valida = true;
                jogar_novamente = true;
            } else if(resposta == 'N' || resposta == 'n') {
                resposta_valida = true;
                jogar_novamente = false;
                cout << "\nObrigado por jogar! Até a próxima! 👋" << endl;
            } else {
                cout << "Opção inválida! Por favor, digite S para Sim ou N para Não." << endl;
            }
        }
    } 

    return 0;
}
