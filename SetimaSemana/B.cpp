#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n,p,tmp,tmp1=0,tmp2=0;
    vector<int>com;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>tmp;
        tmp=tmp-p;
        com.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        tmp1=tmp1+com[i];
        tmp2=max(tmp1,tmp2);
        tmp1=max(0,tmp1);
    }
    cout<<tmp2<<endl;
}