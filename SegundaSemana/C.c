#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000

typedef struct pilha Pilha;

struct pilha{
    int n;
    int v[N];
};

int pilha_vazia(Pilha *p){
    return (p->n==0);
}

void pilha_libera(Pilha *p){
    free(p);
}

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p==NULL){
        exit(1);
    }
    p->n=0;
    return p;
}

void pilha_push(Pilha *p, int novo){
    if(p->n==N){
        printf("Pilha cheia");
        exit(1);
    }
    p->v[p->n]=novo;
    p->n++;
}

int pilha_pop(Pilha *p){
    int c;
    if(pilha_vazia(p)){
        printf("Pilha vazia\n");
        exit(1);
    }
    c=p->v[p->n-1];
    p->n--;
    return c;
}


int main (void){
    int i,tam,tmp,resto=0;
    Pilha * p = pilha_cria();
    int soma[10000]={0};
    char string[10000];
    
    while(gets(string)){
       if(!strcmp(string,"0")){
           break;
       }
       tam=strlen(string)-1;
       for(i=0;i<=tam;i++){
            pilha_push(p,string[i]-'0');
        }
        i=0;
        while(!pilha_vazia(p)){
            tmp=pilha_pop(p);
            soma[i+1]=soma[i+1]+tmp/10;
            soma[i]=soma[i]+(tmp%10);
            if(soma[i]>=10){
                soma[i]=soma[i]-10;
                soma[i+1]++;
            }
            if(soma[i+1]>=10){
                soma[i+1]=soma[i+1]-10;
                soma[i+2]++;
            }
            i++;
        }
        tmp=0;
        resto=0;
    }
    i++;
    while(soma[i]!=0){
        i++;
    }
    while(soma[i]==0){
        i--;
    }
    for(;i>=0;i--){
        printf("%d",soma[i]);
    }
    printf("\n");
    
    return 0;
}