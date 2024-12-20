#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FUNCIONARIOS 200
#define MAX_EMENTAS 7
#define MAX_ESCOLHAS 200

// Estruturas
typedef struct {
    int numero_funcionario;
    char nome[100];
    int nif;
    int tlm;
} Funcionario;

typedef struct {
    char nome_prato[100];
    int calorias;
} Prato;

typedef struct {
    char dia_semana[10];
    char data[11];
    Prato peixe;
    Prato carne;
    Prato dieta;
    Prato vegetariano;
} Ementa;

typedef struct {
    char dia_semana[10];
    int numero_funcionario;
    char tipo_prato; // 'C', 'P', 'D', 'V'
} Escolha;


// /**
//  * @file main.h
//  * @authors Tiago Vale (27675) | Pedro Duarte (27990) | Miguel Areal (29559)
//  * @brief Ficheiro Header que permite a interligação, definição e protótipos de estruturas, funções, e variáveis globais.
//  *
//  *
//  */

// #ifndef MAIN_H
// #define MAIN_H

// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>

//  /**
//   * Estrutura de dados que armazena os dados de cada Paciente
//   * Proveniente por defeito de: pacientes.txt
//  */
// typedef struct Paciente {
//     int id; /**< Número identificador de paciente.*/
//     char nome[50]; /**< Nome de paciente.*/
//     char tlm[15]; /**< Número de contacto de paciente.*/
//     int violouPlano; /**< Se o paciente violou o seu respetivo plano nutricional.*/
// } Paciente;

// /**
//  * Estrutura de dados que armazena os dados de todas as dietas
//  * Proveniente por defeito de: dietas.txt
// */
// typedef struct Dieta {
//     int id; /**< Número identificador do paciente ao qual a dieta se aplica.*/
//     char data[11]; /**< Data do registo no formato aaaa-mm-dd.*/
//     char refeicao[20]; /**< Identificador do tipo de refeição ("pequeno almoço","almoço","jantar").*/
//     char alimento[50]; /**< Nome do alimento consumido na refeição.*/
//     int calorias; /**< Identificador do número de calorias consumidas na refeição.*/
// } Dieta;

// /**
//  * Estrutura de dados que armazena os dados de todos os planos nutricionais.
//  * Proveniente por defeito de: planonutricional.txt
// */
// typedef struct PlanoNutricional {
//     int id; /**< Número identificador do paciente ao qual o plano nutricional se aplica.*/
//     char data[11]; /**< Data do registo no formato aaaa-mm-dd.*/
//     char refeicao[20]; /**< Identificador do tipo de refeição ("pequeno almoço","almoço","jantar").*/
//     int calorias_min; /**< Identificador do número mínimo calorias permitido.*/
//     int calorias_max; /**< Identificador do número máximo calorias permitido.*/
// } PlanoNutricional;


// //Variaveis Globais
// extern int numPacientes;/**<Número de pacientes registados.*/
// extern int numDietas;/**<Número de dietas registadas.*/
// extern int numPlanos;/**<Número de planos nutricionais registados.*/


// //Prototipos das Funções

// /**
//   * @brief A função corresponde à primeira primeira opção do menu.
//   * Imprime os pacientes que ultrapassaram o limite de calorias indicados no
//   * plano nutricional.
//   *
//   * @param pacientes Matriz de estruturas Paciente que representa
//   *     a informação dos pacientes.
//   * @param dietas Matriz de estruturas Dieta que contém a informação
//   *     sobre as dietas dos pacientes.
//   * @param planoNutricional Matriz de estruturas PlanoNutricional que
//   *     contém a informação sobre os planos nutricionais.
//   */
// void verificarLimitesCalorias(Paciente* pacientes, Dieta* dietas, PlanoNutricional* planoNutricional);


