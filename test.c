#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* getString() {
  char* string = malloc(60);
  fgets(string, 60, stdin);
  return string;
}


int main() {

  printf("%s", getString());
  system("pause");
  getchar();
  return 0;
}
















// int verificarSeExisteBarras(char *data, int quantidadeBarrasEncontradas);



// int main() {

//   char data[10] = "09/02/1996";
//   int qtdBarras = verificarSeExisteBarras(data, 0);
//   if (qtdBarras) 
//     printf("Barras encontradas!\nQuantidade: %d", qtdBarras);
//   else 
//     printf("Barras não encontradas!");

//   return 0;
// }



// int verificarSeExisteBarras(char *data, int quantidadeBarrasEncontradas) {
//     char *ptr = strchr(data, '/');
//     if (ptr == NULL) return quantidadeBarrasEncontradas;
//     ++quantidadeBarrasEncontradas;
//     printf("%s\n", ptr+1);
//     return verificarSeExisteBarras(ptr+1, quantidadeBarrasEncontradas);
//     // return 0;
// }
