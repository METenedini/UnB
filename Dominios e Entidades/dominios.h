#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

// ---------------------------------------------------------------------------------
// CLASSE LIMITE - 22005395
// ---------------------------------------------------------------------------------

/**@class Limite
 * @brief Classe armazena um limite inteiro.
 * @author Lurian - 22005395
 *
 * @details
 * O limite s&oacute; &eacute; v&aacute;lido para os seguintes valores: 5, 10, 15, 20.
 *
 */

class Limite
{
private:
    int limite;

public:

    /**
    * @brief Define um limite de cartões.
    *
    * Armazena um limite de cartões. Os limites possíveis são: 5, 10, 15, 20, 25.
    *
    * @param int, representando um limite a ser armazenado.
    *
    * @throw invalid_argument caso n&atilde;o seja nenhum dos valores v&aacute;lido.
    *
    */

    void setLimite(int);

    /**
    * @brief Retorna o limite armazenado.
    *
    * @return int representando o limite.
    *
    */

    int getLimite() const {return limite;};
};

// ---------------------------------------------------------------------------------
// CLASSE COLUNA - 211026548
// ---------------------------------------------------------------------------------

/**@class Coluna
 * @brief Classe armazena uma string que representa o nome da coluna.
 * @author Analyce Rayssa - 211026548
 *
 * @details
 * Colunas existentes:
 * - Solicitado;
 * - Em Execu&ccedil;&atilde;O;
 * - Concluido;
 *
 * A string, nome da coluna, s&oacute; &eacute; v&aacute;lido caso seja igual a uma dentre as colunas j&aacute; existentes.
 */

class Coluna
{
    private:
        string nome_coluna;
    public:

        /**
        * @brief Define a coluna do cartão.
        *
        * Armazena uma string, representando a coluna do cartão. As coluna existentes são: "SOLICITADO", "EM EXECUÇÃO" e "CONCLUIDO".
        *
        * @param string a ser armazenada, representando uma coluna.
        *
        * @throw invalid_argument caso a string n&atilde;o seja igual a nenhum nome de coluna existente.
        *
        */

        void setColuna(string entrada_coluna);

        /**
        * @brief Retorna a coluna armazenada.
        *
        * @return string representando a coluna do cartão.
        *
        */

        string getColuna();
};

inline string Coluna::getColuna(){
    return nome_coluna;
}

// ---------------------------------------------------------------------------------
// CLASSE SENHA - 211026548
// ---------------------------------------------------------------------------------

/**@class Senha
 * @brief Classe armazena senha.
 * @author Analyce Rayssa - 211026548
 *
 * @details
 * Senha &eacute; armazenado como string e deve seguir as seguintes regras:
 *
 * - Formato: XXXXX, comprimento 5;
 * - X &eacute; um dos seguintes caracteres: letra (A - Z, a - z), d&iacute;gito (0 - 9), sinal de pontua&ccedil;&atilde;o ( . , ; ? !);
 * - Pelo menos um caractere &eacute; letra mai&uacute;scula;
 * - Pelo menos um caractere &eacute; letra min&uacute;cula;
 * - Pelo menos um caractere &eacute; d&iacute;gito;
 * - Pelo menos um caracter &eacute; sinal de pontua&ccedil;&atilde;o;
 * - N&atilde;o h&aacute; caractere duplicado;
 *
 */

class Senha
{
    private:
        string chave;
        const static int comprimento;
        void validar(string);

    public:

        /**
        * @brief Define a senha.
        *
        * Armazena a senha, caso seja válida.
        *
        * @param string, representando a senha.
        *
        * @throw invalid_argument caso a senha seja inv&aacute;lida.
        *
        */

        void setSenha(string _senha);

        /**
        * @brief Retorna a senha armazenada.
        *
        * @return string representando a senha.
        *
        */

        string getSenha();

};

inline string Senha::getSenha(){
    return chave;
}

// ---------------------------------------------------------------------------------
// CLASSE TEXTO - 22005395
// ---------------------------------------------------------------------------------

