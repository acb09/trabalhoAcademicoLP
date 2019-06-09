#include <stdio.h>
#include <stdlib.h>
#include "./structs/banco.h"
#include "./funcoes/interface.h"

int main() {

    int opcaoEscolhida;
    Banco banco;

    inicializarBanco(&banco);

    while(1) {
      limparTela();
      exibirMenu();
      lerEntradaDoMenu(&opcaoEscolhida);
      executaOpcao(opcaoEscolhida, &banco);
      aguardaUsuarioPressionarEnter();
    }

    return 0;
}