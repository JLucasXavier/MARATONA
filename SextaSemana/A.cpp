#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    vector<int>days;
    int N,dias,qtd;
    cin>>N;
    for(int i=0;i<N;i++){
        cin >> dias;
        days.push_back(dias);
    }
    sort(days.begin(),days.end(),greater<int>());
    qtd=days[0]+2;
    for(int i=1;i<N;i++){
        if((days[0]-i)-(days[i])<0){
            qtd++;
            days[0]=days[0]+1;
        }
    }
    cout<<qtd<<endl;
}