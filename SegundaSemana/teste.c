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
       length = strlen(s);
  for(i = 0, j = length-1; i < length; i++, j--){
           if((soma[i]+(string[i]-'0')+tmp)>=10){
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