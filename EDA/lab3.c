#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
struct aluno{
    int matricula;
    char nome[81];
    char endereco[121];
    char telefone[21];
};

typedef struct elemento Elemento;
struct elemento{
    Aluno* info;
    struct elemento *prox;
};

int main(){

}