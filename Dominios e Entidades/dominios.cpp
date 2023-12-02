#include "dominios.h"
#include "cctype"
#include "exception"
#include<cstring>
#include <algorithm>
#include<iostream>

using namespace std;

//-------------codigo-222025960--------------------
void Codigo::validar(string codigo){

    int tamanho=strlen(codigo.c_str());

    if (tamanho < 5){
        for (int n=0;n<4;n++){

            if (n<2){
                if (!(65<=codigo[n] &&90>=codigo[n])){
                    throw invalid_argument("o codigo inserido eh invalido ");
                    break;
                }
            }
            else{
                if (!(codigo[n]>=48 && codigo[n]<=57)){
                                        throw invalid_argument("o codigo inserido eh invalido ");
                    break;
                    }
            }
        }
    }
    else{
        throw invalid_argument("o codigo inserido eh invalido,o número máximo de caracteres é 4");
    }
}

void Codigo::setValor(string valor){
    Codigo::validar(valor);
    this->valor = valor;
}

//limite- 222005395

void Limite::setLimite(int numero)
{
    // checa se o limite e um dos valores validos
    switch(numero){
        case 5:
            this->limite = numero;
            break;
        case 10:
            this->limite = numero;
            break;
        case 15:
            this->limite = numero;
            break;
        case 20:
            this->limite = numero;
            break;
        default:
            throw invalid_argument("Limite invalido");
            break;
    }
}

//-----------------------------------------------------

//coluna - 211026548
void Coluna::setColuna(string entrada_coluna)
{
    std::transform(entrada_coluna.begin(), entrada_coluna.end(),
                 entrada_coluna.begin(), ::toupper);

    if (entrada_coluna == "SOLICITADO"){
        this -> nome_coluna = entrada_coluna;

    } else if (entrada_coluna == "EM EXECUÇÃO"){
        this -> nome_coluna = entrada_coluna;

    } else if (entrada_coluna == "CONCLUIDO"){
        this -> nome_coluna = entrada_coluna;
    }else{
        throw invalid_argument("Nome de Coluna inexistente!");
    }
}

//-----------------------------------------------------


//---------------email-222025960----------------

void Email::validar(string EnderecoEmail) {
    int contador;
    string nome;
    string dominio;
    int tamanhoEnderecoEmail = strlen(EnderecoEmail.c_str());

    for (int i = 0; i < tamanhoEnderecoEmail; i++) {
        if (EnderecoEmail[i] == 46 && EnderecoEmail[i + 1] == 46) {
            throw invalid_argument("Pontos em sequência não são permitidos");
        }
    }

    while (EnderecoEmail[contador] != 64) {
        nome = nome + EnderecoEmail[contador];
        contador += 1;
    }
    int tamanhoNome = strlen(nome.c_str());
    contador += 1;

    while (contador < tamanhoEnderecoEmail) {
        dominio = dominio + EnderecoEmail[contador];
        contador += 1;
    }
    int tamanhoDominio = strlen(dominio.c_str());

    // Verificando nome
    if (tamanhoNome > 2 && tamanhoNome < 10) {
        for (int j = 0; j < tamanhoNome; j++) {
            if (!((nome[j] >= 65 && nome[j] <= 90) || (nome[j] >= 97 && nome[j] <= 122) || (nome[j] >= 48 && nome[j] <= 57) || (nome[j] == 46))) {
                throw invalid_argument("nome de email invalido");
                break;
            }
        }
    }

    // Verificando dominio
    if (dominio[0] == 46) {
        throw invalid_argument("dominio de email invalido");
    } else {
        if (tamanhoDominio > 2 && tamanhoDominio < 20) {
            for (int k = 0; k < tamanhoDominio; k++) {
                if (!((dominio[k] >= 65 && dominio[k] <= 90) || (dominio[k] >= 97 && dominio[k] <= 122) || (dominio[k] >= 48 && dominio[k] <= 57) || (dominio[k] == 46))) {
                    throw invalid_argument("dominio de email invalido");
                    break;
                }
            }
        }
    }
}

void Email::setEnderecoEmail(string entrada_texto)
{
    validar(entrada_texto);
    this->enderecoEmail = entrada_texto;
}

//----------------------------------------------------------


//senha - 211026548

const int Senha::comprimento = 5;

void Senha::validar(string caracteres){

    bool tam = comprimento == (int)caracteres.size();
    bool digitos = false;
    bool letra_Maiuscula = false;
    bool letra_Minuscula = false;
    bool simbolos = (caracteres.find_first_of(".,;?!") != std::string::npos);
    bool repetidos = false;

    if (!tam) {
        throw invalid_argument("Tamanho invalido! Senha deve conter 5 caracteres.");
    }

    for (int i= 0; i < comprimento; i++){
        char caractere = caracteres[i];

        //verificar se possui um digito
        if (isdigit(caractere)){
            digitos = true;
        }

        //verificar se é uma letra minuscula
        if (islower(caractere)){
            letra_Minuscula = true;
        }

        //veriicar se é uma letra maiuscula
        if (isupper(caractere)) {
            letra_Maiuscula = true;
        }

        // verificar se possui caractere duplicados
        for (int x= i+1; x < comprimento; x++){
            if (caractere == caracteres[x]){
                repetidos = true;
            }
        }

    }

    //Exceções
    if (!digitos) {
        throw invalid_argument("Senha invalida! Não possui um número.");
    }

    if (!letra_Maiuscula) {
        throw invalid_argument("Senha invalida! Não possui uma letra em Maiuscula.");
    }

    if (!letra_Minuscula) {
        throw invalid_argument("Senha invalida! Não possui uma letra em Minuscula.");
    }

    if (!simbolos) {
        throw invalid_argument("Senha invalida! Não possui um simbolo valido.");
    }

    if (repetidos) {
        throw invalid_argument("Senha invalida! Possui Caractere repetido.");
    }

}

void Senha::setSenha(string _senha){
    validar(_senha);
    this -> chave = _senha;
}

//-----------------------------------------------------


//texto- 222005395
void Texto::validar(string texto)
{

    //checa o tamanho
    if(texto.size() < 5 or texto.size() > 30){
        throw invalid_argument("Tamanho limite do texto não respeitado: 5 a 30 caracteres");
    }

    //checa se o texto comeca com letra maiuscula
    if(!isupper(texto[0])){
        throw invalid_argument("Primeiro caracter deve ser maiusculo");
    }

    //checa o restante
    for(int i = 0; i < (int) texto.size(); i++){

        //verifica se o i-esimo caracter é sinal de pontuacao ou espaco
        if(texto[i] == ',' || texto[i] == '.' || texto[i] == '?' || texto[i] == '!' || texto[i] == ' '){

            if(i < (int)texto.size()-1){

                //verifica se ha espaço ou pontuacao duplicada
                if(texto[i] == texto[i+1]){
                    throw invalid_argument("Não é permitido sinal de pontuação ou espaço duplicado");
                }

                //verifica se o caracter apos pontuacao é maiusculo
                else if((texto[i] == '!' || texto[i] == '?' || texto[i] == '.') && !isupper(texto[i+1])){
                    throw invalid_argument("Início de frase com letra minúscula");
                }
            }
        }

        //verifica se o caracter eh letra ou numero
        else if(!isalnum(texto[i])){
            throw invalid_argument("Texto inválido");
        }
    }
}

void Texto::setTexto(string entrada_texto)
{
    validar(entrada_texto);
    this->texto = entrada_texto;
}

//-----------------------------------------------------
