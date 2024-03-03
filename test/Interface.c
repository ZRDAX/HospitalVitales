#include <stdio.h>

// Definindo códigos de escape ANSI para cores e formatação
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

int main() {
    // Limpando a tela
    printf("\033c");

    // Exemplo de uma interface simples
    printf(BOLD BLUE "Minha Interface Bonita no Terminal\n" RESET);
    printf("===================================\n");
    printf(GREEN "1. Opção 1\n");
    printf(YELLOW "2. Opção 2\n");
    printf(MAGENTA "3. Opção 3\n");
    printf(RED "4. Sair\n" RESET);
    printf("===================================\n");

    // Exemplo de formatação para entrada do usuário
    printf("Escolha uma opção: " BOLD);

    int escolha;
    scanf("%d", &escolha);

    // Exemplo de manipulação de escolha
    switch (escolha) {
        case 1:
            printf("Você escolheu a Opção 1.\n");
            break;
        case 2:
            printf("Você escolheu a Opção 2.\n");
            break;
        case 3:
            printf("Você escolheu a Opção 3.\n");
            printf(CYAN"\nBryan");
            printf(CYAN"\nPAI");
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}
