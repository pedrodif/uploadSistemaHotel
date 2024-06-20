#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_FUNCIONARIOS 50
#define MAX_QUARTOS 100
#define MAX_ESTADIAS 200

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

typedef struct {
  int numero;
  int quantidade_hospedes;
  float valor_diaria;
  char status[10];
} Quarto;

typedef struct {
  int codigo;
  char data_entrada[11];
  char data_saida[11];
  int quantidade_diarias;
  int codigo_cliente;
  int numero_quarto;
} Estadia;

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

void cadastrarQuarto(Quarto quartos[], int *num_quartos) {
  if (*num_quartos >= MAX_QUARTOS) {
    printf("Limite de quartos atingido.\n");
    return;
  }

  Quarto novo_quarto;

  printf("Número do quarto: ");
  scanf("%d", &novo_quarto.numero);

  printf("Quantidade de hóspedes: ");
  scanf("%d", &novo_quarto.quantidade_hospedes);

  printf("Valor da diária: ");
  scanf("%f", &novo_quarto.valor_diaria);

  strcpy(novo_quarto.status, "desocupado");

  for (int i = 0; i < *num_quartos; i++) {
    if (quartos[i].numero == novo_quarto.numero) {
      printf("Erro: já existe um quarto com esse número.\n");
      return;
    }
  }

  quartos[*num_quartos] = novo_quarto;
  (*num_quartos)++;
  printf("Quarto cadastrado com sucesso.\n");
}

void cadastrarEstadia(Estadia estadias[], int *num_estadias, Quarto quartos[],
                      int num_quartos, Cliente clientes[], int num_clientes) {
  if (*num_estadias >= MAX_ESTADIAS) {
    printf("Limite de estadias atingido.\n");
    return;
  }

  Estadia nova_estadia;
  nova_estadia.codigo = *num_estadias + 1;

  printf("Data de Entrada (dd/mm/aaaa): ");
  scanf(" %[^\n]", nova_estadia.data_entrada);

  printf("Data de Saída (dd/mm/aaaa): ");
  scanf(" %[^\n]", nova_estadia.data_saida);

  printf("Quantidade de Diárias: ");
  scanf("%d", &nova_estadia.quantidade_diarias);

  printf("Código do Cliente: ");
  scanf("%d", &nova_estadia.codigo_cliente);

  printf("Número do Quarto: ");
  scanf("%d", &nova_estadia.numero_quarto);

  for (int i = 0; i < num_quartos; i++) {
    if (quartos[i].numero == nova_estadia.numero_quarto) {
      if (strcmp(quartos[i].status, "ocupado") == 0) {
        printf("Erro: o quarto está ocupado.\n");
        return;
      } else {
        strcpy(quartos[i].status, "ocupado");
      }
    }
  }

  int cliente_existe = 0;
  for (int i = 0; i < num_clientes; i++) {
    if (clientes[i].codigo == nova_estadia.codigo_cliente) {
      cliente_existe = 1;
      break;
    }
  }

  if (nova_estadia.quantidade_diarias <= 0) {
    printf("Erro: quantidade de diárias inválida.\n");
    return;
  }

  if (!cliente_existe) {
    printf("Erro: cliente não encontrado.\n");
    return;
  }

  estadias[*num_estadias] = nova_estadia;
  (*num_estadias)++;
  printf("Estadia cadastrada com sucesso.\n");
}

void pesquisarCliente(Cliente clientes[], int num_clientes) {
  int opcao;

  printf("Pesquisar por (1)Código ou (2)Nome: ");
  scanf("%d", &opcao);

  if (opcao == 1) {
    int codigo;
    printf("Digite o código do cliente: ");
    scanf("%d", &codigo);

    for (int i = 0; i < num_clientes; i++) {
      if (clientes[i].codigo == codigo) {
        printf("Código: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n",
               clientes[i].codigo, clientes[i].nome, clientes[i].endereco,
               clientes[i].telefone);
        return;
      }
    }
  } else if (opcao == 2) {
    char nome[100];
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < num_clientes; i++) {
      if (strcmp(clientes[i].nome, nome) == 0) {
        printf("Código: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n",
               clientes[i].codigo, clientes[i].nome, clientes[i].endereco,
               clientes[i].telefone);
        return;
      }
    }
  }
  printf("Cliente não encontrado.\n");
}

void pesquisarFuncionario(Funcionario funcionarios[], int num_funcionarios) {
  int opcao;
  printf("Pesquisar por (1) Código ou (2) Nome: ");
  scanf("%d", &opcao);

  if (opcao == 1) {
    int codigo;
    printf("Digite o código do funcionário: ");
    scanf("%d", &codigo);
    for (int i = 0; i < num_funcionarios; i++) {
      if (funcionarios[i].codigo == codigo) {
        printf("Código: %d\nNome: %s\nTelefone: %s\nCargo: %s\nSal�rio: %.2f\n",
               funcionarios[i].codigo, funcionarios[i].nome,
               funcionarios[i].telefone, funcionarios[i].cargo,
               funcionarios[i].salario);
        return;
      }
    }
  } else if (opcao == 2) {
    char nome[100];
    printf("Digite o nome do funcionário: ");
    scanf(" %[^\n]", nome);
    for (int i = 0; i < num_funcionarios; i++) {
      if (strcmp(funcionarios[i].nome, nome) == 0) {
        printf("Código: %d\nNome: %s\nTelefone: %s\nCargo: %s\nSalário: %.2f\n",
               funcionarios[i].codigo, funcionarios[i].nome,
               funcionarios[i].telefone, funcionarios[i].cargo,
               funcionarios[i].salario);
        return;
      }
    }
  }
  printf("Funcionário não encontrado.\n");
}

