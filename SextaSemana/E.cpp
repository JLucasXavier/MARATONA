#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int qtdAvos(vector<int>&vetor){
    int qtd=1,tmp=0,tmp1=0;
    for(int i=0;i<vetor.size();i++){
        tmp++;
        if(tmp>=vetor[i]){
            tmp1=tmp;
        }
    }
    return tmp1;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    vector<int>avos;
    int t,n,a;
    cin>>t;
    while(t>0){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            avos.push_back(a);
        }
        sort(avos.begin(),avos.end());
        cout<<qtdAvos(avos)+1<<endl;
        avos.clear();
        t--;
    }
}