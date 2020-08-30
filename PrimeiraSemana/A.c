// TOILET SEAT //
#include <stdio.h>
#include <string.h>

int main(){
    int i,poli1=0,poli2=0,poli3=0,qtdU=0,qtdD=0;
    char string[1000];
    if(strlen(string)<2 || strlen(string)>1000){
        scanf("%s",&string);
    }
    if(string[0]=='U' && string[1]=='U'){
        poli2++;
    }
    if(string[0]=='D' && string[1]=='D'){
        poli1++;
    }
    if(string[0]=='D' && string[1]=='U'){
        poli1++;
        poli2=poli2+2;
    }
    if(string[0]=='U' && string[1]=='D'){
        poli1=poli1+2;
        poli2++;
    }
    for(i=1;string[i]!='\0';i++){
        if(i>=2){
            if(string[i]=='U'){
                qtdU++;
            }else{
                qtdD++;
            }
        }
        if(string[i]!=string[i-1]){
            poli3++;
        }
    }
    printf("%d\n",poli1+qtdD*2);
    printf("%d\n",poli2+qtdU*2);
    printf("%d",poli3);

    return 0;
}