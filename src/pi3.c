#include "../include/main.h"


int numFuncionario = 0;
int numEmentas = 0;
int numEscolhas = 0;

char nomesficheiros[3][75] = {
    "../../data/funcionarios.txt",
    "../../data/ementas.txt",
    "../../data/escolhas.txt" };


FILE* fileFuncionario; /**< Variável usada para guardar dados lidos no ficheiro referente a pacientes. */
FILE* fileEmentas; /**< Variável usada para guardar dados lidos no ficheiro referente a dietas. */
FILE* fileEscolhas; /**< Variável usada para guardar dados lidos no ficheiro referente a planos nutricionais. */

Funcionario* funcionario;
Ementa* ementas;
Escolha* escolhas;

int leituraFicheiros(int tab)
{
    char formatoStringFuncionario[50]; /**< Variável usada para guardar a forma de como o programa vai ler a separação de dados de pacientes. */
    char formatoStringEmentas[50];   /**< Variável usada para guardar a forma de como o programa vai ler a separação de dados de dietas. */
    char formatoStringEscolhas[50];  /**< Variável usada para guardar a forma de como o programa vai ler a separação de dados de planos nutricionais.*/

    //Se for para ler com -tab, charSeparador = \t, se não for, separa por ';'
    if (tab == 1) {
        strcpy(formatoStringFuncionario, "%d;%49[^\t];%14s\n");
        strcpy(formatoStringEmentas, "%d; %10[^\t]; %19[^\t]; %49[^\t]; %d cal\n");
        strcpy(formatoStringEscolhas, "%d; %10[^\t]; %19[^\t]; %d Cal, %d Cal\n");
    }
    else
    {
        strcpy(formatoStringFuncionario, "%d; %19[^;];%14s,%14s\n");
        strcpy(formatoStringEmentas, "%d; %10[^;]; %19[^;]; %49[^;]; %d cal\n");
        strcpy(formatoStringEscolhas, "%d; %10[^;]; %19[^;]; %d Cal, %d Cal\n");
    }

    //Tenta abrir os ficheiros, caso não consiga, avisa o utilizador e fecha o programa
    fileFuncionario = fopen(nomesficheiros[0], "r");
    fileEmentas = fopen(nomesficheiros[1], "r");
    fileEscolhas = fopen(nomesficheiros[2], "r");
int i;

    if (fileFuncionario == NULL || fileEmentas == NULL || fileEscolhas == NULL) {
        printf("Nao foi possivel abrir um ou mais ficheiros. (%s / %s / %s)\n", nomesficheiros[0], nomesficheiros[1], nomesficheiros[2]);
        printf("\nClique na tecla ENTER para sair do programa...");
        while (getchar() != '\n');
        getchar();
        return 1;
    }
        scanf("%d",&i);

    //Alocar na memória espaço para as estruturas necessárias de armazenamento de dados
    funcionario = malloc(sizeof(funcionario) * 100);
    ementas = malloc(sizeof(ementas) * 100);
    escolhas = malloc(sizeof(escolhas) * 100);
   scanf("%d",&i);
   
    //Lê o conteúdo dos ficheiros
    while (fscanf(fileFuncionario, formatoStringFuncionario, &funcionario[numFuncionario].numero_funcionario, funcionario[numFuncionario].nome,funcionario[numFuncionario].nif, funcionario[numFuncionario].tlm) == 3) {
        numFuncionario++;
    }

    printf("%d",numFuncionario);
        scanf("%d",&i);

    // while (fscanf(fileEmentas, formatoStringDietas, &dietas[numEmentas].id, dietas[numEmentas].data, dietas[numEmentas].refeicao, dietas[numEmentas].alimento, &dietas[numEmentas].calorias) == 5) {
    //     numEmentas++;
    // }

    // while (fscanf(fileEscolhas, formatoStringPlanos, &planoNutricional[numEscolhas].id, planoNutricional[numEscolhas].data, planoNutricional[numEscolhas].refeicao, &planoNutricional[numEscolhas].calorias_min, &planoNutricional[numEscolhas].calorias_max) == 5) {
    //     numEscolhas++;
    // }

        

    //Após leitura, fecha os ficheiros
    fclose(fileFuncionario);
    fclose(fileEmentas);
    fclose(fileEscolhas);
}




// Funcoes para processar linhas
void processaLinhaFuncionario(char *linha, Funcionario *funcionario) {
    const char delimitador[] = ";";
    funcionario->numero_funcionario = atoi(strtok(linha, delimitador));
    strcpy(funcionario->nome, strtok(NULL, delimitador));
    funcionario->nif = atoi(strtok(NULL, delimitador));
    funcionario->tlm = atoi(strtok(NULL, delimitador));
}

