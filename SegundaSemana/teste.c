#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista Lista;
struct lista{
    char telefone[12];
    Lista* prox;
};

Lista* lst_cria(void){
    return NULL;
}

Lista* lst_insere(Lista* lst,char* telefone){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    strcpy(novo->telefone,telefone);
    novo->prox=lst;
    return novo;
}


int comprimento(char*s){
    int i;
    int n=0;
    for(i=0;s[i]!='\0';i++){
        n++;
    }
    return n;
}


int busca(Lista* lst, char* telefone){
    Lista* p;
    int resposta=2,i;
    p=p->prox;
        int j=comprimento(p->telefone);
        int k=comprimento(telefone);
        if(j>k){
            for(i=0;i<k;i++){
            if(p->telefone[i]==telefone[i]){
                resposta=1;
            }else{
                resposta=0;
                break;
            }
        }
        }else{
            for(i=0;i<j;i++){
            if(p->telefone[i]==telefone[i]){
                resposta=1;
            }else{
                resposta=0;
                break;
            }
        }
        }
        busca(p->prox,telefone); 
    return resposta;
}

Lista* lst_remove(Lista* lst, char* telefone){
        Lista* a = NULL;
        Lista* p = lst;
        while(p !=NULL && p->telefone != telefone){
            a=p;
            p=p->prox;
        }
        if (p==NULL){
            return lst;
        }
        if (a==NULL){
            lst=p->prox;
        }else{
            a->prox=p->prox;
        }
    return lst;
}

int main(void){
    Lista* lst;
    Lista* p;
    lst= lst_cria();
    int j,casos,i,qtd,teste[41];
    char string[12];
    scanf("%d",&casos);
    for(i=0;i<casos;i++){
        scanf("%d",&qtd);
        for(j=0;j<qtd;j++){
            scanf("%s",string);
            lst=lst_insere(lst,string);
        }
    }
    for(j=0;j<qtd;j++){
            strcpy(string,lst->telefone);
            lst=lst_remove(lst,lst->telefone);
            teste[i]=busca(lst,string);
            if(teste[i]==1){
                break;
            }
        }
    for(i=0;i<casos;i++){
        if(teste[i]==0){
            printf("\nYES");
        }else{
            printf("\nNO");
        }
    }
    return 0;
}