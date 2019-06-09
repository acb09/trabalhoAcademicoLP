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
void mensagemPadrao(char palavra[20]);
int listaCheia(Banco *banco);




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
  int posicaoNoVetor = (*banco).quantidadeClientes;
  (*banco).clientes[posicaoNoVetor].idCliente = posicaoNoVetor;
}





void lerNome(Banco *banco) {
  int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeNome = sizeof((*banco).clientes[posicaoNoVetor].nome);
  (*banco).clientes[posicaoNoVetor].nome;
  mensagemPadrao("nome");
  setbuf(stdin, NULL);
  fgets( (*banco).clientes[posicaoNoVetor].nome, tamanhoEmBytesDeNome, stdin);
  setbuf(stdin, NULL);
}





void lerDataNascimento(Banco *banco) {
  int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeDataNascimento = sizeof((*banco).clientes[posicaoNoVetor].dataNascimento);
  mensagemPadrao("nascimento");
  fgets((*banco).clientes[posicaoNoVetor].dataNascimento, tamanhoEmBytesDeDataNascimento, stdin);
  setbuf(stdin, NULL);
  
}





void lerCPF(Banco *banco) {
  int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeCPF = sizeof((*banco).clientes[posicaoNoVetor].CPF);
  mensagemPadrao("CPF");
  fgets((*banco).clientes[posicaoNoVetor].CPF, tamanhoEmBytesDeCPF, stdin);
  setbuf(stdin, NULL);
  
}





void lerRG(Banco *banco) {
  int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeRG = sizeof((*banco).clientes[posicaoNoVetor].RG);
  mensagemPadrao("RG");
  fgets((*banco).clientes[posicaoNoVetor].RG, tamanhoEmBytesDeRG, stdin);
  setbuf(stdin, NULL);
  
}





void lerTelefone(Banco *banco) {
  int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeTelefone = sizeof((*banco).clientes[posicaoNoVetor].telefone);
  mensagemPadrao("telefone");
  fgets((*banco).clientes[posicaoNoVetor].telefone, tamanhoEmBytesDeTelefone, stdin);
  setbuf(stdin, NULL);
  
}






void lerEmail(Banco *banco) {
  int posicaoNoVetor = (*banco).quantidadeClientes;
  int tamanhoEmBytesDeEmail = sizeof((*banco).clientes[posicaoNoVetor].email);
  mensagemPadrao("email");
  fgets((*banco).clientes[posicaoNoVetor].email, tamanhoEmBytesDeEmail, stdin);
  setbuf(stdin, NULL);
  
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





void mensagemPadrao(char palavra[20]) {
  printf("\nDigite seu %s: ", palavra);
}






int listaCheia(Banco *banco) {
  return (*banco).quantidadeClientes == MAXUSUARIOS;
}