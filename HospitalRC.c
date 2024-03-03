#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define VERDE "\033[32m"
#define AMARELO "\033[33m"
#define VERMELHO "\033[31m"
#define AZUL "\033[34m"
#define CIANO "\033[36m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

typedef struct {
  char data[11];
  char descricao[100];
} Consulta;

typedef struct {
  char nome[50];
  char dataNascimento[11];
  Consulta atendimento[50];
  int contConsulta;
  bool ativo;
} Paciente;

void incluirPaciente(Paciente *pacientes, int *numPacientes);
void alterarPaciente(Paciente *pacientes, int numPacientes);
void realizarConsulta(Paciente *pacientes, int numPacientes);
void listarPacientes(Paciente *pacientes, int numPacientes);
void mostrarPaciente(Paciente *pacientes, int numPacientes);
void apagarPaciente(Paciente *pacientes, int *numPacientes);
void restaurarPaciente(Paciente *pacientes, int *numPacientes);
void salvarDados(Paciente *pacientes, int numPacientes);
void carregarDados(Paciente *pacientes, int *numPacientes);
void logoTipo();

int main() {

  Paciente pacientes[100];
  int numPacientes = 0;
  char opcao;

  logoTipo();
  carregarDados(pacientes, &numPacientes);

  do {

    printf("                             ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("                             ┃             MENU            ┃\n");
    printf("                             ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━━━━━"
           "━━━━━━━━━━━━━━━━┓\n");
    printf(" ┃      Adicionar Paciente     │    Modificar Paciente   │    "
           "Realizar Consulta    ┃\n");
    printf(" ┃                             │                         │         "
           "                ┃\n");
    printf(" ┃              1              │            2            │         "
           "   3            ┃\n");
    printf(" ┃─────────────────────────────┼─────────────────────────┼─────────"
           "────────────────┃\n");
    printf(" ┃       Listar Pacientes      │     Mostrar Paciente    │     "
           "Apagar Paciente     ┃\n");
    printf(" ┃                             │                         │         "
           "                ┃\n");
    printf(" ┃              4              │            5            │         "
           "   6            ┃\n");
    printf(" ┃─────────────────────────────┼─────────────────────────╆━━━━━━━━━"
           "━━━━━━━━━━━━━━━━┛\n");
    printf(" ┃      Restaurar Paciente     │           Sair          ┃\n");
    printf(" ┃                             │                         ┃\n");
    printf(" ┃              7              │            8            ┃\n");
    printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf(" ┃  Escolha a opcao: ");
    scanf(" %c", &opcao);
    printf("\n");

    switch (opcao) {
    case '1':
      system("clear");
      incluirPaciente(pacientes, &numPacientes);
      break;
    case '2':
      system("clear");
      alterarPaciente(pacientes, numPacientes);
      break;
    case '3':
      system("clear");
      realizarConsulta(pacientes, numPacientes);
      break;
    case '4':
      listarPacientes(pacientes, numPacientes);
      break;
    case '5':
      mostrarPaciente(pacientes, numPacientes);
      break;
    case '6':
      system("clear");
      apagarPaciente(pacientes, &numPacientes);
      break;
    case '7':
      system("clear");
      restaurarPaciente(pacientes, &numPacientes);
      break;
    case '8':
      salvarDados(pacientes, numPacientes);
      system("clear");
      printf(BOLD AZUL "Saindo do programa.\n" RESET);
      break;
    default:
      printf("Opcao invalida. Tente novamente.\n");
    }
  } while (opcao != '8');

  return 0;
}

void incluirPaciente(Paciente *pacientes, int *numPacientes) {
  if (*numPacientes < 100) {
    Paciente p;
    printf("Nome: ");
    scanf(" %[^\n]", p.nome);
    printf("Data de Nascimento (DD/MM/YYYY): ");
    scanf(" %s", p.dataNascimento);

    for (int i = 0; i < 50; i++) {
      Consulta c = {"00/00/0000", "descricao"};
      p.atendimento[i] = c;
    }

    p.contConsulta = 0;
    p.ativo = true;

    pacientes[*numPacientes] = p;
    (*numPacientes)++;
    printf(AMARELO "Paciente adicionado com sucesso.\n\n" RESET);
    sleep(1);
    system("clear");

    printf(VERDE "Paciente adicionado com sucesso.\n\n" RESET);
    sleep(1);
    system("clear");

  } else {
    system("clear");
    printf(VERMELHO "Limite de pacientes atingido.\n" RESET);
  }
}

void alterarPaciente(Paciente *pacientes, int numPacientes) {
  char nome[50];
  printf("Digite o nome do paciente para alterar: ");
  scanf(" %[^\n]", nome);

  int indice = -1;

  for (int i = 0; i < numPacientes; i++) {
    if (strcmp(pacientes[i].nome, nome) == 0) {
      indice = i;
      break;
    }
  }

  if (indice != -1) {
    printf("Digite a nova data de nascimento (formato DD/MM/YYYY): ");
    scanf(" %s", pacientes[indice].dataNascimento);
    printf(AMARELO "Paciente alterado com sucesso.\n\n" RESET);
    sleep(1);
    system("clear");

    printf(VERDE "Paciente alterado com sucesso.\n\n" RESET);
    sleep(1);
    system("clear");

  } else {
    system("clear");
    printf(VERMELHO "Paciente nao encontrado.\n" RESET);
  }
}

void realizarConsulta(Paciente *pacientes, int numPacientes) {
  char nome[50];
  printf("Digite o nome do paciente para realizar a consulta: ");
  scanf(" %[^\n]", nome);

  int indice = -1;

  for (int i = 0; i < numPacientes; i++) {
    if (strcmp(pacientes[i].nome, nome) == 0) {
      indice = i;
      break;
    }
  }

  if (indice != -1) {
    if (pacientes[indice].contConsulta < 50) {
      printf("Digite a data da consulta (formato DD/MM/YYYY): ");
      scanf(" %s",
            pacientes[indice].atendimento[pacientes[indice].contConsulta].data);
      printf("Digite a descricao da consulta: ");
      scanf(" %[^\n]", pacientes[indice]
                           .atendimento[pacientes[indice].contConsulta]
                           .descricao);

      pacientes[indice].contConsulta++;
      printf(AMARELO "Consulta realizada com sucesso.\n\n" RESET);
      sleep(1);
      system("clear");

      printf(VERDE "Consulta realizada com sucesso.\n\n" RESET);
      sleep(1);
      system("clear");
    } else {
      system("clear");
      printf(VERMELHO
             "Limite de consultas atingido para este paciente.\n" RESET);
    }
  } else {
    printf("Paciente(s) nao encontrado.\n");
  }
}

void listarPacientes(Paciente *pacientes, int numPacientes) {
  system("clear");
  printf("Lista de Pacientes:\n");
  for (int i = 0; i < numPacientes; i++) {
    if (pacientes[i].ativo) {
      printf(CIANO "%s - %s\n" RESET, pacientes[i].nome,
             pacientes[i].dataNascimento);
    }
  }
  printf("\nPrecione (c) para continuar: ");
  char wt;
  while (wt != 'c') {
    char y;
    wt = y;
    scanf("%c", &y);
  }

  printf("\n");
  system("clear");
}

void mostrarPaciente(Paciente *pacientes, int numPacientes) {
  system("clear");

  char nome[50];
  printf("Digite o nome do paciente para mostrar os dados: ");
  scanf(" %[^\n]", nome);

  int indice = -1;

  for (int i = 0; i < numPacientes; i++) {
    if (strcmp(pacientes[i].nome, nome) == 0) {
      indice = i;
      break;
    }
  }

  if (indice != -1 && pacientes[indice].ativo) {
    printf("Nome: " CIANO "%s" RESET "\n", pacientes[indice].nome);
    printf("Data de Nascimento: %s\n", pacientes[indice].dataNascimento);
    printf("Historico de Consultas:\n");

    for (int i = 0; i < pacientes[indice].contConsulta; i++) {
      if (i % 5 == 0 && i != 0) {
        char wt;
        printf("\nPressione (s) para continuar: ");
        scanf(" %c", &wt);
        system("clear");

        if (wt != 's') {
          break;
        }
      }

      printf("\nConsulta %d:\n", i + 1);
      printf("Data: %s\n", pacientes[indice].atendimento[i].data);
      printf("Descricao: %s\n", pacientes[indice].atendimento[i].descricao);
    }
  } else {
    system("clear");
    printf(VERMELHO "Paciente nao encontrado.\n" RESET);
  }

  char wt;
  printf("\nPressione (c) para continuar: ");
  while (wt != 'c') {
    scanf(" %c", &wt);
  }
  printf("\n");
  system("clear");
}

void apagarPaciente(Paciente *pacientes, int *numPacientes) {
  char nome[50];
  printf("Digite o nome do paciente para apagar: ");
  scanf(" %[^\n]", nome);

  int indice = -1;

  for (int i = 0; i < *numPacientes; i++) {
    if (strcmp(pacientes[i].nome, nome) == 0) {
      indice = i;
      break;
    }
  }

  if (indice != -1) {
    pacientes[indice].ativo = false;
    printf(AMARELO "*Paciente apagado com sucesso*.\n\n" RESET);
    sleep(1);
    system("clear");

    printf(VERDE "*Paciente apagado com sucesso*.\n\n" RESET);
    sleep(1);
    system("clear");
  } else {
    system("clear");
    printf(VERMELHO "Paciente nao encontrado.\n\n" RESET);
  }
}

void restaurarPaciente(Paciente *pacientes, int *numPacientes) {
  char nome[50];
  printf("Digite o nome do paciente para restaurar: ");
  scanf(" %[^\n]", nome);

  int indice = -1;

  for (int i = 0; i < *numPacientes; i++) {
    if (strcmp(pacientes[i].nome, nome) == 0) {
      indice = i;
      break;
    }
  }

  if (indice != -1) {
    pacientes[indice].ativo = true;
    printf(AMARELO "Paciente restaurado com sucesso.\n\n" RESET);
    sleep(1);
    system("clear");

    printf(VERDE "Paciente restaurado com sucesso.\n\n" RESET);
    sleep(1);
    system("clear");
  } else {
    system("clear");
    printf(VERMELHO "Paciente nao encontrado.\n\n" RESET);
  }
}

void salvarDados(Paciente *pacientes, int numPacientes) {
  FILE *arquivo;
  arquivo = fopen("hospital.db", "wb");

  if (arquivo != NULL) {
    fwrite(pacientes, sizeof(Paciente), numPacientes, arquivo);
    fclose(arquivo);

    system("clear");
    system("clear");
    printf(AMARELO "Dados salvos com sucesso.\n\n" RESET);
    sleep(1);
    system("clear");
    setbuf(stdin, NULL);
    printf(VERDE "Dados salvos com sucesso.\n\n" RESET);
    sleep(1);
    system("clear");

  } else {
    system("clear");
    printf(VERMELHO "Erro ao abrir o arquivo para salvar os dados.\n\n" RESET);
  }
}

void carregarDados(Paciente *pacientes, int *numPacientes) {
  FILE *arquivo;
  arquivo = fopen("hospital.db", "rb");

  if (arquivo != NULL) {
    *numPacientes = fread(pacientes, sizeof(Paciente), 100, arquivo);
    fclose(arquivo);
    printf(AMARELO "Dados carregados com sucesso.\n\n" RESET);
    sleep(1);
    system("clear");
    printf(VERDE "Dados carregados com sucesso.\n\n" RESET);
    sleep(1);
    system("clear");
  } else {
    system("clear");
    printf(VERMELHO "Arquivo de dados nao encontrado.\n" VERDE
                    "Iniciando com banco de dados vazio.\n\n" RESET);
    sleep(2);
    system("clear");
  }
}

void logoTipo() {

  system("clear");
  char loading_text[] = VERDE
      "  |   |   -----   -----   -----   ---   -------    ---    |        \n"
      "  |   |   |   |   |       |   |    |       |      |   |   |        \n"
      "  |---|   |   |   ----    |----    |       |      |---|   |        \n"
      "  |   |   |   |       |   |        |       |      |   |   |        \n"
      "  |   |   _____   ____    |       ___      |      |   |   |_____   "
      "\n" RESET;

  int length = sizeof(loading_text) - 1;
  for (int i = 0; i < 1; ++i) {
    for (int j = 0; j < length; ++j) {
      printf("%c", loading_text[j]);
      fflush(stdout);
      usleep(20000);
    }

    printf("\033[2J");
    usleep(400000);
  }
  sleep(1);
  system("clear");
  printf("Pronto!\n");
  sleep(1);
  system("clear");
}