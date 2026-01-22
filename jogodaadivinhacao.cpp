#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main () {

    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da advinhação! *" << endl;
    cout << "*************************************" << endl;

    int numero_de_tentativas;

    bool dificuldade_nao_valida = true;

    while(dificuldade_nao_valida){
        cout << "\nEscolha o seu nível de dificuldade: " << endl;
        cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

        char dificuldade;
        cin >> dificuldade;
        
        if(dificuldade == 'F'){
            numero_de_tentativas = 15;
            dificuldade_nao_valida = false;
        } else if (dificuldade == 'M') {
            numero_de_tentativas = 10;
            dificuldade_nao_valida = false;
        } else if (dificuldade == 'D') {
            numero_de_tentativas = 5;
            dificuldade_nao_valida = false;
        } else {
            cout << "Por favor, digite F para Fácil, M para Médio ou D para Difícil!" << endl;
        }
    }
    

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){

        int chute;
        cout << "\nTentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

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
}