#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char placa[]="CJH1920";
    char tmp[9];
    strncpy(tmp,&placa[3],4);
   printf("%s",tmp);
}