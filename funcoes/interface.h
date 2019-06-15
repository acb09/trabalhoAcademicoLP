void exibirMenu() {

    printf("Escolha uma opção abaixo: \n");
    printf("1 - Cadastrar cliente\n");
    printf("2 - Cadastrar conta\n");
    printf("3 - Realizar Saque\n");
    printf("4 - Efetuar depósito\n");
    printf("5 - Extrato no período\n");
    printf("6 - Lista de clientes\n");
    printf("7 - Busca por CPF\n");
    printf("8 - Busca comparada\n");
    printf("0 - Sair\n");
    printf("Opcao escolhida: ");

}

void lerEntradaDoMenu(int *opcaoEscolhida) {
    scanf("%d", opcaoEscolhida);
}

void executaOpcao(int opcaoEscolhida, Banco *banco) {
    switch (opcaoEscolhida)
    {
    case 1:
        cadastrarCliente(banco);
        break;
    case 2:
        cadastrarConta(banco);
        break;
    case 3:
        printf("Realizar saque");
        break;
    case 4:
        printf("Efetuar deposito");
        break;
    case 5:
        printf("Extrato no período");
        break;
    case 6:
        listarClientes(banco);
        break;
    case 7:
        // Code
        break;
    case 8:
        printf("Busca comparada");
        break;
    default:
        printf("\nFinalizando aplicação...");
        exit(0);
        break;
    }
    opcaoEscolhida = -1;
}

void limparTela() {
    system("cls || clear");
}

void aguardaUsuarioPressionarEnter() {
    printf("\n\nPressione qualquer tecla para voltar para o menu.");
    // system("pause");
    getch();
}

void resetarValoresDeBanco(Banco *banco) {
    (*banco).quantidadeClientes = 0;
    (*banco).quantidadeContas = 0;
    (*banco).quantidadeMovimentacoes = 0;
}