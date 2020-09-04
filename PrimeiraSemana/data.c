#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "data.h" /* falta explicar */

struct data {
   int dd,mm,aa;
};

Data* dt_cria (int dia, int mes, int ano) {
    Data* data =(Data*)malloc(sizeof(Data));
    if(data==NULL){
        printf("Memória insuficiente\n");
        exit(1);
    }
    data->dd=dia;
    data->mm=mes;
    data->aa=ano;
    return data;
}

Data* dt_cria(int d){
    int dia,mes,ano;
    dia=d/1000000;
    mes=(d%1000000)/10000;
    ano=d%10000;
    return dt_cria(dia,mes,ano);
}

void dt_libera (Data* d){
    free(d);
}

char *dt_to_string (Data* d){
    char *str = (char*)malloc(11*sizeof(char));
    if(str == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    sprintf(str,"%02d/%02d/%04d",d->dd,d->mm,d->aa);
    return str;
}

int dt_difData(Data *dt1,Data *dt2) {
    int dias1, dias2;
 
    dt1->mm = (dt1->mm + 9)%12;
    dt1->aa = dt1->aa - dt1->mm/10;
 
    dt2->mm = (dt2->mm + 9)%12;
    dt2->aa = dt2->aa - dt2->mm/10;
 
    dias1 = 365*dt1->aa + dt1->aa/4 - dt1->aa/100 + dt1->aa/400 + (dt1->mm*306 + 5)/10 + ( dt1->dd - 1 );
    dias2 = 365*dt2->aa + dt2->aa/4 - dt2->aa/100 + dt2->aa/400 + (dt2->mm*306 + 5)/10 + ( dt2->dd - 1 );
 
    return dias2 - dias1;
}
