#define MENOR 1
#define IGUAL 2
#define MAIOR 3
#define DIFERENTE 4






long int  lerId(Banco *banco);
char* lerNome();
char* lerDataNascimento();
char* lerCPF();
char* lerRG();
char* lerTelefone();
char* lerEmail();
void exibirCliente(Cliente cliente);
void listarClientes(Banco *banco);
void incrementarQuantidadeDeClientes(Banco *banco);
void incrementarQuantidadeDeContas(Banco *banco);
void exibirMensagemDigite(char palavra[20]);
int listaCheia(Banco *banco);
int validarNome(char* nome, int *invalido);
void quantidadeCaracteresIncompativel(char* palavra, int quantidadeMinima, int medida, int *invalido);
int validarData(char* data, int *invalido);
void formatoInvalido(char* data, int *invalido);
int verificarSeExisteArroba(char* email);
int verificarSeExistePonto(char* email);
void verificarSeExisteBarras(char *data, int *invalido);
int validarEmail(char*, int *);









void cadastrarCliente(Banco *banco) {
  if(listaCheia(banco)) return;
  Cliente* novoCliente = criarNovoCliente(banco);
  definirIDCliente(novoCliente, lerId(banco)); 
  definirNomeCliente(novoCliente, lerNome()); 
  definirDataNascimentoCliente(novoCliente, lerDataNascimento());
  definirCPFCliente(novoCliente, lerCPF()); 
  definirRGCliente(novoCliente, lerRG()); 
  definirTelefoneCliente(novoCliente, lerTelefone()); 
  definirEmailCliente(novoCliente, lerEmail()); 
  definirQuantidadeClientes(banco, obterQuantidadeClientes(banco) + 1); 
  printf("Usuário cadastrado com sucesso!");
}









long int lerId(Banco *banco) {
  printf("%ld", obterPosicaoNovoCliente(banco));
  return obterPosicaoNovoCliente(banco);
}








char* lerNome() {
  char* nome = malloc(obterTamanhoEmBytesNomeCliente());
  int invalido;
  do {
    invalido=0;
    exibirMensagemDigite("nome");
    setbuf(stdin, NULL);
    fgets(nome, obterTamanhoEmBytesNomeCliente(), stdin);
    setbuf(stdin, NULL);
    validarNome(nome, &invalido);
    if (invalido) printf("\nNome inválido!\n");
  } while (invalido);
  return nome;
}








char* lerDataNascimento() {
  char* dataNascimento = malloc(obterTamanhoEmBytesDataNascimentoCliente());
  int invalido;
  do {
    invalido = 0;
    exibirMensagemDigite("nascimento");
    fgets(dataNascimento, obterTamanhoEmBytesDataNascimentoCliente(), stdin);
    setbuf(stdin, NULL);
    validarData(dataNascimento, &invalido);
    if (invalido) printf("\nData inválida!\n");
  } while (invalido);
  return dataNascimento;
}







char* lerCPF() {
  char* cpf = malloc(obterTamanhoEmBytesCPFCliente());
  int invalido;
  do {
    invalido = 0;
    exibirMensagemDigite("CPF");
    fgets(cpf, obterTamanhoEmBytesCPFCliente(), stdin);
    setbuf(stdin, NULL);
    quantidadeCaracteresIncompativel(cpf, 11, DIFERENTE, &invalido);
    if (invalido) printf("\nCPF inválido!\n");
  } while (invalido);
  return cpf;
}






char* lerRG() {
  char* rg = malloc(obterTamanhoEmBytesRGCliente());
  int invalido;
  do {
    invalido = 0;
    exibirMensagemDigite("RG");
    fgets(rg, obterTamanhoEmBytesRGCliente(), stdin);
    setbuf(stdin, NULL);
    quantidadeCaracteresIncompativel(rg, 5, MENOR, &invalido);
    if (invalido) printf("\nRG inválido!\n");
  } while (invalido);
  return rg;
}





