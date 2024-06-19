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

void pesquisarFuncionario(Funcionario funcionarios[], int num_funcionarios) {
    int opcao;
    printf("Pesquisar por (1) C�digo ou (2) Nome: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        int codigo;
        printf("Digite o c�digo do funcion�rio: ");
        scanf("%d", &codigo);
        for (int i = 0; i < num_funcionarios; i++) {
            if (funcionarios[i].codigo == codigo) {
                printf("C�digo: %d\nNome: %s\nTelefone: %s\nCargo: %s\nSal�rio: %.2f\n", funcionarios[i].codigo, funcionarios[i].nome, funcionarios[i].telefone, funcionarios[i].cargo, funcionarios[i].salario);
                return;
            }
        }
    } else if (opcao == 2) {
        char nome[100];
        printf("Digite o nome do funcion�rio: ");
        scanf(" %[^\n]", nome);
        for (int i = 0; i < num_funcionarios; i++) {
            if (strcmp(funcionarios[i].nome, nome) == 0) {
                printf("C�digo: %d\nNome: %s\nTelefone: %s\nCargo: %s\nSal�rio: %.2f\n", funcionarios[i].codigo, funcionarios[i].nome, funcionarios[i].telefone, funcionarios[i].cargo, funcionarios[i].salario);
                return;
            }
        }
    }
    printf("Funcion�rio n�o encontrado.\n");
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
  nova_estadia.codigo = *num_estadias + 1; // Gera��o autom�tica de c�digo

  // Entrada de dados da estadia
  printf("Data de Entrada (dd/mm/aaaa): ");
  scanf(" %[^\n]", nova_estadia.data_entrada);
  printf("Data de Sa�da (dd/mm/aaaa): ");
  scanf(" %[^\n]", nova_estadia.data_saida);
  printf("Quantidade de Di�rias: ");
  scanf("%d", &nova_estadia.quantidade_diarias);
  printf("C�digo do Cliente: ");
  scanf("%d", &nova_estadia.codigo_cliente);
  printf("N�mero do Quarto: ");
  scanf("%d", &nova_estadia.numero_quarto);

  // Verifica se o quarto est� ocupado
  for (int i = 0; i < num_quartos; i++) {
    if (quartos[i].numero == nova_estadia.numero_quarto) {
      if (strcmp(quartos[i].status, "ocupado") == 0) {
        printf("Erro: o quarto est� ocupado.\n");
        return;
      } else {
        strcpy(quartos[i].status, "ocupado");
      }
    }
  }

  // Verifica se o cliente existe
  int cliente_existe = 0;
  for (int i = 0; i < num_clientes; i++) {
    if (clientes[i].codigo == nova_estadia.codigo_cliente) {
      cliente_existe = 1;
      break;
    }
  }

  if (!cliente_existe) {
    printf("Erro: cliente n�o encontrado.\n");
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

void mostrarEstadiasCliente(Estadia estadias[], int num_estadias, Cliente clientes[], int num_clientes) {
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
                printf("Código da Estadia: %d\nData de Entrada: %s\nData de Saída: %s\nQuantidade de Diárias: %d\nNúmero do Quarto: %d\n", estadias[i].codigo, estadias[i].data_entrada, estadias[i].data_saida, estadias[i].quantidade_diarias, estadias[i].numero_quarto);
            }
        }
    } else {
        printf("Cliente não encontrado.\n");
    }
}

int main(void) {
  Quarto quartos[MAX_QUARTOS];
  Cliente clientes[MAX_CLIENTES];
  Funcionario funcionarios[MAX_FUNCIONARIOS];

  int num_clientes = 0, num_funcionarios = 0, num_quartos = 0;
  return 0;
}
