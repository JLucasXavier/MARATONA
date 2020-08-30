#include <stdio.h>
#include <stdlib.h>

int main(){
    int **vetor;
    int t,i,j=0,a,b;
    if(t>15 || t==0){
        scanf("%d",&t);
    }
    vetor = (int**)malloc(t * sizeof(int *));
    for (i = 0; i < t; ++i){
        vetor[i] = (int*)malloc(2*sizeof(int));
    }
    for(i = 0; i < t; i++){
		scanf("%d %d",&vetor[i][j], &vetor[i][j+1]);
	}
    for(i = 0; i < t; i++){
        if(vetor[i][j]==vetor[i][j+1]){ 
            printf("=\n");
        }else if(vetor[i][j]<vetor[i][j+1]){
            printf("<\n");
        }else{
            printf(">\n");
        }
    }

    return 0;
}