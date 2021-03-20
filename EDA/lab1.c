#include <stdio.h>
#include <stdlib.h>

void imprime(char* s){
    if(s[0] != '\0'){
        printf("%c",s[0]);
        imprime(&s[1]);
    }
}

int comprimento(char* s){
    if(s[0] != '\0'){
        return 1 + comprimento(&s[1]);
    }
}

struct aluno{
    int matricula;
    char nome[81];
    char endereco[121];
    char telefone[21];
};

typedef struct aluno Aluno;

int main(){
    //Aluno* tabela[10];
    Aluno** tabela = (Aluno**)malloc(sizeof(Aluno*)*10);
    //tabela[0] = (Aluno*)malloc(sizeof(Aluno));
    tabela[0]->matricula=1921287;
    printf("A matricula  %d",tabela[0]->matricula);
    
}