char* lerTelefone() {
  char *telefone = malloc(obterTamanhoEmBytesTelefoneCliente());
  int invalido;
  do {
    invalido = 0;
    exibirMensagemDigite("telefone");
    fgets(telefone, obterTamanhoEmBytesTelefoneCliente(), stdin);
    setbuf(stdin, NULL);
    quantidadeCaracteresIncompativel(telefone, 10, MENOR, &invalido);
    if (invalido) printf("\nTelefone inválido!\n");
  } while (invalido);
  return telefone;
}






char* lerEmail() {
  char* email = malloc(obterTamanhoEmBytesEmailCliente());
  int invalido;
  do {
    invalido = 0;
    exibirMensagemDigite("email");
    setbuf(stdin, NULL);
    fgets(email, obterTamanhoEmBytesEmailCliente(), stdin);
    setbuf(stdin, NULL);
    validarEmail(email, &invalido);
    if (invalido) printf("\nEmail inválido!\n");
  } while (invalido);
  return email;
}





int validarData(char* data, int *invalido) {
  quantidadeCaracteresIncompativel(data, 10, DIFERENTE, invalido);
  formatoInvalido(data, invalido);
  verificarSeExisteBarras(data, invalido);
  return (*invalido);
}





int validarNome(char* nome, int *invalido) {
  quantidadeCaracteresIncompativel(nome, 3, MENOR, invalido);
  return (*invalido);
}






int validarEmail(char* email, int *invalido) {
    quantidadeCaracteresIncompativel(email, 6, MENOR, invalido);
    (*invalido) = verificarSeExisteArroba(email);
    (*invalido) = verificarSeExistePonto(email);
    return (*invalido);
}






void verificarSeExisteBarras(char *data, int *invalido) {
    (*invalido) = !(data[2] == '/' && data[5] == '/');
}





// FALTA IMPLEMENTAR
void formatoInvalido(char *data, int *invalido) {
  if (invalido) return;
  (*invalido) = 0;
  //  Código que valida a data
}






int verificarSeExistePonto(char* email) {
  return !(strchr(email, '.') != NULL);
}






int verificarSeExisteArroba(char* email) {
  return !(strchr(email, '@') != NULL);
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
  printf("ID: %d", cliente.idCliente);
  printf("Nome: %s", cliente.nome);
  printf("Nascimento: %s", cliente.dataNascimento);
  printf("CPF: %s", cliente.CPF);
  printf("RG: %s", cliente.RG);
  printf("Telefone: %s", cliente.telefone);
  printf("Email: %s", cliente.email);
  printf("####################################\n");
}





void exibirMensagemDigite(char palavra[20]) {
  printf("\nDigite o %s: ", palavra);
}






int listaCheia(Banco *banco) {
  int estaCheia = banco->quantidadeClientes == MAXUSUARIOS;
  if (estaCheia) printf("\nLista cheia! Não é possível inserir mais novos usuários.\n");
  return estaCheia;
}






void quantidadeCaracteresIncompativel(char* palavra, int quantidade, int medida, int *invalido) {
  if ((*invalido)) return; // Se sinalizaor for verdadeiro ele não precisa fazer nada alem de aguardar o retorno da função pai como invalido
  if (medida == MENOR) (*invalido) = (strlen(palavra)-1 < quantidade) ? 1 : 0;
  // else if (medida == IGUAL) (*invalido) = (strlen(palavra)-1 == quantidade) ? 1 : 0;
  else if (medida == DIFERENTE) (*invalido) = (strlen(palavra)-1 != quantidade) ? 1 : 0;
  else if (medida == MAIOR) (*invalido) = (strlen(palavra)-1 > quantidade) ? 1 : 0;
}





int buscarClienteIDViaCPF(Banco *banco, char* cpf) {
  int idUsuario = 0;
  int maximoUsuarios = (*banco).quantidadeClientes;
  Cliente* ptrClientes = (*banco).clientes;
  for (; idUsuario<maximoUsuarios; idUsuario++) 
    if (strcmp(cpf, ptrClientes[idUsuario].CPF)) 
      return idUsuario;
  return -1;
}