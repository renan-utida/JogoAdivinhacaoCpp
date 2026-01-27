# 🎯 Jogo de Adivinhação em C++

Projeto desenvolvido durante o curso **C++: Conhecendo a linguagem e a STL**, da plataforma **Alura**, com melhorias adicionais implementadas para aprimorar a experiência do jogador e a qualidade do código.

O objetivo do projeto é aplicar os principais conceitos iniciais da linguagem C++, como entrada e saída de dados, estruturas de controle, geração de números aleatórios, validação de entradas, modularização com funções e boas práticas de organização de código.

---

## 📌 Sobre o projeto

Neste jogo interativo, o computador escolhe um número secreto aleatório e o jogador deve tentar adivinhar esse número dentro de um limite de tentativas, que varia de acordo com o nível de dificuldade escolhido.

O sistema também permite personalizar o intervalo de valores e calcula uma pontuação baseada na precisão dos chutes do jogador.

---

## 🎮 Como funciona o jogo

### 1️⃣ Escolha do nível de dificuldade
O jogador escolhe entre três níveis de dificuldade (aceita maiúsculas e minúsculas):
- **Fácil (F/f)** → 15 tentativas  
- **Médio (M/m)** → 10 tentativas  
- **Difícil (D/d)** → 5 tentativas  

### 2️⃣ Definição do intervalo de valores
O jogador pode escolher o valor máximo para o jogo:
- **99** → Modo clássico (padrão)
- **500** → Modo intermediário
- **1000** → Modo desafiador
- Ou qualquer valor entre **50 e 10000**

### 3️⃣ Mecânica do jogo
- O programa gera um número secreto aleatório entre **0 e o valor máximo escolhido**
- A cada tentativa, o jogador informa um chute
- O programa indica se o chute foi:
  - ✅ **Correto** - Você venceu! 🎉
  - ⬆️ **Maior** que o número secreto
  - ⬇️ **Menor** que o número secreto

### 4️⃣ Sistema de pontuação
- Pontuação inicial: **1000 pontos**
- A pontuação diminui conforme a diferença entre o chute e o número secreto
- Fórmula: `pontos_perdidos = |chute - numero_secreto| / 2`

### 5️⃣ Final do jogo
O jogo termina quando:
- ✅ O jogador **acerta** o número secreto
- ❌ O jogador **esgota** todas as tentativas

Ao final, o número secreto é sempre revelado, junto com a pontuação (se acertou).

### 6️⃣ Jogar novamente
Após cada partida, o jogador pode escolher se deseja jogar novamente sem precisar reiniciar o programa.

---

## ✨ Funcionalidades implementadas

### 🎯 Funcionalidades do curso base
- ✅ Sistema de níveis de dificuldade
- ✅ Geração de números aleatórios
- ✅ Sistema de pontuação
- ✅ Feedback em tempo real (maior/menor)
- ✅ Contador de tentativas

### 🚀 Melhorias adicionais implementadas
- ✅ **Sistema de "jogar novamente"** - Permite múltiplas partidas sem reiniciar
- ✅ **Validação completa de entradas** - Impede erros com entradas inválidas
- ✅ **Intervalo customizável** - Jogador escolhe o valor máximo do jogo
- ✅ **Exibição do número secreto** - Mostra a resposta ao final da partida
- ✅ **Código modularizado** - Organizado em funções específicas
- ✅ **Mensagens aprimoradas** - Interface mais amigável e informativa
- ✅ **Suporte a maiúsculas/minúsculas** - Aceita F ou f, M ou m, S ou s, etc.

---

## 🧠 Conceitos praticados

### Conceitos básicos
- Entrada e saída de dados com `cin` e `cout`
- Estruturas de repetição (`while`, `for`)
- Estruturas condicionais (`if`, `else if`, `else`)
- Geração de números aleatórios (`rand`, `srand`, `time`)
- Uso de constantes (`const`)
- Operações matemáticas
- Controle de fluxo do programa
- Formatação de saída com `precision` e `fixed`

### Conceitos avançados
- **Validação de entradas** com `cin.fail()`, `cin.clear()` e `cin.ignore()`
- **Modularização** com funções
- **Passagem de parâmetros** por valor
- **Funções com retorno** (`int`, `bool`, `double`, `void`)
- **Funções com múltiplos parâmetros**
- **Biblioteca `<limits>`** para manipulação de buffer de entrada
- **Boas práticas** de organização e legibilidade de código

---

