#define MENOR 1
#define IGUAL 2
#define MAIOR 3
#define DIFERENTE 4




void lerId(Banco *banco);
void lerNome(Banco *banco);
void lerDataNascimento(Banco *banco);
void lerCPF(Banco *banco);
void lerRG(Banco *banco);
void lerTelefone(Banco *banco);
void lerEmail(Banco *banco);
void exibirCliente(Cliente cliente);
void listarClientes(Banco *banco);
void incrementarQuantidadeDeClientes(Banco *banco);
void incrementarQuantidadeDeContas(Banco *banco);
void exibirMensagemDigite(char palavra[20]);
int listaCheia(Banco *banco);
int nomeInvalido(char* nome, int *sinalizador);
void quantidadeCaracteresIncompativel(char* palavra, int quantidadeMinima, int medida, int *sinalizador);
int dataInvalida(char* data, int *sinalizador);
void formatoInvalido(char* data, int *sinalizador);






void cadastrarCliente(Banco *banco) {
  if(listaCheia(banco)) return;
  lerId(banco);
  lerNome(banco);
  lerDataNascimento(banco);
  lerCPF(banco);
  lerRG(banco);
  lerTelefone(banco);
  lerEmail(banco);
  incrementarQuantidadeDeClientes(banco);
  printf("Usuário cadastrado com sucesso!");
}







void lerId(Banco *banco) {
  long int posicaoNoVetor = (*banco).quantidadeClientes;
  (*banco).clientes[posicaoNoVetor].idCliente = posicaoNoVetor;
}







void lerNome(Banco *banco) {
  long int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeNome = sizeof((*banco).clientes[posicaoNoVetor].nome);
  int invalido;
  do {
    invalido=0;
    exibirMensagemDigite("nome");
    setbuf(stdin, NULL);
    fgets((*banco).clientes[posicaoNoVetor].nome, tamanhoEmBytesDeNome, stdin);
    setbuf(stdin, NULL);
    nomeInvalido((*banco).clientes[posicaoNoVetor].nome, &invalido);
    if (invalido) printf("\nNome inválido!\n");
  } while (invalido);
}







int nomeInvalido(char* nome, int *sinalizador) {
  quantidadeCaracteresIncompativel(nome, 3, MENOR, sinalizador);
  return (*sinalizador);
}







void lerDataNascimento(Banco *banco) {
  long int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeDataNascimento = sizeof((*banco).clientes[posicaoNoVetor].dataNascimento);
  int invalido;
  do {
    invalido = 0;
    exibirMensagemDigite("nascimento");
    fgets((*banco).clientes[posicaoNoVetor].dataNascimento, tamanhoEmBytesDeDataNascimento, stdin);
    setbuf(stdin, NULL);
    dataInvalida((*banco).clientes[posicaoNoVetor].dataNascimento, &invalido);
    if (invalido) printf("\nData inválida!\n");
  } while (invalido);
}






int dataInvalida(char* data, int *sinalizador) {
  quantidadeCaracteresIncompativel(data, 10, DIFERENTE, sinalizador);
  formatoInvalido(data, sinalizador);
  return (*sinalizador);
}





// FALTA IMPLEMENTAR
void formatoInvalido(char *data, int *sinalizador) {
  if (sinalizador) return;
  (*sinalizador) = 0;
  //  Código que valida a data
}





void lerCPF(Banco *banco) {
  long int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeCPF = sizeof((*banco).clientes[posicaoNoVetor].CPF);
  int invalido;
  do {
    invalido = 0;
    exibirMensagemDigite("CPF");
    fgets((*banco).clientes[posicaoNoVetor].CPF, tamanhoEmBytesDeCPF, stdin);
    setbuf(stdin, NULL);
    quantidadeCaracteresIncompativel((*banco).clientes[posicaoNoVetor].CPF, 11, DIFERENTE, &invalido);
    if (invalido) printf("\nCPF inválido!\n");
  } while (invalido);
}






