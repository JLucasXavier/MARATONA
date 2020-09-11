#include <iostream>
#include <vector>

using namespace std;

int maior(vector<int>&vetor){
    int maior=0,i=0;
    for(i=0;i<vetor.size();i++){
        if(vetor[i]>maior){
            maior=vetor[i];
        }
    }
    return maior;
}

int main(){
    int n,i,ret,x;
    while(cin >> n){
        vector<int>eda;
        for(i=0;i<n;i++){
            cin >> ret >> x;
            if(ret==1){
                eda.push_back(x);
            }else{
                if(x==eda.front() && x!=maior(eda) && i==n-1){
                    cout <<"queue"<<endl;
                }else if(x!=eda.front() && x==maior(eda) && i==n-1){
                    cout<<"priority queye"<<endl;
                }
            }
        }
        eda.clear();
        
    }
}