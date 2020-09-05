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
    int n,m,i,pos,valor;
    scanf("%d %d",&n,&m);
    int vetor[n];
    for(i=0;i<n;i++){
        scanf("%d",&vetor[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d %d",&pos,&valor);
        printf("%d\n",buscar(vetor,pos,valor,n));
    }
}