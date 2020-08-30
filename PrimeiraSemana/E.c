// ODD SUM //
#include <stdio.h>
#include <stdlib.h>

int main(){
    int **vetor;
    int casos=0,i,soma=0;
    int tmp;
    while(casos<1 || casos>100){
        scanf("%d",&casos);
    }
    vetor=(int**)malloc(casos*sizeof(int*));
    for(i=0;i<casos;i++){
        vetor[i]=(int*)malloc(2*sizeof(int));
    }
    for(i=0;i<casos;i++){
        scanf("%d",&vetor[i][0]);
        scanf("%d", &vetor[i][1]);
    }
    for(i=0;i<casos;i++){
        tmp=vetor[i][0];
        while(tmp<=vetor[i][1]){
            if((tmp%2)!=0){
                soma=soma+tmp;
                tmp++;
            }else{
                tmp++;
            }
        }
        printf("Case %d: %d\n",i+1,soma);
        soma=0;
    }
}