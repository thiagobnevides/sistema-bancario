#ifndef CADASTRO_H
#define CADASTRO_H

#include "usuario.h"
#include <map>

class Cadastro {
private:
    std::map<std::string, Usuario> usuarios;

public:
    bool adicionarUsuario(Usuario usuario);
    std::map<std::string, Usuario> getUsuarios() const;
    Usuario* getUsuarioPorCPF(const std::string& cpf);
    bool adicionarCreditoPara(const std::string& cpf, int creditos);
    bool transferirCreditos(const std::string& cpf_origem, const std::string& cpf_destino, int creditos);
    bool removerCreditos(const std::string& cpf, int quantidade);
};

#endif 
