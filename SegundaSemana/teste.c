#include <stdio.h>
#include <string.h>
 #include <stdlib.h>
 #include <conio.h>



int main(void)
 {
     int numero;
    printf ("digite qtd de numeros\n");
    scanf("%d", &numero);

    int vetor[numero];
    int x, i;

    printf ("digite o numeros\n");

    for (i = 0; i < numero; i++)   /*Este laço faz o scan de cada elemento do vetor*/
    {
       scanf("%d", &vetor[i] );
    }

    printf("%d",vetor[3]);
    return 0;
 }