void mostrarEstadiasCliente(Estadia estadias[], int num_estadias,
                            Cliente clientes[], int num_clientes) {
  int opcao;
  printf("Pesquisar por (1) Código ou (2) Nome do cliente: ");
  scanf("%d", &opcao);

  int codigo_cliente = -1;
  if (opcao == 1) {
    printf("Digite o código do cliente: ");
    scanf("%d", &codigo_cliente);
  } else if (opcao == 2) {
    char nome[100];
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nome);
    for (int i = 0; i < num_clientes; i++) {
      if (strcmp(clientes[i].nome, nome) == 0) {
        codigo_cliente = clientes[i].codigo;
        break;
      }
    }
  }

  if (codigo_cliente != -1) {
    printf("Estadias do cliente:\n");
    for (int i = 0; i < num_estadias; i++) {
      if (estadias[i].codigo_cliente == codigo_cliente) {
        printf("Código da Estadia: %d\nData de Entrada: %s\nData de Saída: "
               "%s\nQuantidade de Diárias: %d\nNúmero do Quarto: %d\n",
               estadias[i].codigo, estadias[i].data_entrada,
               estadias[i].data_saida, estadias[i].quantidade_diarias,
               estadias[i].numero_quarto);
      }
    }
  } else {
    printf("Cliente não encontrado.\n");
  }
}

void darBaixaEstadia(Estadia estadias[], int *num_estadias, Quarto quartos[],
                     int num_quartos, Cliente clientes[], int num_clientes) {

  int codigo_estadia;
  printf("Digite o código da estadia: ");
  scanf("%d", &codigo_estadia);

  for (int i = 0; i < *num_estadias; i++) {
    if (estadias[i].codigo == codigo_estadia) {
      int numero_quarto = estadias[i].numero_quarto;
      int codigo_cliente = estadias[i].codigo_cliente;

      for (int j = 0; j < num_quartos; j++) {
        if (quartos[j].numero == numero_quarto) {
          strcpy(quartos[j].status, "desocupado");

          float valor_total =
              estadias[i].quantidade_diarias * quartos[j].valor_diaria;
          printf("Valor total a ser pago: %.2f\n", valor_total);

          for (int k = i; k < *num_estadias - 1; k++) {
            estadias[k] = estadias[k + 1];
          }

          (*num_estadias)--;
          return;
        }
      }
    }
  }
  printf("Estadia não encontrada.\n");
}

void calcularPontosFidelidade(Estadia estadias[], int num_estadias,
                              Cliente clientes[], int num_clientes) {
  int opcao;
  printf("Pesquisar por (1) Código ou (2) Nome do cliente: ");
  scanf("%d", &opcao);

  int codigo_cliente = -1;
  if (opcao == 1) {
    printf("Digite o código do cliente: ");
    scanf("%d", &codigo_cliente);
  } else if (opcao == 2) {
    char nome[100];
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nome);
    for (int i = 0; i < num_clientes; i++) {
      if (strcmp(clientes[i].nome, nome) == 0) {
        codigo_cliente = clientes[i].codigo;
        break;
      }
    }
  }

  if (codigo_cliente != -1) {
    int pontos = 0;
    for (int i = 0; i < num_estadias; i++) {
      if (estadias[i].codigo_cliente == codigo_cliente) {
        pontos += estadias[i].quantidade_diarias * 10;
      }
    }
    printf("Pontos de fidelidade do cliente: %d\n", pontos);
  } else {
    printf("Cliente não encontrado.\n");
  }
}

void salvarQuartos(Quarto quartos[], int num_quartos) {
  FILE *arquivo = fopen("quartos.dat", "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de quartos.\n");
    return;
  }
  fwrite(&num_quartos, sizeof(int), 1, arquivo);
  fwrite(quartos, sizeof(Quarto), num_quartos, arquivo);
  fclose(arquivo);
}

void carregarQuartos(Quarto quartos[], int *num_quartos) {
  FILE *arquivo = fopen("quartos.dat", "rb");
  if (arquivo == NULL) {
    printf("Arquivo de quartos não encontrado.\n");
    return;
  }
  fread(num_quartos, sizeof(int), 1, arquivo);
  fread(quartos, sizeof(Quarto), *num_quartos, arquivo);
  fclose(arquivo);
}

void salvarEstadias(Estadia estadias[], int num_estadias) {
    FILE *arquivo = fopen("estadias.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de estadias.\n");
        return;
    }
    fwrite(&num_estadias, sizeof(int), 1, arquivo);
    fwrite(estadias, sizeof(Estadia), num_estadias, arquivo);
    fclose(arquivo);
}

void carregarEstadias(Estadia estadias[], int *num_estadias) {
    FILE *arquivo = fopen("estadias.dat", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de estadias não encontrado.\n");
        return;
    }
    fread(num_estadias, sizeof(int), 1, arquivo);
    fread(estadias, sizeof(Estadia), *num_estadias, arquivo);
    fclose(arquivo);
}

int main(void) {
  Quarto quartos[MAX_QUARTOS];
  Cliente clientes[MAX_CLIENTES];
  Funcionario funcionarios[MAX_FUNCIONARIOS];

  int num_clientes = 0, num_funcionarios = 0, num_quartos = 0;
  return 0;
}