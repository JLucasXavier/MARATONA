#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int corteFita(vector<int>&vetor,int tam){
    vector<int>::iterator it=max_element(vetor.begin(),vetor.end());
    if(tam==*it){
        vetor.erase(it);
        vector<int>::iterator it=max_element(vetor.begin(),vetor.end());
    }
    int valor=tam-*it;
    int c=1;
    it=find(vetor.begin(),vetor.end(),valor);
    if(it!=vetor.end()){
        c++;
    }else{
        for(int i=0;valor!=0;i++){
            if(valor%vetor[i]==0){
                c=c+valor/vetor[i];
                valor=valor-(valor/vetor[i])*vetor[i];
            }
        }
    }
    return c;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int tmp,fitaOri;
    vector<int>fita;
    for(int i=0;i<4;i++){
        cin>>tmp;
        fita.push_back(tmp);
    }
    fitaOri=fita[0];
    fita.erase(fita.begin());
    cout<<corteFita(fita,fitaOri)<<endl;
}