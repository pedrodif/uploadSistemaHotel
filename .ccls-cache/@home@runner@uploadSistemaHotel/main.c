#include <stdio.h>
#define MAX_CLIENTES 100

typedef struct {
  int codigo;
  char nome[100];
  char endereco[200];
  char telefone[20];
} Cliente;

void cadastrarCliente(Cliente clientes[], int *num_clientes) {
  if (*num_clientes >= MAX_CLIENTES) {
    printf("Limite de clientes atingido.\n");
    return;
  }

  Cliente novo_cliente;
  novo_cliente.codigo = *num_clientes + 1;

  printf("Nome: ");
  scanf(" %[^\n]", novo_cliente.nome);

  printf("Endereço: ");
  scanf(" %[^\n]", novo_cliente.endereco);

  printf("Telefone: ");
  scanf(" %[^\n]", novo_cliente.telefone);

  for (int i = 0; i < *num_clientes; i++) {
    if (clientes[i].codigo == novo_cliente.codigo) {
      printf("Erro: já existe um cliente com esse código.\n");
      return;
    }
  }

  clientes[*num_clientes] = novo_cliente;
  (*num_clientes)++;
  printf("Cliente cadastrado com sucesso.\n");
}

int main(void) {
  Cliente clientes[MAX_CLIENTES];
  int num_clientes = 0;

  return 0;
}
