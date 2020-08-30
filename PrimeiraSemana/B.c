#include <stdio.h>
#include <math.h>

int localRainha(char tabul[8][9],int coluna){
    int i,local=-1,qtd=0;
    for(i=0;i<8;i++){
        if(tabul[coluna][i]=='*'){
            qtd++;
            local=i;
        }
    }
    if(qtd>1){
        return -2;
    }
    if(local!=-1){
        return local;
    }
}

int comparaTabuleiro(char tabul[8][9]){
    int i,j;
    int localI,localJ;
    for (i=0;i<8;i++){
        for(j=0;j<8;j++){
            localI=localRainha(tabul,i);
            localJ=localRainha(tabul,j);
            if(i!=j){
                if(localI==-2 || localJ==-2){
                    return 1;
                }
                if(localI!=-1 && localJ!=-1){
                    if(abs(localJ-localI)==abs(j-i) || localI==localJ){
                        return 1;     
                    }
                }
            }
        }
    }
    return 0;
}

int main(void){
    char tabuleiro[8][9];
    int i;
    for(i=0;i<8;i++){
        scanf("%s",&tabuleiro[i]);
    }
    comparaTabuleiro(tabuleiro)==0 ? printf("valid") : printf("invalid");
    return 0;
}