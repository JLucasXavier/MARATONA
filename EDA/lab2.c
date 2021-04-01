#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;
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
        strcpy(tab[i]->nome,nome);
        strcpy(tab[i]->endereco,endereco);
        strcpy(tab[i]->telefone,telefone);
    }
}

void deletar(int n, Aluno** tab, int i){
    if(i<0 || i>=n){
        printf("Indice fora do limite\n");
        exit(1);
    }
    if(tab[i]!=NULL){
        free(tab[i]);
        tab[i]=NULL;
    }
}

void atualiza(int n, Aluno** tab, int i,int matricula, char nome[],char endereco[],char telefone[]){
    if(i<0 || i>=n){
        printf("Indice fora do limite\n");
        exit(1);
    }
    if(tab[i]!=NULL){
        tab[i]->matricula = matricula;
        strcpy(tab[i]->nome,nome);
        strcpy(tab[i]->endereco,endereco);
        strcpy(tab[i]->telefone,telefone);
    }
}



int main(){
    Aluno* tabela[10];
}