## 🛠️ Tecnologias e ferramentas

- **Linguagem:** C++
- **Bibliotecas:** `<iostream>`, `<cstdlib>`, `<ctime>`, `<limits>`
- **Compilador:** g++ (MinGW)
- **Editor:** Visual Studio Code
- **Sistema operacional:** Windows

---

## ▶️ Como compilar e executar

### 1️⃣ Compile o programa
No terminal, dentro da pasta do projeto:
```bash
g++ jogodaadivinhacao.cpp -o jogodaadivinhacao
```

### 2️⃣ Execute o jogo

**Windows:**
```bash
jogodaadivinhacao.exe
```

**Linux/Mac:**
```bash
./jogodaadivinhacao
```

---

## 📷 Exemplo de execução
```text
*************************************
* Bem-vindos ao jogo da adivinhação! *
*************************************

Escolha o seu nível de dificuldade: 
Fácil (F), Médio (M) ou Difícil (D)
D

Qual valor máximo deseja para o jogo?
(O número secreto será entre 0 e o valor escolhido)
Sugestões: 99 (padrão), 500 (médio), 1000 (desafiador)
Valor máximo: 1000

🎮 Jogo configurado!
📊 Intervalo: 0 a 1000
🎯 Tentativas: 5

Tentativa 1
Qual seu chute? 500
O valor do seu chute é: 500
Seu chute foi maior que o número secreto!

Tentativa 2
Qual seu chute? 250
O valor do seu chute é: 250
Seu chute foi menor que o número secreto!

Tentativa 3
Qual seu chute? 375
O valor do seu chute é: 375

🎉 Parabéns! Você acertou o número secreto!
🔢 O número era: 375
⏱️  Tentativas utilizadas: 3 de 5
⭐ Sua pontuação foi de 437.50 pontos.

========================================
Fim de jogo!
========================================

Deseja jogar novamente? (S/N): 
```

---

## 📁 Estrutura do código

O código foi organizado em **funções modulares** para melhor manutenibilidade:
```cpp
// Funções de interface
void exibir_cabecalho()
void exibir_configuracoes()
void exibir_resultado()

// Funções de entrada/escolha
int escolher_dificuldade()
int escolher_valor_maximo()
int validar_chute()
bool perguntar_jogar_novamente()

// Funções de lógica do jogo
double calcular_pontos_perdidos()
bool processar_chute()

// Função principal
int main()
```

---

## 🎓 Aprendizados do projeto

### Durante o curso
- ✅ Fundamentos de C++
- ✅ Estruturas de controle
- ✅ Geração de números aleatórios
- ✅ Sistema de pontuação

### Melhorias extras implementadas
- ✅ Validação robusta de entradas do usuário
- ✅ Modularização e organização de código
- ✅ Implementação de loops de controle
- ✅ Personalização da experiência do jogador
- ✅ Boas práticas de programação

---

## 🚀 Possíveis melhorias futuras

- [ ] Sistema de ranking/histórico de pontuações (salvar em arquivo)
- [ ] Modo multiplayer (dois jogadores se alternando)
- [ ] Dicas progressivas conforme erros
- [ ] Interface gráfica (GUI)
- [ ] Níveis de dificuldade personalizados
- [ ] Sistema de conquistas/badges
- [ ] Estatísticas de desempenho

---

## 📚 Curso de referência

- **C++: Conhecendo a linguagem e a STL**
- **Plataforma:** Alura
- **Instrutor:** Guilherme Lima
- **Carga horária:** 8 horas
- **Conclusão:** 22 de janeiro de 2026

---

## 👨‍💻 Autor

[<img loading="lazy" src="https://github.com/user-attachments/assets/b4f96f4b-542e-4988-9bc1-b1acf22a41a1" width=115><br><sub>Renan Dias Utida</sub>](https://github.com/renan-utida)

**Renan Dias Utida**  
Estudante de Engenharia de Software

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/renan-dias-utida-1b1228225/)
[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/renan-utida)

---

## 📄 Licença

Este projeto foi desenvolvido exclusivamente para fins educacionais.

---

## 📝 .gitignore

Crie um arquivo `.gitignore` na raiz do projeto com o seguinte conteúdo:
```gitignore
# Executáveis
*.exe
*.out
jogodaadivinhacao

# Arquivos de compilação
*.o
*.obj

# Arquivos do VS Code
.vscode/

# Arquivos do sistema
.DS_Store
Thumbs.db
```
