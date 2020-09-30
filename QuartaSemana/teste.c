#include <stdio.h>
#define TAM 100
void subir(int vet[], int i) {
    int j = i/2;
    if(j>=1){
        if(vet[i]>vet[j]){
            int tmp = vet[i];
            vet[i] = vet[j];
            vet[j] = tmp;
            subir(vet,j);
        }
    }
}

void descer(int vet[], int i, int tam) {
    int esq = i*2;
    int dir = i*2 + 1;
    int maior = i;
    if(esq<=tam && vet[esq] > vet[i])
        maior = esq;
    if(dir <= tam && vet[dir] > vet[maior])
        maior = dir;
    if(maior != i){
        int tmp = vet[i];
        vet[i] = vet[maior];
        vet[maior] = tmp;
        descer(vet,maior,tam);
    }
    
}

void inserir(int vet[], int novo, int tam) {
    tam = tam+1;
    vet[tam] = novo;
    subir(vet,tam);
}

void agir(int chave) {
/* utiliza elemento prioritário */
    printf("chave prioritária: %d\n", chave);
    return;
}

void remover(int vet[], int tam) { //chama a agir() para o elemento prioritário
    agir(vet[0]);
    vet[1] = vet[tam];
    tam = tam - 1;
    descer(vet,1,tam);
}

void construir1(int vet[], int n) { // usando subir()
    for(int i = n-1; i>0; i--)
        subir(vet,i);
    subir(vet,n-1);
}

void construir2(int vet[], int n) { // usando descer()
    int i;
    int j=(n/2)-1;
    for(i=j;i>=0;i--)
        descer(vet, i, n);
}

void heap_sort(int vet[], int n){
    int i;
    int j=n;
    construir2(vet, n);
    for(i=n;i>1;i--){
        //troca raiz com o ultimo elemento (posicao j)
        int temp=vet[i];
        vet[i]=vet[1];
        vet[1]=temp;
        //diminui o tamanho do vetor a ser considerado na heep
        j--;
        //desce com a raiz nessa nova heap de tamanho j-1
        descer(vet, 1, j);
    }
}

int main()
{
    int vet1[] = { 33, 39, 28, 66, 70, 60, 78, 95 };
    int vet2[] = { 33, 39, 28, 66, 70, 60, 78, 95 };
    int tam = 8;
    int nova_chave=100;
    construir1(vet1, tam);
    for (int i = 0; i < tam; i++)
        printf("%d\t", vet1[i]);
    printf("\n");
    construir2(vet2, tam);
    for (int i = 0; i < tam; i++)
        printf("%d\t", vet2[i]);
    printf("\n");
    remover(vet2, tam);
    inserir(vet2, nova_chave, tam);
    for (int i = 0; i < tam; i++)
        printf("%d\t", vet2[i]);
    printf("\n");
    heap_sort(vet2, tam);
    for (int i = 0; i < tam; i++)
        printf("%d\t", vet2[i]);
}