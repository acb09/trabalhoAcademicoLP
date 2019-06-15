Cliente* definirIDCliente(Cliente*, long int );
void definirNomeCliente(Cliente*, char*);
Cliente* definirDataNascimentoCliente(Cliente*, char*);
Cliente* definirCPFCliente(Cliente*, char*);
Cliente* definirRGCliente(Cliente*, char*);
Cliente* definirTelefoneCliente(Cliente*, char *);
Cliente* definirEmailCliente(Cliente*, char*);
Cliente* obterClientes(Banco*);
long int obterPosicaoNovoCliente(Banco*);
Conta* definirIDConta(Conta *, long int);
Conta* definirIDClienteConta(Conta*,  long int);
Conta* definirSaldo(Conta *, float);
Conta* definirDataAbertura(Conta *, char*);
Conta* obterContas(Banco *);
long int obterQuantidadeClientes(Banco*);
long int obterQuantidadeContas(Banco*);
long int definirQuantidadeClientes(Banco*, long int);
long int definirQuantidadeContas(Banco*, long int);
int obterTamanhoEmBytesIDCliente();
int obterTamanhoEmBytesNomeCliente();
int obterTamanhoEmBytesDataNascimentoCliente();
int obterTamanhoEmBytesCPFCliente();
int obterTamanhoEmBytesRGCliente();
int obterTamanhoEmBytesTelefoneCliente();
int obterTamanhoEmBytesEmailCliente();
int obterTamanhoEmBytesIDConta();
int obterTamanhoEmBytesIDClienteConta();
int obterTamanhoEmBytesSaldo();
int obterTamanhoEmBytesDataAbertura();
Cliente* criarNovoCliente(Banco *);


void testedetexto(Cliente *cliente, char *nome);


Cliente* criarNovoCliente(Banco* banco) {
  return &banco->clientes[obterPosicaoNovoCliente(banco)];
}

Cliente* definirIDCliente(Cliente* cliente, long int id) {
  // cliente->idCliente = id;
  (*cliente).idCliente = id;
  return cliente;
}

void definirNomeCliente(Cliente* cliente, char *nome) {
  printf("%s", nome);
  strcpy(cliente->nome, nome);
  // return cliente;
}

Cliente* definirDataNascimentoCliente(Cliente* cliente, char *dataNascimento) {
  strcpy(cliente->dataNascimento, dataNascimento);
  return cliente;
}

Cliente* definirCPFCliente(Cliente* cliente, char *cpf) {
  strcpy(cliente->CPF, cpf);
  return cliente;
}

Cliente* definirRGCliente(Cliente* cliente, char *rg) {
  strcpy(cliente->RG, rg);
  return cliente;
}

Cliente* definirTelefoneCliente(Cliente* cliente, char *telefone) {
  strcpy(cliente->telefone, telefone);
  return cliente;
}

Cliente* definirEmailCliente(Cliente* cliente, char *email) {
  strcpy(cliente->email, email);
  return cliente;
}

Cliente* obterClientes(Banco *banco) {
  return banco->clientes;
}

long int obterPosicaoNovoCliente(Banco *banco) {
  return banco->quantidadeClientes;
}






Conta* definirIDConta(Conta *conta, long int id) {
  conta->idConta = id;
  return conta;
}

Conta* definirIDClienteConta(Conta *conta, long int id) {
  conta->idCliente = id;
  return conta;
}

Conta* definirSaldo(Conta *conta, float saldo) {
  conta->saldo = saldo;
  return conta;
}

Conta* definirDataAbertura(Conta *conta, char* dataAbertura) {
  strcpy(conta->dataAbertura, dataAbertura);
  return conta;
}

Conta* obterContas(Banco *banco) {
  return banco->contas;
}






long int obterQuantidadeClientes(Banco* banco) {
  return banco->quantidadeClientes;
}

long int obterQuantidadeContas(Banco* banco) {
  return banco->quantidadeContas;
}

long int definirQuantidadeClientes(Banco* banco, long int novaQuantidade) {
  banco->quantidadeClientes = novaQuantidade;
  return novaQuantidade;
}

long int definirQuantidadeContas(Banco* banco, long int novaQuantidade) {
  banco->quantidadeContas = novaQuantidade;
  return novaQuantidade;
}








int obterTamanhoEmBytesIDCliente() {
  Cliente cliente;
  return sizeof(cliente.idCliente);
}

int obterTamanhoEmBytesNomeCliente() {
  Cliente cliente;
  return sizeof(cliente.nome);
}

int obterTamanhoEmBytesDataNascimentoCliente() {
  Cliente cliente;
  return sizeof(cliente.dataNascimento);
}

int obterTamanhoEmBytesCPFCliente() {
  Cliente cliente;
  return sizeof(cliente.CPF);
}

int obterTamanhoEmBytesRGCliente() {
  Cliente cliente;
  return sizeof(cliente.RG);
}

int obterTamanhoEmBytesTelefoneCliente() {
  Cliente cliente;
  return sizeof(cliente.telefone);
}

int obterTamanhoEmBytesEmailCliente() {
  Cliente cliente;
  return sizeof(cliente.email);
}









int obterTamanhoEmBytesIDConta() {
  Conta conta;
  return sizeof(conta.idConta);
}

int obterTamanhoEmBytesIDClienteConta() {
  Conta conta;
  return sizeof(conta.idCliente);
}

int obterTamanhoEmBytesSaldo() {
  Conta conta;
  return sizeof(conta.saldo);
}

int obterTamanhoEmBytesDataAbertura() {
  Conta conta;
  return sizeof(conta.dataAbertura);
}