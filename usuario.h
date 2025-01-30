#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string nome;
    std::string cpf;
    int creditos;

public:
    Usuario(std::string nome, std::string cpf);

    std::string getNome() const;
    void setNome(std::string novoNome);
    std::string getCPF() const;
    int getCreditos() const;

    bool adicionarCreditos(int quantidade);
    bool removerCreditos(int quantidade);

    Usuario& operator++();
    Usuario operator++(int);
    Usuario& operator--();
    Usuario operator--(int);
};

#endif 
