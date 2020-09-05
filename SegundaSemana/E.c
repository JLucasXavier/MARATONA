#include <stdio.h>
#define N 400000

struct pilha{
    int n;
    char vet**;
};

typedef struct pilha Pilha;

Pilha * pilhaCria(void){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p==NULL){
        printf("Falta memoria\n");
        exit(1);
    }
    p->n=0;
    return p;
}

void pilhaPush(Pilha* p, char v){
    if(p->n == N){
        printf("Capacidade estourada\n");
        exit(1);
    }
    p->vet[p->n]=v;
    p->n++;
}



int main(void){
    int casos,i;
    scanf("%d",&casos);
    for(i=0;i<casos;i++){
        
    }
}