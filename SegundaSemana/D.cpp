#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int a,b,i,valor,l,k,tmp;
    map <int,vector<int>> vetor;
    while (cin >> a >> b){
        for(i=0;i<a;i++){
            cin >> valor;
            vetor[valor].push_back(i);
        }
        for(i=0;i<b;i++){
            cin>> l >> k;
            if(!vetor.count(k) || vetor[k].size()<l){
                cout << 0<<endl;
            }else{
                cout <<vetor[k][l-1]+1<<endl;
            } 
        }
    }
}