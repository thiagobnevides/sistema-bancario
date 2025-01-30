# Gerenciamento de Usuários e Créditos

Este é um programa em C++ para gerenciar usuários e seus créditos. Permite adicionar usuários, listar os cadastrados, buscar um usuário por CPF, adicionar e remover créditos, além de realizar transferências entre usuários.

## Estrutura do Projeto
O projeto é modularizado em diferentes arquivos:

- `usuario.h` - Declaração da classe `Usuario`
- `usuario.cpp` - Implementação da classe `Usuario`
- `cadastro.h` - Declaração da classe `Cadastro`
- `cadastro.cpp` - Implementação da classe `Cadastro`
- `main.cpp` - Arquivo principal que gerencia a execução do programa

## Funcionalidades
- Adicionar um novo usuário
- Listar todos os usuários
- Buscar um usuário por CPF
- Adicionar créditos a um usuário
- Remover créditos de um usuário
- Transferir créditos entre usuários
- Incrementar e decrementar créditos usando operadores `++` e `--`

## Como Compilar e Executar
Para compilar o projeto, utilize o seguinte comando no terminal:

```bash
g++ -o programa main.cpp Usuario.cpp Cadastro.cpp
```

Isso gerará um executável chamado `programa`. Para executá-lo, use:

```bash
./programa
```

## Exemplo de Uso
O programa exibe um menu interativo onde você pode escolher opções digitando o número correspondente:

```
===== MENU =====
1. Adicionar usuário
2. Listar todos os usuários
3. Buscar usuário por CPF
4. Adicionar créditos a um usuário
5. Remover créditos de um usuário
6. Transferir créditos entre usuários
7. Incrementar créditos de um usuário (++)
8. Decrementar créditos de um usuário (--)
0. Sair
Escolha uma opção:
```

## Requisitos
- Compilador C++ (g++, clang++ ou MSVC)
- Sistema operacional compatível (Linux, Windows ou macOS)

## Autor
Thiago de Araújo Benevides
