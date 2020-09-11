#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    vector<int>votos;
    vector<int>novaLista;
    int i,j,n1,n2,n3,total,voto,teste=-1;
    cin>>n1>>n2>>n3;
    total=n1+n2+n3;
    for(i=0;i<total;i++){
        cin>>voto;
        votos.push_back(voto);
    }
    sort(votos.begin(),votos.end());
    i=0;
    while(i<total){
        j=i;
        while (votos[j+1]==votos[i] && j+1<total){
            j++;
        }
        if(j!=i){
            novaLista.push_back(votos[i]);
            i=j;
        }
        i++;
    }
    cout << novaLista.size()<<endl;
    for(i=0;i<novaLista.size();i++){
        cout<<novaLista[i]<<endl;
    }
}