/**@class Texto
 * @brief Classe armazena um texto de 5 a 30 caracteres.
 * @author Lurian - 22005395
 *
 * @details
 * Texto &eacute; armazenado como string e deve seguir as seguintes regras:
 *
 * - 5 a 30 caracteres;
 * - Cada caractere &eacute; letra (A - Z, a - z), dígito (0-9), sinal de pontuaç&ccedil;&atilde;o ( . , ; ? !) ou espaço em branco;
 * - N&atilde;o h&aacute; espaços em branco em sequencia;
 * - N&atilde;o h&aacute; sinais de pontuaç&ccedil;&atilde;o em sequencia;
 * - N&atilde;o h&aacute; acentuaç&ccedil;&atilde;o;
 * - Primeiro caractere &eacute; letra mai&uacute;scula;
 * - Primeiro caractere após sinal de pontuaç&ccedil;&atilde;o (exceto v&iacute;rgula ou ponto-e-v&iacute;rgula) &eacute; letra mai&uacute;scula;
 *
 *
 */


class Texto
{
private:
    string texto;
    void validar(string);

public:

    /**
    * @brief Define um texto.
    *
    * Armazena uma sequência de caracteres, caso seja válido.
    *
    * @param string, representando um texto.
    *
    * @throw invalid_argument caso o texto seja inv&aacute;lido.
    *
    */

    void setTexto(string);

    /**
    * @brief Retorna a senha armazenada.
    *
    * @return string representando o texto.
    *
    */

    string getTexto() const {return texto;};
};

// ---------------------------------------------------------------------------------
// CLASSE CODIGO - 222025960
// ---------------------------------------------------------------------------------

/**@class Codigo
 * @brief Classe armazena codigo.
 * @author Marcus - 222025960
 *
 * Codigo &eacute; armazenado como string e deve seguir as seguintes regras:
 *
 * - Formato LLDD
 * - L &eacute; letra mai&uacute;scula (A - Z)
 * - D &eacute; d&iacute;gito (0 – 9)
 *
 */

class Codigo{
private:
    string valor;
    void validar(string);

public:

    /**
    * @brief Define um código.
    *
    * Armazena uma string representado o código, caso seja válido.
    *
    * @param string, representando um código.
    *
    * @throw invalid_argument caso o codigo seja inv&aacute;lido.
    *
    */

    void setValor(string);

    /**
    * @brief Retorna o código armazenado.
    *
    * @return string representando o código.
    *
    */

    string getValor() const;

};
inline string Codigo::getValor() const{
    return valor;
}

// ---------------------------------------------------------------------------------
// CLASSE EMAIL - 222025960
// ---------------------------------------------------------------------------------

/**@class Email
 * @brief Classe armazena o endere&ccedil;o de e-mail.
 * @author Marcus - 222025960
 *
 * @details
 * Email &eacute; armazenado como string e deve seguir as seguintes regras:
 *
 * - Formato: nome@dom&iacute;nio;
 * - nome &eacute; composto por 2 a 10 caracteres;
 * - dom&iacute;nio &eacute; composto por 2 a 20 caracteres;
 * - Cada caractere &eacute; letra (A-Z ou a-z), d&iacute;gito (0 – 9) ou ponto (.);
 * - Caractere @ n&atilde;o pode ser imediatamente precedido ou sucedido por ponto (.);
 * - N&atilde;o h&aacute; pontos (.) em sequencia;
 *
 */


class Email{
private:
    string enderecoEmail;
    void validar(string);

public:

    /**
    * @brief Define um email.
    *
    * Armazena uma string representado o email, caso seja válido.
    *
    * @param string, representando um email.
    *
    * @throw invalid_argument caso o email seja inv&aacute;lido.
    *
    */

    void setEnderecoEmail(string);

    /**
    * @brief Retorna o email armazenado.
    *
    * @return string representando o email.
    *
    */

    string getEnderecoEmail() const;

};

inline string Email::getEnderecoEmail() const{
    return enderecoEmail;
}

#endif // DOMINIOS_H_INCLUDED
