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

int main(){
    Aluno* tabela[10];
    //Aluno** tabela = (Aluno**)malloc(sizeof(Aluno*)*10);
    inicializa(10, tabela);
    preenche(10,tabela,0,1,"Marcelo","Leblon","38756651");
    preenche(10,tabela,1,2,"Gustavo","Copacabana","22451250");
    for(int i=0;tabela[i]!=NULL;i++){
        printf("%d\n",tabela[i]->matricula);
        imprime(tabela[i]->nome);
        printf("\n");
        imprime(tabela[i]->endereco);
        printf("\n");
        imprime(tabela[i]->telefone);
        printf("\n");
    }
}