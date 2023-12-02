// autoria: 222005386

#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <string>
#include <vector>

// ------------------ Entidade Conta -------------------
// inclui email (PK), nome e senha

/**@class Conta
 * @brief Representação da conta do usuário
 *
 * @author Laryssa - 222005386
 *
 * Regras do formato:
 *
 * - O e-mail é armazenado caso esteja no formato nome@domínio.
 * - O nome é composto por 2 a 10 caracteres.
 * - Domínio é composto por 2 a 20 caracteres.
 * - Cada caractere é letra (A-Z ou a-z), dígito (0 – 9) ou ponto (.).
 * - Caractere @ não pode ser imediatamente precedido ou sucedido por ponto (.).
 * - Não há pontos (.) em sequência.
 *
 * Esta classe contém informaçoes do usuário como nome, e-mail e senha.
*/

class Conta {
private:
    Email email;
    Texto nomeUsuario;
    Senha senha;

public:

    /**
    * @brief Define o atributo objeto email da classe
    *
    * Armazena o e-mail do usuário, caso seja válido
    *
    * @param Instância da classe domínio Email, representando o e-mail do usuário
    *
    */

    void setEmail(const Email&);


    /**
    *
    * @brief Retorna o atributo objeto email da classe
    *
    * busca o e-mail do usuário
    *
    * @return objeto Email representando o email do usuário
    */

    Email getEmail() const;

    /**
    * @brief Define o atributo objeto nomeUsuario da classe
    *
    * Armazena o nome do usuário, caso seja válido
    *
    * @param Instância da classe domínio Texto, representando o nome do usuário
    *
    */

    void setNomeUsuario(const Texto&); // Alterado o nome do método para setNome

    /**
    *
    * @brief Retorna o atributo objeto nomeUsuario da classe
    *
    * busca o nome do usuário
    *
    * @return objeto Texto representando o nome do usuário
    */

    Texto getNomeUsuario() const;      // Alterado o nome do método para getNome

    /**
    * @brief Define o atributo objeto senha da classe.
    *
    * Armazena a senha do usuário, caso seja válido
    *
    * @param Instância da classe domínio Senha, representando a senha do usuário
    *
    */

    void setSenha(const Senha&);

    /**
    *
    * @brief Retorna o atributo objeto senha da classe
    *
    * busca a senha do usuário
    *
    * @return objeto Senha representando a senha do usuário
    */

    Senha getSenha() const;
};

// implementacao dos metodos da entidade Conta --------------

inline void Conta::setEmail(const Email& email) {
    this->email = email;
}

inline Email Conta::getEmail() const {
    return email;
}

inline void Conta::setNomeUsuario(const Texto& nomeUsuario) {
    this->nomeUsuario = nomeUsuario;
}

inline Texto Conta::getNomeUsuario() const {
    return nomeUsuario;
}

inline void Conta::setSenha(const Senha& senha) {
    this->senha = senha;
}

inline Senha Conta::getSenha() const {
    return senha;
}

// ------------------ Entidade Quadro -------------------
// recebe codigo, nome, descricao e limite

/** @class Quadro
 * @brief Representação do quadro criado pelo usuário
 *
 * @author Laryssa - 222005386
 * Regras do formato:
 *
 * O quadro é criado caso atenda as restrições definidas para os domínios Codigo, Texto e Limite.
 *
 * É possível definir e buscar as informações definidas para o quadro, como código, o nome do quadro, descrição e limite de cartoes.
 *
*/

class Quadro {
private:
    Codigo codigo;
    Texto nomeQuadro;
    Texto descricaoQuadro;
    Limite limite;
    Email emailConta; // Chave estrangeira referenciando a Conta

public:

    /**
    * @brief Define o atributo objeto codigo da classe.
    *
    * Armazena o codigo do quadro, caso seja válido.
    *
    * @param Instância da classe domínio Codigo, representando o codigo do quadro.
    *
    */

    void setCodigo(const Codigo&);

    /**
    *
    * @brief Retorna o atributo objeto codigo da classe.
    *
    * busca o código do quadro.
    *
    * @return objeto Codigo representando o código do quadro.
    */

    Codigo getCodigo() const;

    /**
    * @brief Define o atributo objeto nomeQuadro da classe.
    *
    * Armazena o nome do quadro, caso seja válido.
    *
    * @param Instância da classe domínio Texto, representando o nome do quadro.
    *
    */

    void setNomeQuadro(const Texto&); // Alterado o nome do método para setNome

    /**
    *
    * @brief Retorna o atributo objeto nomeQuadro da classe.
    *
    * busca o nome do quadro.
    *
    * @return objeto Codigo representando o nome do quadro.
    */

    Texto getNomeQuadro() const;      // Alterado o nome do método para getNome

    /**
    * @brief Define o atributo objeto descricaoQuadro da classe.
    *
    * Armazena a descrição do quadro, caso seja válido.
    *
    * @param Instância da classe domínio Texto, representando a descrição do quadro.
    *
    */

    void setDescricaoQuadro(const Texto&); // Alterado o nome do método para setDescricao

    /**
    *
    * @brief Retorna o atributo objeto descricaoQuadro da classe.
    *
    * busca a descrição do quadro.
    *
    * @return objeto Texto representando o nome do quadro.
    */

    Texto getDescricaoQuadro() const;      // Alterado o nome do método para getDescricao

