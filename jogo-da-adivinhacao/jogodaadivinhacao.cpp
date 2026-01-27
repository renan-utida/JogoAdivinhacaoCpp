#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
using namespace std;

// Exibe o cabeçalho do jogo
void exibir_cabecalho(){
    cout << "\n*************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhação! *" << endl;
    cout << "*************************************" << endl;
}

// Escolhe o nível de dificuldade e retorna o número de tentativas
int escolher_dificuldade(){
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

    return numero_de_tentativas;
}

// Escolhe o valor máximo para o jogo
int escolher_valor_maximo() {
    int valor_maximo;
    bool valor_valido = false;

    while(!valor_valido) {
        cout << "\nQual valor máximo deseja para o jogo?" << endl;
        cout << "(O número secreto será entre 0 e o valor escolhido)" << endl;
        cout << "Sugestões: 99 (padrão), 500 (médio), 1000 (desafiador)" << endl;
        cout << "Valor máximo: ";
        cin >> valor_maximo;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida! Por favor, digite um número inteiro positivo." << endl;
        } 
        else if(valor_maximo < 50) {
            cout << "Valor muito baixo! Por favor, escolha no mínimo 50." << endl;
        }
        else if(valor_maximo > 10000) {
            cout << "Valor muito alto! Por favor, escolha no máximo 10000." << endl;
        }
        else {
            valor_valido = true;
        }
    }

    return valor_maximo;
}

// Exibe as configurações do jogo
void exibir_configuracoes(int valor_maximo, int numero_de_tentativas) {
    cout << "\n🎮 Jogo configurado!" << endl;
    cout << "📊 Intervalo: 0 a " << valor_maximo << endl;
    cout << "🎯 Tentativas: " << numero_de_tentativas << endl;
}

// Valida e retorna o chute do jogador
int validar_chute(int tentativa_atual, int valor_maximo) {
    int chute;
    bool chute_valido = false;

    while(!chute_valido) {
        cout << "\nTentativa " << tentativa_atual << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida! Por favor, digite um número entre 0 e " << valor_maximo << "." << endl;
        } 
        else if(chute < 0 || chute > valor_maximo) {
            cout << "Número fora do intervalo! Por favor, digite um número entre 0 e " << valor_maximo << "." << endl;
        } 
        else {
            chute_valido = true;
        }
    }

    return chute;
}

// Calcula e retorna os pontos perdidos
double calcular_pontos_perdidos(int chute, int numero_secreto) {
    return abs(chute - numero_secreto) / 2.0;
}

// Processa o chute e retorna true se acertou
bool processar_chute(int chute, int numero_secreto) {
    cout << "O valor do seu chute é: " << chute << endl;

    if(chute == numero_secreto){
        cout << "\nParabéns! Você acertou o número secreto!" << endl;
        return true;
    } 
    else if (chute > numero_secreto) {
        cout << "Seu chute foi maior que o número secreto!" << endl;
    } 
    else {
        cout << "Seu chute foi menor que o número secreto!" << endl;
    }

    return false;
}

// Exibe o resultado final do jogo
void exibir_resultado(bool acertou, int numero_secreto, int tentativas, int numero_de_tentativas, double pontos) {
    if(!acertou){
        cout << "\n❌ Você perdeu! Suas tentativas acabaram." << endl;
        cout << "🔢 O número secreto era: " << numero_secreto << endl;
        cout << "Você chegou perto? Tente novamente!" << endl;
    } else {
        cout << "\n🎉 Parabéns! Você acertou o número secreto!" << endl;
        cout << "🔢 O número era: " << numero_secreto << endl;
        cout << "⏱️  Tentativas utilizadas: " << tentativas << " de " << numero_de_tentativas << endl;
        cout.precision(2);
        cout << fixed;
        cout << "⭐ Sua pontuação foi de " << pontos << " pontos." << endl;
    }  

    cout << "\n" << string(40, '=') << endl;
    cout << "Fim de jogo!" << endl;
    cout << string(40, '=') << endl;
}

// Pergunta se o jogador quer jogar novamente
bool perguntar_jogar_novamente() {
    bool resposta_valida = false;

    while(!resposta_valida) {
        cout << "\nDeseja jogar novamente? (S/N): ";
        char resposta;
        cin >> resposta;

        if(resposta == 'S' || resposta == 's') {
            return true;
        } else if(resposta == 'N' || resposta == 'n') {
            cout << "\nObrigado por jogar! Até a próxima! 👋" << endl;
            return false;
        } else {
            cout << "Opção inválida! Por favor, digite S para Sim ou N para Não." << endl;
        }
    }

    return false;
}

int main () {

    srand(time(NULL));
    bool jogar_novamente = true;

    while(jogar_novamente){
        
        // Exibe cabeçalho
        exibir_cabecalho();

        // Escolhe dificuldade
        int numero_de_tentativas = escolher_dificuldade();

        // Escolhe valor máximo
        int valor_maximo = escolher_valor_maximo();

        // Exibe configurações
        exibir_configuracoes(valor_maximo, numero_de_tentativas);

        // Gera o número secreto baseado no valor máximo escolhido
        const int NUMERO_SECRETO = rand() % (valor_maximo + 1);

        // Variáveis do jogo
        bool acertou = false;
        int tentativas = 0;
        double pontos = 1000.0;

        // Loop principal do jogo
        for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){

            // Valida o chute
            int chute = validar_chute(tentativas, valor_maximo);

            // Calcula pontos perdidos
            double pontos_perdidos = calcular_pontos_perdidos(chute, NUMERO_SECRETO);
            pontos = pontos - pontos_perdidos;

            // Processa o chute
            acertou = processar_chute(chute, NUMERO_SECRETO);

            // Se acertou, sai do loop
            if(acertou) {
                break;
            }
        }

        // Exibe resultado final
        exibir_resultado(acertou, NUMERO_SECRETO, tentativas, numero_de_tentativas, pontos);

        // Pergunta se quer jogar novamente
        
        jogar_novamente = perguntar_jogar_novamente();
    } 

    return 0;
}
