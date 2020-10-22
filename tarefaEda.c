#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1031

int colisao=0;

struct automovel{
    char placa[9];
};
typedef struct automovel Automovel;

typedef Automovel* Hash[TAM];

int hash(char placa[9]){
    char tmp[9];
    strncpy(tmp,&placa[3],4);
    int valor=tmp-'0';
    return (valor%TAM);
}

int hash2(char placa[9]){
    char tmp[9];
    strncpy(tmp,&placa[3],4);
    int valor=tmp-'0';
    return TAM - 2 - valor%(TAM-2);
}

Automovel* insere(Hash tabela,char placa[9]){
    int h=hash2(placa);
    while(tabela[h]!=NULL){
        if(tabela[h]->placa==placa){
            break;
        }
        h=(h+1) % TAM;
        colisao+=1;
    }
    if(tabela[h]==NULL){
        tabela[h]=(Automovel*) malloc(sizeof(Automovel));
        strcpy(tabela[h]->placa,placa);
    }
    return tabela;
}

Automovel* busca(Hash tabela, char placa[9]){
    int h=hash(placa);
    int h2=hash2(placa);
    while(tabela[h]!=NULL){
        if(tabela[h]->placa==placa){
            return tabela[h];
        }
        h=(h+h2)%TAM;
    }
    return NULL;
}

int main(){
    Hash vet;
    FILE *arq;
    char le_placa[9];
    char *result;
    int i=0;

    arq=fopen("placas.txt","rt");
    if(arq==NULL){
        exit(0);
    }
    printf("CHEGAMO\n");
    while (!feof(arq)){
        result=fgets(le_placa,9,arq);
        if(result){
            insere(vet,le_placa);
        }
        i++;
    }
    printf("Placas lidas: %d\n",i);
    printf("Colisoes: %d\n",colisao);
    fclose(arq);    
}