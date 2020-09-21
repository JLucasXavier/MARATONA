/*
Autores:

Alexandre R. Bomfim Junior   1921241
Jose Lucas Teixeira  1921254
Rogerio Pazetto Saldanha da Gama 1612652

*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "hash.h"

struct hash {
    Lista **lst;
    int tam;
};

typedef struct elemHash {
    int key;
    void *value;
}ElemHash;

static ElemHash *hash_busca(Lista*lst,int key){
    lst_posFin(lst);
    ElemHash*tmp=lst_ant(lst);
    printf("%p busca\n",tmp);
    while(tmp!=NULL){
        if (key==tmp->key){
            return tmp->value;
        }
        tmp=lst_ant(lst);
    }
    return NULL;
}

static void hash_insere(Lista*lst, int key, void*value){
    ElemHash*tmp=(ElemHash*) malloc(sizeof(ElemHash));
    if (tmp==NULL){
        printf("Memรณria insuficiente!\n");
        exit(1);
    }
    tmp->key=key;
    tmp->value=value;
    lst_insFin(lst,tmp);
}

Hash *hash_cria(int tam){
    Hash* tmp=(Hash*)malloc(sizeof(Hash));
    if(tmp==NULL){
        printf("Memรณria insuficiente!\n");
        exit(1);
    }
    tmp->tam=tam;
    tmp->lst=(Lista**) malloc(tam*sizeof(Lista*));
    if (tmp->lst==NULL){
        printf("Memรณria insuficiente!\n");
        exit(1);
    }
    for(int i=0;i<tam;i++){
        tmp->lst[i]=NULL;
    }
    return tmp;
}

int hash_put(Hash *hash, int key, void *value){
    if (hash->lst[(key)%(hash->tam)]==NULL){
        hash->lst[(key)%(hash->tam)]=lst_cria();
    }
    if ((hash_busca(hash->lst[(key)%(hash->tam)], key))!=NULL){
        return 0;
    }
    hash_insere(hash->lst[(key)%(hash->tam)], key, value);
    return 1;
}

void *hash_get(Hash *hash , int key){
    ElemHash*tmp=hash_busca(hash->lst[(key)%(hash->tam)],key);
    if (tmp==NULL){
        return NULL;
    }
    return tmp;
}