#include <stdio.h>
#include <string.h>

int main (void){
    int tmp=0,i,j,qtd=0,tam;
    char string[101];
    int soma[101]={0};
    
    while(gets(string)){
       if(!strcmp(string,"0")){
           break;
       }
       tam = strlen(string);
  for(i = 0, j = tam-1; i < tam; i++, j--){
      soma[i]=(string[i]-'0')+soma[i];
        if((soma[i]>=10){
                soma[i]=(soma[i]+(string[i]-'0')+tmp)%10;
               tmp=(soma[i]+(string[i]-'0')+tmp)/10;
           }else{
               soma[i]=soma[i]+(string[i]-'0')+tmp;
           }
       }
       tmp=0;
    }
    for(i=0;i<=2;i++){
        printf("%d",soma[i]);
    }
}