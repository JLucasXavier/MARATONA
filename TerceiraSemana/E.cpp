#include <iostream>
#include <algorithm>

using namespace std;

int menor(int x, int y){
    if(x<y){
        return x;
    }else{
        return y;
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int i,queries,c,m,s,team=0;
    cin >> queries;
    for(i=0;i<queries;i++){
        cin >>c>>m>>s;
        team=menor(menor(c,m),(c+m+s)/3);
        cout<<team<<endl;
    }
}