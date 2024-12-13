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