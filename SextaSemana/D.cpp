#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long verifica(vector<int>&vetor,int s){
    int meio=vetor.size()/2;
    long long tmp=0;
    if(vetor[meio]==s){
        return 0;
    }else if(vetor[meio]<s){
        for(int i=meio;i<vetor.size() && vetor[i]<s;i++){
            tmp=(s-vetor[i])+tmp;
        }
    }else{
        for(int i=meio;i>-1 && vetor[i]>s;i--){
            tmp=(vetor[i]-s)+tmp;
        }
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    vector<int>median;
    int n,s,tmp;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>tmp;
        median.push_back(tmp);
    }
    sort(median.begin(),median.end());
    cout<<verifica(median,s)<<endl;
}