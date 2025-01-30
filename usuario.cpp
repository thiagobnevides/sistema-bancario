#include "usuario.h"
#include <stdexcept>

Usuario::Usuario(std::string nome, std::string cpf) : cpf(cpf), creditos(10) {
    setNome(nome);
}

std::string Usuario::getNome() const {
    return nome;
}

void Usuario::setNome(std::string novoNome) {
    if (novoNome.empty()) {
        throw std::invalid_argument("Nome não pode ser vazio.");
    }
    nome = novoNome;
}

std::string Usuario::getCPF() const {
    return cpf;
}

int Usuario::getCreditos() const {
    return creditos;
}

bool Usuario::adicionarCreditos(int quantidade) {
    if (quantidade <= 0) {
        return false;
    }
    creditos += quantidade;
    return true;
}

bool Usuario::removerCreditos(int quantidade) {
    if (quantidade <= 0 || creditos - quantidade < 0) {
        return false;
    }
    creditos -= quantidade;
    return true;
}

Usuario& Usuario::operator++() {
    creditos++;
    return *this;
}

Usuario Usuario::operator++(int) {
    Usuario temp = *this;
    ++(*this);
    return temp;
}

Usuario& Usuario::operator--() {
    if (creditos > 0) {
        creditos--;
    }
    return *this;
}

Usuario Usuario::operator--(int) {
    Usuario temp = *this;
    --(*this);
    return temp;
}
