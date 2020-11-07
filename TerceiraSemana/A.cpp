#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int vetor[10],valor,pos,cont=0;
    vetor[0] = 1;
    cin>>valor;
    for (int i=1;i<=9;i++) {
        vetor[i] = i*vetor[i-1];
    }
    for(int i=1;i<=9;i++){
        if(vetor[i]>valor){
            pos=i;
            break;
        }
    }
    for(int i=pos-1;valor>0;i--){
        valor=valor-vetor[i];
        cont++;
    }
    cout<<cont<<endl;
}