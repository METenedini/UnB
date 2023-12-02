#include "comandos.h"


//-----------------------------------------------------------------------------------
// Implementações de métodos de comandos
// Codigo:222025960

void ComandoIAProjetoCriar_Cartao::executar(ISProjeto* cntrISProjeto){

    bool resultado;
    Cartao cartao;

    // Código de interação com o usuário.

    while(true){
        try{
            string valor;
            string valor_quadro;
            string name;
            string description;
            string column;
            Codigo codigo;
            Codigo codigo_quadro;
            Texto nome;
            Texto desc;
            Coluna coluna;

            cout << "Digite o codigo: ";
            cin >> valor;
            cout << "Digite o codigo do quadro: ";
            cin >> valor_quadro;
            cout << "Digite o nome:";
            cin >> name;
            cout << "Digite a decricao:";
            cin >> description;
            cout << "Digite a coluna:";
            cin >> column;

            codigo.setValor(valor);
            codigo_quadro.setValor(valor_quadro);
            nome.setTexto(name);
            desc.setTexto(description);
            coluna.setColuna(column);

            cartao.setCodigo(codigo);
            cartao.setCodigoQuadro(codigo_quadro);
            cartao.setNomeCartao(nome);
            cartao.setDescricaoCartao(desc);
            cartao.setColuna(coluna);

            break;

        }
        catch(invalid_argument &exp){
            cout << "Cartao com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.

    resultado = cntrISProjeto->criar_cartao(cartao);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
}

void ComandoIAProjetoVizualizar_Cartao::executar(ISProjeto* cntrISProjeto){

    Cartao cartao;
    Cartao cartao_provisorio;
    // Código de interação com o usuário.

    while(true){
        try{
            string valor;
            Codigo codigo;
            cout << "Digite o codigo: ";
            cin >> valor;
            codigo.setValor(valor);
            cartao_provisorio.setCodigo(codigo);
            break;

        }
        catch(invalid_argument &exp){
            cout << "Codigo com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.
    cartao=cntrISProjeto->vizualizar_cartao(cartao_provisorio);
    cout << "Codigo: " << cartao.getCodigo().getValor() << endl;
    cout << "Codigo_Quadro: " << cartao.getCodigoQuadro().getValor() << endl;
    cout << "Nome: " << cartao.getNomeCartao().getTexto() << endl;
    cout << "Descricao: " << cartao.getDescricaoCartao().getTexto() << endl;
    cout << "Coluna: " << cartao.getColuna().getColuna() << endl;

}

void ComandoIAProjetoMover_Cartao::executar(ISProjeto* cntrISProjeto){

    bool resultado;
    Cartao cartao;
    Cartao cartao_provisorio;
    // Código de interação com o usuário.

    while(true){
        try{
            string valor;
            string column;
            Codigo codigo;
            Coluna coluna;
            cout << "Digite o codigo: ";
            cin >> valor;
            codigo.setValor(valor);
            cout << "Digite a nova coluna";
            cin >> column;
            coluna.setColuna(column);

            cartao_provisorio.setCodigo(codigo);


            break;

        }
        catch(invalid_argument &exp){
            cout << "Codigo com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.
    cartao=cntrISProjeto->mover_cartao(cartao_provisorio);
    cartao_provisorio.setCodigoQuadro(cartao.getCodigoQuadro());
    cartao_provisorio.setColuna(cartao.getColuna());
    cartao_provisorio.setNomeCartao(cartao.getNomeCartao());
    cartao_provisorio.setDescricaoCartao(cartao.getDescricaoCartao());

    resultado=cntrISProjeto->atualizar_cartao(cartao_provisorio);
    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }

}

void ComandoIAProjetoEliminar_Cartao::executar(ISProjeto* cntrISProjeto){

    bool resultado;
    Codigo codigo;

    // Código de interação com o usuário.

    while(true){
        try{
            string valor;

            cout << "Digite o codigo: ";
            cin >> valor;

            codigo.setValor(valor);


            break;

        }
        catch(invalid_argument &exp){
            cout << "Cartao com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.

    resultado = cntrISProjeto->eliminar_cartao(codigo);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
}


// Método por meio do qual é solicitada a execução do comando.



void ComandoIAProjetoCriar_Quadro::executar(ISProjeto* cntrISProjeto){

    bool resultado;
    Quadro quadro;

    // Código de interação com o usuário.

    while(true){
        try{
            string valor;
            string email;
            string name;
            string description;
            int lim;
            Codigo codigo;
            Email email_conta;
            Texto nome;
            Texto desc;
            Limite limite;

            cout << "Digite o codigo: ";
            cin >> valor;
            cout << "Digite o email da conta: ";
            cin >> email;
            cout << "Digite o nome:";
            cin >> name;
            cout << "Digite a decricao:";
            cin >> description;
            cout << "Digite o limite de cartoes:";
            cin >> lim;

            codigo.setValor(valor);
            email_conta.setEnderecoEmail(email);
            nome.setTexto(name);
            desc.setTexto(description);
            limite.setLimite(lim);

            quadro.setCodigo(codigo);
            quadro.setEmailConta(email_conta);
            quadro.setNomeQuadro(nome);
            quadro.setDescricaoQuadro(desc);
            quadro.setLimite(limite);


            break;
        }
        catch(invalid_argument &exp){
            cout << "Quadro com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.

    resultado = cntrISProjeto->criar_quadro(quadro);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
}

void ComandoIAProjetoVizualizar_Quadro::executar(ISProjeto* cntrISProjeto){


    Quadro quadro;
    Quadro quadro_provisorio;

    // Código de interação com o usuário.

    while(true){
        try{
            string valor;
            Codigo codigo;


            cout << "Digite o codigo: ";
            cin >> valor;

            codigo.setValor(valor);
            quadro_provisorio.setCodigo(codigo);

            break;
        }
        catch(invalid_argument &exp){
            cout << "Quadro com formato incorreto" << endl;
        }
    }

    // Solicitar serviço.

    quadro = cntrISProjeto->vizualizar_quadro(quadro_provisorio);
    cout <<"Codigo:"<<quadro.getCodigo().getValor();
    cout <<"Email_conta:"<<quadro.getEmailConta().getEnderecoEmail();
    cout <<"Nome:"<<quadro.getNomeQuadro().getTexto();
    cout <<"Descricao:"<<quadro.getDescricaoQuadro().getTexto();
    cout <<"Limite:"<<quadro.getLimite().getLimite();



    // Criticar resultado e apresentar mensagem correspondente.


}

void ComandoIAProjetoEliminar_Quadro::executar(ISProjeto* cntrISProjeto){
    
    bool resultado;
    Codigo codigo;

    // Código de interação com o usuário.

    while(true){
        try{
            string valor;

            cout << "Digite o codigo: ";
            cin >> valor;

            codigo.setValor(valor);


            break;

        }
        catch(invalid_argument &exp){
            cout << "Cartao com formato incorreto" << endl;
        }
    }
    resultado = cntrISProjeto->eliminar_quadro(codigo);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }


}
