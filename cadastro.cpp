#include "cadastro.h"

bool Cadastro::adicionarUsuario(Usuario usuario) {
    std::string cpf = usuario.getCPF();
    if (usuarios.find(cpf) != usuarios.end()) {
        return false;
    }
    usuarios.insert({cpf, usuario});
    return true;
}

std::map<std::string, Usuario> Cadastro::getUsuarios() const {
    return usuarios;
}

Usuario* Cadastro::getUsuarioPorCPF(const std::string& cpf) {
    auto it = usuarios.find(cpf);
    if (it != usuarios.end()) {
        return &it->second;
    }
    return nullptr;
}

bool Cadastro::adicionarCreditoPara(const std::string& cpf, int creditos) {
    Usuario* usuario = getUsuarioPorCPF(cpf);
    if (usuario) {
        return usuario->adicionarCreditos(creditos);
    }
    return false;
}

bool Cadastro::transferirCreditos(const std::string& cpf_origem, const std::string& cpf_destino, int creditos) {
    Usuario* origem = getUsuarioPorCPF(cpf_origem);
    Usuario* destino = getUsuarioPorCPF(cpf_destino);
    if (origem && destino && origem->removerCreditos(creditos)) {
        destino->adicionarCreditos(creditos);
        return true;
    }
    return false;
}

bool Cadastro::removerCreditos(const std::string& cpf, int quantidade) {
    Usuario* usuario = getUsuarioPorCPF(cpf);
    if (usuario) {
        return usuario->removerCreditos(quantidade);
    }
    return false;
}
