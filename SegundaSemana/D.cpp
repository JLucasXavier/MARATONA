#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int buscar(vector <int> &vetor,int local, int valor){
    int i,qtd=0;
    for(i=0;i<vetor.size();i++){
        if(vetor[i]==valor){
            qtd++;
        }
        if(vetor[i]==valor && qtd==local){
            return i+1;
        }
    }
    return 0;
}

int main(){
    int a,b,i,valor,l,k;
    vector <int> vetor;
    while (cin >> a >> b){
        for(i=0;i<a;i++){
            cin >> valor;
            vetor.push_back(valor);
        }
        for(i=0;i<b;i++){
            cin>> l >> k;
            if(l<0)

        }
    }
}