void lerRG(Banco *banco) {
  long int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeRG = sizeof((*banco).clientes[posicaoNoVetor].RG);
  int invalido;
  do {
    invalido = 0;
    exibirMensagemDigite("RG");
    fgets((*banco).clientes[posicaoNoVetor].RG, tamanhoEmBytesDeRG, stdin);
    setbuf(stdin, NULL);
    quantidadeCaracteresIncompativel((*banco).clientes[posicaoNoVetor].RG, 5, MENOR, &invalido);
    if (invalido) printf("\nRG inválido!\n");
  } while (invalido);
}





void lerTelefone(Banco *banco) {
  long int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeTelefone = sizeof((*banco).clientes[posicaoNoVetor].telefone);
  int invalido;
  do {
    invalido = 0;
    exibirMensagemDigite("telefone");
    fgets((*banco).clientes[posicaoNoVetor].telefone, tamanhoEmBytesDeTelefone, stdin);
    setbuf(stdin, NULL);
    quantidadeCaracteresIncompativel((*banco).clientes[posicaoNoVetor].telefone, 10, MENOR, &invalido);
    if (invalido) printf("\nTelefone inválido!\n");
  } while (invalido);
}






void lerEmail(Banco *banco) {
  long int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeEmail = sizeof((*banco).clientes[posicaoNoVetor].email);
  int invalido;
  do {
    invalido = 0;
    exibirMensagemDigite("email");
    fgets((*banco).clientes[posicaoNoVetor].email, tamanhoEmBytesDeEmail, stdin);
    setbuf(stdin, NULL);
    quantidadeCaracteresIncompativel((*banco).clientes[posicaoNoVetor].email, 6, MENOR, &invalido);
    if (invalido) printf("\nEmail inválido!\n");
  } while (invalido);
}





void incrementarQuantidadeDeClientes(Banco *banco) {
  (*banco).quantidadeClientes++;
}






void incrementarQuantidadeDeContas(Banco *banco) {
  (*banco).quantidadeContas++;  
}






void listarClientes(Banco *banco) {
  int contador = 0;
  int numeroUsuarios = (*banco).quantidadeClientes;
  for(;contador<numeroUsuarios; contador++) {
    exibirCliente((*banco).clientes[contador]);
  }

}





void exibirCliente(Cliente cliente) {
  printf("\n############## Cliente ##############\n");
  printf("Nome: %s", cliente.nome);
  printf("Nascimento: %s", cliente.dataNascimento);
  printf("CPF: %s\n", cliente.CPF);
  printf("RG: %s", cliente.RG);
  printf("Telefone: %s", cliente.telefone);
  printf("Email: %s", cliente.email);
  printf("####################################\n");
}





void exibirMensagemDigite(char palavra[20]) {
  printf("\nDigite o %s: ", palavra);
}






int listaCheia(Banco *banco) {
  int estaCheia = (*banco).quantidadeClientes == MAXUSUARIOS;
  if (estaCheia) printf("\nLista cheia! Não é possível inserir mais novos usuários.\n");
  return estaCheia;
}






void quantidadeCaracteresIncompativel(char* palavra, int quantidade, int medida, int *sinalizador) {
  printf("%s = %d", palavra, strlen(palavra)-1);
  if ((*sinalizador)) return; // Se sinalizaor for verdadeiro ele não precisa fazer nada alem de aguardar o retorno da função pai como invalido
  if (medida == MENOR) (*sinalizador) = (strlen(palavra)-1 < quantidade) ? 1 : 0;
  // else if (medida == IGUAL) (*sinalizador) = (strlen(palavra)-1 == quantidade) ? 1 : 0;
  else if (medida == DIFERENTE) (*sinalizador) = (strlen(palavra)-1 != quantidade) ? 1 : 0;
  else if (medida == MAIOR) (*sinalizador) = (strlen(palavra)-1 > quantidade) ? 1 : 0;
}