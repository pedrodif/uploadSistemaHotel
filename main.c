#include <stdio.h>

#define MAX_CLIENTES 100
#define MAX_FUNCIONARIOS 50

typedef struct {
  int codigo;
  char nome[100];
  char endereco[200];
  char telefone[20];
} Cliente;

typedef struct {
  int codigo;
  char nome[100];
  char telefone[20];
  char cargo[50];
  float salario;
} Funcionario;

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

void cadastrarFuncionario(Funcionario funcionarios[], int *num_funcionarios) {
  if (*num_funcionarios >= MAX_FUNCIONARIOS) {
    printf("Limite de funcionários atingido.\n");
    return;
  }

  Funcionario novo_funcionario;
  novo_funcionario.codigo = *num_funcionarios + 1;

  printf("Nome: ");
  scanf(" %[^\n]", novo_funcionario.nome);

  printf("Telefone: ");
  scanf(" %[^\n]", novo_funcionario.telefone);

  printf("Cargo: ");
  scanf(" %[^\n]", novo_funcionario.cargo);

  printf("Salario: ");
  scanf("%f", &novo_funcionario.salario);

  for (int i = 0; i < *num_funcionarios; i++) {
    if (funcionarios[i].codigo == novo_funcionario.codigo) {
      printf("Erro: já existe um funcionário com esse código.\n");
      return;
    }
  }

  funcionarios[*num_funcionarios] = novo_funcionario;
  (*num_funcionarios)++;
  printf("Funcionário cadastrado com sucesso.\n");
}

int main(void) {
  Cliente clientes[MAX_CLIENTES];
  Funcionario funcionarios[MAX_FUNCIONARIOS];

  int num_clientes = 0, num_funcionarios = 0;

  return 0;
}
