#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s1[] = "Rio de janeiro";
    char* s2 = "Rio de janeiro";
    //s2[0]='p';
    char *teste;
    teste = (char*)malloc(15);
    strcpy(teste,s2);
    printf("aqui %s",teste);
    teste[0]='p';
    printf("\naqui 2 %s",teste);
    //printf("tamanho %d",strlen(s2));
    //printf("\ntamanho %d",strlen(s1));
}