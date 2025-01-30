#include <iostream>
#include "cadastro.h"
#include "usuario.h"

void exibirMenu() {
  std::cout << "\n===== MENU =====\n";
  std::cout << "1. Adicionar usuário\n";
  std::cout << "2. Listar todos os usuários\n";
  std::cout << "3. Buscar usuário por CPF\n";
  std::cout << "4. Adicionar créditos a um usuário\n";
  std::cout << "5. Remover créditos de um usuário\n";
  std::cout << "6. Transferir créditos entre usuários\n";
  std::cout << "7. Incrementar créditos de um usuário (++)\n";
  std::cout << "8. Decrementar créditos de um usuário (--)\n";
  std::cout << "0. Sair\n";
  std::cout << "Escolha uma opção: ";
}

int main() {
  Cadastro cadastro;
  int opcao;

  do {
    exibirMenu();
    std::cin >> opcao;

    switch (opcao) {
    case 1: {
      std::string nome;
      std::string cpf;
      std::cout << "Digite o nome do usuário: ";
      std::cin.ignore();
      std::getline(std::cin, nome);

      if (nome.empty()) {
        std::cout << "Erro: Nome não pode ser vazio.\n";
        break;
      }

      std::cout << "Digite o CPF do usuário: ";
      std::getline(std::cin, cpf);

      Usuario novoUsuario(nome, cpf);
      if (cadastro.adicionarUsuario(novoUsuario)) {
        std::cout << "Usuário adicionado com sucesso!\n";
      } else {
        std::cout << "Erro: CPF já cadastrado.\n";
      }
      break;
    }

    case 2: {
      std::cout << "\n=== Usuários Cadastrados ===\n";
      if (cadastro.getUsuarios().empty()) {
        std::cout << "Nenhum usuário cadastrado.\n";
      } else {
        for (const auto &par : cadastro.getUsuarios()) {
          std::cout << "CPF: " << par.first
                    << ", Nome: " << par.second.getNome()
                    << ", Créditos: " << par.second.getCreditos() << "\n";
        }
      }
      break;
    }

    case 3: {
      std::string cpf;
      std::cout << "Digite o CPF do usuário: ";
      std::cin.ignore();
      std::getline(std::cin, cpf);

      Usuario *usuario = cadastro.getUsuarioPorCPF(cpf);
      if (usuario) {
        std::cout << "Usuário encontrado:\n";
        std::cout << "Nome: " << usuario->getNome()
                  << ", Créditos: " << usuario->getCreditos() << "\n";
      } else {
        std::cout << "Usuário não encontrado.\n";
      }
      break;
    }

    case 4: {
      std::string cpf;
      int creditos;

      std::cout << "Digite o CPF do usuário: ";
      std::cin.ignore();
      std::getline(std::cin, cpf);

      std::cout << "Digite a quantidade de créditos a adicionar: ";
      std::cin >> creditos;

      if (cadastro.adicionarCreditoPara(cpf, creditos)) {
        std::cout << "Créditos adicionados com sucesso!\n";
      } else {
        std::cout << "Erro: CPF não encontrado ou quantidade inválida.\n";
      }
      break;
    }

    case 5: {
      std::string cpf;
      int quantidade;
      std::cout << "Digite o CPF do usuário: ";
      std::cin.ignore();
      std::getline(std::cin, cpf);
      std::cout << "Digite a quantidade de créditos a remover: ";
      std::cin >> quantidade;

      if (cadastro.removerCreditos(cpf, quantidade)) {
        std::cout << "Créditos removidos com sucesso!\n";
      } else {
        std::cout << "Erro: CPF não encontrado ou quantidade inválida.\n";
      }
      break;
    }

    case 6: {
      std::string cpf_origem, cpf_destino;
      int creditos;
      std::cin.ignore();
      std::cout << "Digite o CPF de origem: ";
      std::getline(std::cin, cpf_origem);
      std::cout << "Digite o CPF de destino: ";
      std::getline(std::cin, cpf_destino);
      std::cout << "Digite a quantidade de créditos a transferir: ";
      std::cin >> creditos;

      if (cadastro.transferirCreditos(cpf_origem, cpf_destino, creditos)) {
        std::cout << "Transferência realizada com sucesso!\n";
      } else {
        std::cout << "Erro: CPFs inválidos ou créditos insuficientes.\n";
      }
      break;
    }

    case 7: {
      std::string cpf;
      std::cout << "Digite o CPF do usuário: ";
      std::cin >> cpf;
      std::cin.ignore();

      Usuario *usuario = cadastro.getUsuarioPorCPF(cpf);
      if (usuario) {
        ++(*usuario);
        std::cout << "Créditos incrementados com sucesso!\n";
      } else {
        std::cout << "Erro: CPF não encontrado.\n";
      }
      break;
    }

    case 8: {
      std::string cpf;
      std::cout << "Digite o CPF do usuário: ";
      std::cin >> cpf;
      std::cin.ignore();

      Usuario *usuario = cadastro.getUsuarioPorCPF(cpf);
      if (usuario) {
        if (usuario->getCreditos() > 0) {
          --(*usuario);
          std::cout << "Créditos decrementados com sucesso!\n";
        } else {
          std::cout << "Erro: Não há créditos suficientes para retirar.\n";
        }
      } else {
        std::cout << "Erro: CPF não encontrado.\n";
      }
      break;
    }

    case 0: {
      std::cout << "Programa finalizado\n";
      break;
    }

    default: {
      std::cout << "Opção inválida. Tente novamente.\n";
      break;
    }
    }
  } while (opcao != 0);

  return 0;
}
