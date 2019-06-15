#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "./structs/banco.h"
#include "./funcoes/banco.h"
#include "./funcoes/cliente.h"
#include "./funcoes/conta.h"
#include "./funcoes/interface.h"

int main() {

    int opcaoEscolhida;
    Banco banco;

    resetarValoresDeBanco(&banco);

    while (1) {
      limparTela();
      exibirMenu();
      lerEntradaDoMenu(&opcaoEscolhida);
      executaOpcao(opcaoEscolhida, &banco);
      aguardaUsuarioPressionarEnter();
    }

    return 0;
}