    /**
    * @brief Define o atributo objeto limite da classe.
    *
    * Armazena o limite de cartões do quadro, caso seja válido.
    *
    * @param Instância da classe domínio Limite, representando o limite de cartões.
    *
    */

    void setLimite(const Limite&);

    /**
    *
    * @brief Retorna o atributo objeto limite da classe.
    *
    * busca o limite do quadro.
    *
    * @return objeto Limite representando o limite do quadro.
    */

    Limite getLimite() const;

    
    void setEmailConta(const Email&); 

    // foreign key (FK) email
    Email getEmailConta() const;
};

// implementacao dos metodos da entidade Quadro --------------

inline void Quadro::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

inline Codigo Quadro::getCodigo() const {
    return codigo;
}

inline void Quadro::setNomeQuadro(const Texto& nomeQuadro) {
    this->nomeQuadro = nomeQuadro;
}

inline Texto Quadro::getNomeQuadro() const {
    return nomeQuadro;
}

inline void Quadro::setDescricaoQuadro(const Texto& descricaoQuadro) {
    this->descricaoQuadro = descricaoQuadro;
}

inline Texto Quadro::getDescricaoQuadro() const {
    return descricaoQuadro;
}

inline void Quadro::setLimite(const Limite& limite) {
    this->limite = limite;
}

inline Limite Quadro::getLimite() const {
    return limite;
}

inline void Quadro::setEmailConta(const Email& email) {
    this->emailConta = email;
}

inline Email Quadro::getEmailConta() const { // foreign key (FK) email
    return emailConta;
}

// ------------------ Entidade Cartao -------------------
// recebe codigo, nome, descricao e coluna

/** @class Cartao
 * @brief Representação do Cartão criado pelo usuário
 *
 * @author Laryssa - 222005386
 *
 * Regras do formato:
 *
 * O cartão é criado caso atenda as restrições definidas para os domínios Codigo, Texto e Coluna.
 *
 * É possível definir e buscar as informações definidas para o cartão, como código, o nome do cartão, descrição e coluna do cartao.
 *
*/

class Cartao {
private:
    Codigo codigo;
    Codigo codigoQuadro; // Chave estrangeira referenciando o Código do Quadro
    Texto nomeCartao;
    Texto descricaoCartao;
    Coluna coluna;

public:

    /**
    * @brief Define o atributo objeto codigo da classe.
    *
    * Armazena o codigo do quadro, caso seja válido.
    *
    * @param Instância da classe domínio Codigo, representando o codigo do cartao.
    *
    */

    void setCodigo(const Codigo&);

    /**
    *
    * @brief Retorna o atributo objeto codigo da classe.
    *
    * busca o codigo do quadro.
    *
    * @return objeto Codigo representando o codigo do quadro.
    */

    Codigo getCodigo() const;

    /**
    * @brief Define o atributo objeto nomeCartao da classe.
    *
    * Armazena o nome do cartão, caso seja válido.
    *
    * @param Instância da classe domínio Texto, representando o nome do cartao.
    *
    */

    void setNomeCartao(const Texto&);

    /**
    *
    * @brief Retorna o atributo objeto nomeCartao da classe.
    *
    * busca o nome do cartão.
    *
    * @return objeto Texto representando o nome do cartão.
    */

    Texto getNomeCartao() const;

    /**
    * @brief Define o atributo objeto descricaoCartao da classe.
    *
    * Armazena a descrição do cartão, caso seja válido.
    *
    * @param Instância da classe domínio Texto, representando a descrição do cartao.
    *
    */

    void setDescricaoCartao(const Texto&);

    /**
    *
    * @brief Retorna o atributo objeto descricaoCartao da classe.
    *
    * busca a descrição do cartão.
    *
    * @return objeto Texto representando a descrição do cartão.
    */

    Texto getDescricaoCartao() const;

    /**
    * @brief Define o atributo objeto coluna da classe.
    *
    * Armazena a coluna do cartão, caso seja válida.
    *
    * @param Instância da classe domínio Coluna, representando a coluna do cartao.
    *
    */

    void setColuna(const Coluna&);

    /**
    *
    * @brief Retorna o atributo objeto coluna da classe.
    *
    * busca a coluna do cartão.
    *
    * @return objeto Coluna representando a coluna do cartão.
    */

    Coluna getColuna() const;

    void setCodigoQuadro(const Codigo&); 

    // referencia ao codigo do quadro
    Codigo getCodigoQuadro() const;
};

inline void Cartao::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

inline Codigo Cartao::getCodigo() const {
    return codigo;
}

inline void Cartao::setNomeCartao(const Texto& nomeCartao) {
    this->nomeCartao = nomeCartao;
}

inline Texto Cartao::getNomeCartao() const {
    return nomeCartao;
}

inline void Cartao::setDescricaoCartao(const Texto& descricaoCartao) {
    this->descricaoCartao = descricaoCartao;
}

inline Texto Cartao::getDescricaoCartao() const {
    return descricaoCartao;
}

inline void Cartao::setColuna(const Coluna& coluna) {
    this->coluna = coluna;
}

inline Coluna Cartao::getColuna() const {
    return coluna;
}

inline void Cartao::setCodigoQuadro(const Codigo& codigoQuadro) {
    this->codigoQuadro = codigoQuadro;   // nomenclatura correta? (?)
}

inline Codigo Cartao::getCodigoQuadro() const {
    return codigoQuadro;
}

#endif // ENTIDADES_H_INCLUDED
