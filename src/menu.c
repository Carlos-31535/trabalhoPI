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

void menuInicial(int opcValida, Paciente* pacientes, Dieta* dietas, PlanoNutricional* planoNutricional)
{
    //Se a opção não é valida, pede para introduzir novamente
    if (opcValida == 0)
    {
        printf("Opcao invalida, introduza novamente.\n");
    }
    else
    {
        printf("Ola, Bem vindo. Escolha uma opcao:\n");
    }
    printf("\n------------MENU-----------------------");
    printf("1 - Carregar dados do ficheiro.\n");
    printf("2 - Apresentar as refeicoes no dia indica:\n");
    printf("3 - Listar o plano nutricional de um paciente para determinada refeicao.\n");
    printf("4 - Calculo das medias da calorias consumidas por refeicao por cada paciente.\n");
    printf("5 - Gerar a tabela das refeicoes planeadas e realizadas para todos os pacientes.\n");
    printf("6 - Ajuda.\n");
    printf("7 - Sair do programa.\n\n");

    printf("Opcao: ");
    scanf("%d", &opcaomenu);    