Hotel Management System
Pontifícia Universidade Católica de Minas Gerais
Instituto de Ciências Exatas e Informática
Curso de Engenharia de Software
Este projeto implementa um sistema de gerenciamento de hotel conforme os requisitos fornecidos.

Estrutura de Dados
Estadia

codigo_estadia
data_entrada
data_saida
quantidade_diarias
codigo_cliente
numero_quarto
Quarto

numero_quarto
quantidade_hospedes
valor_diaria
status
Restrições
Clientes e quartos devem estar cadastrados antes de registrar uma estadia.
Estadia só pode ser cadastrada em quartos desocupados.
Não pode haver mais de uma estadia para um mesmo quarto no mesmo período.
Diárias começam às 14h00 e terminam às 12h00 do dia seguinte.
Funcionalidades
Cadastrar Cliente

Garante unicidade do código do cliente (geração automática opcional).
Cadastrar Funcionário

Garante unicidade do código do funcionário (geração automática opcional).
Cadastrar Quarto

Garante unicidade do número do quarto.
Cadastrar Estadia

Recebe código do cliente, quantidade de hóspedes, data de entrada e saída.
Encontra quarto disponível para a quantidade de hóspedes.
Calcula a quantidade de diárias.
Dar Baixa em Estadia

Calcula e mostra o valor total a ser pago.
Altera status do quarto para desocupado.
Pesquisar Clientes/Funcionários

Pesquisa por nome ou código e exibe informações correspondentes.
Mostrar Estadias de um Cliente

Pesquisa por nome ou código do cliente e exibe todas as estadias.
Calcular Pontos de Fidelidade

Calcula pontos com base nas diárias (10 pontos por diária).
Estrutura de Arquivos
Persistência dos dados em arquivos binários.
Leitura e escrita de dados utilizando bibliotecas adequadas.
Função Main
Exibe um menu interativo com opções para:
Cadastrar cliente
Cadastrar funcionário
Cadastrar quarto
Cadastrar estadia
Pesquisar clientes/funcionários
Dar baixa em estadias
Calcular pontos de fidelidade
Sair
Menu em loop até o usuário selecionar a opção "SAIR".