// /**
//  * @brief A funcao corresponde à segunda opção do menu inicial.
//  *  Imprime informações sobre os pacientes que realizaram
//  *  refeições fora do intervalo de calorias escritos nos planos
//  *  nutricionais.
//  *
//  * @param pacientes Matriz de estruturas Paciente que
//  *  representa a informação dos pacientes.
//  * @param dietas Matriz de estruturas Dieta que contém a
//  *  informação sobre as dietas dos pacientes.
//  * @param planoNutricional Matriz de estruturas PlanoNutricional
//  *  que contém a informação sobre os planos nutricionais.
//  */
// void listarPacientesForaIntervalo(Paciente* pacientes, Dieta* dietas, PlanoNutricional* planoNutricional);

// /**
//  * @brief A função corresponde à terceira opção do menu inicial.
//  *  Pede informações ao utilizador, como o ID do paciente, tipo
//  *  de refeição, e datas de inicio e fim. Em seguida, lista o
//  *  plano nutricional do paciente para a refeição específica
//  *  durante o período especificado.
//  *
//  * @param pacientes Matriz de estruturas Paciente que representa
//  *  a informação dos pacientes.
//  * @param planoNutricional Matriz de estruturas PlanoNutricional
//  *  que contém a informação sobre os planos nutricionais.
//  */
// void listarPlanoNutricional(Paciente* pacientes, PlanoNutricional* planoNutricional);


// /**
//  * @brief A função corresponde à quarta opção do menu inicial.
//  *  Solicita informações do paciente ao utilizador, como as datas
//  *  de inicio e fim do período de procura. Por fim calcula as médias
//  *  de calorias consumidas por refeição para cada paciente no
//  *  período especificado, exibindo as informações na consola.
//  *
//  * @param pacientes Matriz de estruturas Paciente que representa
//  *  a informação dos pacientes.
//  * @param dietas Matriz de estruturas Dieta que contém a informação
//  *  sobre as dietas dos pacientes.
//  */
// void calcularMediasCalorias(Paciente* pacientes, Dieta* dietas);

// /**
//  * @brief A função corresponde à quinta opção do menu inicial.
//  * Gera uma tabela das refeições planeadas e realizadas para todos os pacientes, de acordo com um intervalo de tempo fornecido pelo utilizador.
//  * @param pacientes Matriz de estruturas Paciente que representa
//  *  a informação dos pacientes.
//  * @param dietas Matriz de estruturas Dieta que contém a informação
//  * sobre as dietas dos pacientes.
//  * @param planoNutricional Matriz de estruturas PlanoNutricional
//  *  que contém a informação sobre os planos nutricionais.
// */
// void gerarTabelaRefeicoes(Paciente* pacientes, Dieta* dietas, PlanoNutricional* planos);


// /**
//  * @brief Menu inicial do programa.
//  *
//  * Função recursiva que contém um menu iterativo com as funcionalidades para apresentar ao utilizador.
//  *
//  * @param opcValida Flag indicando se a opção do menu é válida.
//  * @param pacientes Matriz de estruturas Paciente contendo informações sobre os pacientes.
//  * @param dietas Matriz de estruturas Dieta contendo informações sobre as dietas dos pacientes.
//  * @param planoNutricional Matriz de estruturas PlanoNutricional contendo informações sobre os planos nutricionais dos pacientes.
//  */
// void menuInicial(int opcValida, Paciente* pacientes, Dieta* dietas, PlanoNutricional* planoNutricional);

// /**
//  * Lista uma página de ajuda, acessível também diretamente pelo argumento "-ajuda".
// */
// void ajuda();

// /**
//  * @brief Executa a leitura de argumentos dados inicialmente, pelo utilizador.
//  *
//  * Função que lê e valida os argumentos que o utilizador possa utilizar.
//  *
//  *
//  * @param argc Número de argumentos, provenientes da função Main.
//  * @param argv Matriz que contém os argumentos, provenientes da função Main.
//  */
// void leituraArgumentos(int argc, char *argv[]);


// /**
//  * Limpa o ecrã da consola / terminal, independentemente do sistema operativo a ser utilizado.
// */
// void clearScreen();

// #endif /* MAIN_H */


