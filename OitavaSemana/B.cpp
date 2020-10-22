#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    vector<int>v;
    int tmp;
    for(int i=0;i<4;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    if(2*v[2]<v[3] || 2*v[3]<v[2] || v[3]>=v[1]){
        cout<<"-1"<<endl;
    }
}