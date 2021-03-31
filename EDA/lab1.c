#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void inicializa(int n, Aluno** tab){
    int i;
    for(i=0;i<n;i++){
        tab[i]=NULL;
    }
}

void preenche(int n, Aluno** tab, int i,int matricula, char nome[],char endereco[],char telefone[]){
    if(i<0 || i>=n){
        printf("Indice fora do limite\n");
        exit(1);
    }
    if(tab[i]==NULL){
        tab[i] = (Aluno*)malloc(sizeof(Aluno));
        tab[i]->matricula = matricula;
        strcpy()
    }
}

typedef struct aluno Aluno;
//teste
int main(){
    Aluno* tabela[10];
    //Aluno** tabela = (Aluno**)malloc(sizeof(Aluno*)*10);
    printf("A matricula  %d",tabela[0]->matricula);
    
}