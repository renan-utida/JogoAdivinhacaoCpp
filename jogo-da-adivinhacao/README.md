# 🎯 Jogo de Adivinhação em C++

Projeto desenvolvido durante o curso **C++: Conhecendo a linguagem e a STL**, da plataforma **Alura**.

O objetivo do projeto é aplicar os principais conceitos iniciais da linguagem C++, como entrada e saída de dados, estruturas de controle, geração de números aleatórios e boas práticas de organização de código, por meio da implementação de um jogo simples de adivinhação.

---

## 📌 Sobre o projeto

Neste jogo, o computador escolhe um número secreto aleatório e o jogador deve tentar adivinhar esse número dentro de um limite de tentativas, que varia de acordo com o nível de dificuldade escolhido.

O sistema também calcula uma pontuação baseada na precisão dos chutes do jogador.

---

## 🎮 Como funciona o jogo

1. O jogador escolhe o nível de dificuldade:
   - **Fácil (F)** → 15 tentativas  
   - **Médio (M)** → 10 tentativas  
   - **Difícil (D)** → 5 tentativas  

2. O programa gera um número secreto aleatório entre **0 e 99**.

3. A cada tentativa:
   - O jogador informa um chute
   - O programa indica se o chute foi:
     - Maior que o número secreto
     - Menor que o número secreto
     - Ou correto 🎉

4. A pontuação inicial é **1000 pontos**, e diminui conforme a diferença entre o chute e o número secreto.

5. O jogo termina quando:
   - O jogador acerta o número secreto
   - Ou acaba o número de tentativas

---

## 🧠 Conceitos praticados

- Entrada e saída de dados com `cin` e `cout`
- Estruturas de repetição (`while`, `for`)
- Estruturas condicionais (`if`, `else if`, `else`)
- Geração de números aleatórios (`rand`, `srand`, `time`)
- Uso de constantes (`const`)
- Operações matemáticas
- Controle de fluxo do programa
- Formatação de saída com `precision` e `fixed`

---

## 🛠️ Tecnologias e ferramentas

- **Linguagem:** C++
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

Tentativa 1
Qual seu chute? 50
Seu chute foi maior que o número secreto!
```

---

## 🚀 Possíveis melhorias futuras

- Permitir jogar novamente sem reiniciar o programa
- Validar entradas inválidas (letras no chute)
- Exibir o número secreto ao final do jogo
- Criar um ranking de pontuação
- Modularizar o código usando funções

---

## 📚 Curso de referência

- **C++: Conhecendo a linguagem e a STL**
- Plataforma: Alura

---

## 👨‍💻 Autor

[<img loading="lazy" src="https://github.com/user-attachments/assets/b4f96f4b-542e-4988-9bc1-b1acf22a41a1" width=115><br><sub>Renan Dias Utida</sub>](https://github.com/renan-utida)

Desenvolvido por **Renan Dias Utida**

Estudante de Engenharia de Software

#### Linkedin: https://www.linkedin.com/in/renan-dias-utida-1b1228225/

---

## 📄 Licença

Este projeto foi desenvolvido apenas para fins educacionais.

--- 

## ✅ Dica final (muito importante pro GitHub)

No seu repositório:
- Não suba o `.exe`
- Use um `.gitignore` com:
***.exe**

