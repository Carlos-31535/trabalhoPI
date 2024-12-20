#include "../include/main.h"

void clearScreen() {
#if defined(_WIN32) || defined(_WIN64) // Sistema Operativo - Windows
    system("cls");
#elif defined(__unix__) || defined(__APPLE__) // Sistemas baseado em Unix (Linux e macOS)
    system("clear");
#else
    // Para outros sistemas não suportados, imprime linhas vazias de forma a simular a limpeza de ecrã
    for (int i = 0; i < 100; ++i) {
        printf("\n");
    }
#endif
}

int opcaomenu;/**Variável utilizada para guardar a escolha do utilizador, em número, na função menuInicial.*/

void menuInicial(Funcionario* Funcionario, Ementa* Ementa, Escolha* Escolha)
{
    int carregarFicheiros();

    do
    {
        printf("\n------------MENU-----------------------");
        printf("1 - Carregar dados do ficheiro.\n");
        printf("2 - Listar as refeicoes requeridas pelos utentes para um dado dia.\n");
        printf("3 - Listar os utentes por ordem decrescente do numero de funcionario, com total de refeicoes e despesa.\n");
        printf("4 - Listar as refeicoes e calorias de um utente ao longo de um periodo especifico.\n");
        printf("5 - Calcular as medias de calorias consumidas por refeicao em todo o espaço, por dia da semana.\n");
        printf("6 - Gerar a tabela da ementa semanal usufruida por um utente.\n");
        printf("7 - Ajuda (detalhes de utilizacao do programa).\n");
        printf("8 - Sair do programa.\n\n");

    printf("Opcao: ");
    scanf("%d", &opcaomenu);
        switch (expression)
        {
        case 1:
            /* code */
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6
            break;

        default:
            break;
        }
    
    } while (opcaomenu != 7);

    
        printf("Opcao invalida, introduza novamente.\n");
        printf("Ola, Bem vindo. Escolha uma opcao:\n");
    }