#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

#define VERDE "\033[32m"
#define BOLD  "\033[1m"
#define RESET "\033[0m"

int main() {
  system("clear");
    char loading_text[] =
    VERDE"  |   |   -----   -----   -----   ---   -------    ---    |        \n"
    "  |   |   |   |   |       |   |    |       |      |   |   |        \n"
    "  |---|   |   |   ----    |----    |       |      |---|   |        \n"
    "  |   |   |   |       |   |        |       |      |   |   |        \n"
    "  |   |   _____   ____    |        |       |      |   |   |_____   \n" RESET;

    int length = sizeof(loading_text) - 1;
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < length; ++j) {
            printf("%c", loading_text[j]);
            fflush(stdout);
            usleep(30000);
        }

        printf("\033[2J");
        usleep(500000);
    }
    
    sleep(1);
    system("clear");
    printf("Efeito concluído!\n");

    return 0;
}

  /*
int main() {
  system("clear");
    printf("  ║   ║  ╔═══╗  ╔═══    ╔═══╗   ═╦═   ══╦══  ╔═══╗  ║     \n");
    printf("  ║   ║  ║   ║  ║       ║   ║    ║      ║    ║   ║  ║     \n");
    printf("  ╠═══╣  ║   ║  ╚═══╗   ╠═══╝    ║      ║    ╠═══╣  ║     \n");
    printf("  ║   ║  ║   ║      ║   ║        ║      ║    ║   ║  ║     \n");
    printf("  ║   ║  ╚═══╝  ╚═══╝   ║       ═╩═     ║    ║   ║  ╚════ \n");

  
    return 0;
}
  */