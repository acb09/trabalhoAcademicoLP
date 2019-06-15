#include "./cliente.h"
#include "./conta.h"
#include "./movimentacao.h"

#define MAXUSUARIOS 10
#define MAXCONTAS MAXUSUARIOS
#define MAXMOVIMENTACAO 10

typedef struct Bancos {

    long int quantidadeClientes;
    long int quantidadeContas;
    long int quantidadeMovimentacoes;
    
    Cliente clientes[MAXUSUARIOS];
    Conta contas[MAXCONTAS];
    Movimentacao movimentacoes[MAXCONTAS][MAXMOVIMENTACAO];

} Banco;