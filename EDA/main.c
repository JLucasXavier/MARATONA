#include <stdio.h>
#include "lab2.h"

int main(){
    Aluno* tabela[10];
    inicializa(10, tabela);
    preenche(10,tabela,0,1,"Marcelo","Leblon","38756651");
    preenche(10,tabela,1,2,"Gustavo","Copacabana","22451250");

    printf("O nome Gustavo esta no indice %d\n",busca_linear(10,tabela,"Gustavo"));
}