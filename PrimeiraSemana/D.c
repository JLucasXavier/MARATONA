#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificaString(char *string){
    int i,qtd=0,t=0,q=0;
    for(i=0;string[i]!='\0';i++){
        if(string[i]=='1'){
            t=1;
        }
        if(string[i]=='0' && t==1){
            q++;
        }
        if(string[i]=='1' && q!=0){
            if(string[i+1]!='1'){
                qtd=qtd+q;
                q=0;
            }
        }
    }
    return qtd;
}

int main(){
    char **string;
    int i,casos,qtd;
    char temp[1000];
    scanf("%d",&casos);
    string = (char**)malloc(casos* sizeof(char *));
    for(i=0;i<casos;i++){
        scanf("%s",temp);
        qtd=strlen(temp);
        string[i]=(char*)malloc(qtd*sizeof(char));
        strcpy(string[i],temp);
    }
    for(i=0;i<casos;i++){
        printf("%d\n",verificaString(string[i]));
    }
}