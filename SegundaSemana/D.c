#include <stdio.h>
#include <stdlib.h>

int buscar(int vetor[],int local, int valor,int tam){
    int i,qtd=0;
    for(i=0;i<tam;i++){
        if(vetor[i]==valor){
            qtd++;
        }
        if(vetor[i]==valor && qtd==local){
            return i+1;
        }
    }
    return 0;
}

int main(void){
    int n,m,i=0,pos,valor,x,teste=1,tamanho;
    int vetor[100001];
    int vetorPrint[100001];
    while (scanf("%d %d", &n, &m) != EOF){
        i++;
        if(teste!=0){
            for(i=0;i<n;i++){
                scanf("%d",&vetor[i]);
                teste=0;
                tamanho=n;
            }
            i=0;
        }
        if(i!=0){
            vetorPrint[i-1]=buscar(vetor,n,m,tamanho);
        }
    }
   for(i=0;i<4;i++){
        printf("%d\n",vetorPrint[i]);
    }

    return 0;
}