void processaLinhaEmenta(char *linha, Ementa *ementa) {
    const char delimitador[] = ";";
    strcpy(ementa->dia_semana, strtok(linha, delimitador));
    strcpy(ementa->data, strtok(NULL, delimitador));

    strcpy(ementa->peixe.nome_prato, strtok(NULL, delimitador));
    ementa->peixe.calorias = atoi(strtok(NULL, delimitador));

    strcpy(ementa->carne.nome_prato, strtok(NULL, delimitador));
    ementa->carne.calorias = atoi(strtok(NULL, delimitador));

    strcpy(ementa->dieta.nome_prato, strtok(NULL, delimitador));
    ementa->dieta.calorias = atoi(strtok(NULL, delimitador));

    strcpy(ementa->vegetariano.nome_prato, strtok(NULL, delimitador));
    ementa->vegetariano.calorias = atoi(strtok(NULL, delimitador));
}

void processaLinhaEscolha(char *linha, Escolha *escolha) {
    const char delimitador[] = ";";
    strcpy(escolha->dia_semana, strtok(linha, delimitador));
    escolha->numero_funcionario = atoi(strtok(NULL, delimitador));
    escolha->tipo_prato = strtok(NULL, delimitador)[0];
}

// Funcoes para carregar ficheiros
int carregarFuncionarios(const char *caminhofunc, Funcionario funcionarios[], int maxFuncionarios) {
    char linhaFicheiro[500];
    FILE *fp = fopen("data/funcionarios.txt", "r");
    if (fp == NULL) {
        printf("Nao foi possivel abrir o ficheiro: %s\n", caminhofunc);
        return -1;
    }

    int i = 0;
    while (fgets(linhaFicheiro, sizeof(linhaFicheiro), fp) != NULL && i < maxFuncionarios) {
        linhaFicheiro[strcspn(linhaFicheiro, "\n")] = '\0'; // Remove o '\n'
        processaLinhaFuncionario(linhaFicheiro, &funcionarios[i]);
        i++;
    }
    fclose(fp);
    return i;
}

int carregarEmenta(const char *caminhoementa, Ementa ementas[], int maxEmentas) {
    char linhaFicheiro[500];
    FILE *fp = fopen("data/emeta.txt", "r");
    if (fp == NULL) {
        printf("Nao foi possivel abrir o ficheiro: %s\n", caminhoementa);
        return -1;
    }

    int i = 0;
    while (fgets(linhaFicheiro, sizeof(linhaFicheiro), fp) != NULL && i < maxEmentas) {
        linhaFicheiro[strcspn(linhaFicheiro, "\n")] = '\0'; // Remove o '\n'
        processaLinhaEmenta(linhaFicheiro, &ementas[i]);
        i++;
    }
    fclose(fp);
    return i;
}

int carregarEscolhas(const char *caminhoEscolha, Escolha escolhas[], int maxEscolhas) {
    char linhaFicheiro[500];
    FILE *fp = fopen(caminhoEscolha, "r"); // ainda tenho que fazer o ficheiro
    if (fp == NULL) {
        printf("Nao foi possivel abrir o ficheiro: %s\n", caminhoEscolha);
        return -1;
    }

    int i = 0;
    while (fgets(linhaFicheiro, sizeof(linhaFicheiro), fp) != NULL && i < maxEscolhas) {
        linhaFicheiro[strcspn(linhaFicheiro, "\n")] = '\0'; // Remove o '\n'
        processaLinhaEscolha(linhaFicheiro, &escolhas[i]);
        i++;
    }
    fclose(fp);
    return i;
}

// Funcao principal
int main() {

    leituraFicheiros(0);
     menuInicial(1, funcionario, ementas, escolhas);

    // int totalFuncionarios = carregarFuncionarios("data/funcionarios.csv", funcionarios, MAX_FUNCIONARIOS);
    // printf("Funcionarios carregados: %d\n", totalFuncionarios);

    // int totalEmentas = carregarEmenta("data/ementa.csv", ementas, MAX_EMENTAS);
    // printf("Ementas carregadas: %d\n", totalEmentas);

    // int totalEscolhas = carregarEscolhas("data/escolhas.csv", escolhas, MAX_ESCOLHAS);
    // printf("Escolhas carregadas: %d\n", totalEscolhas);

    return 0;
}