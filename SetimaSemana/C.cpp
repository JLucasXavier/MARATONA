#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

using namespace std;

int a,b,c;
int dinamico[4001];
int resolve(int n){
    if(n == 0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    if(dinamico[n] != -1){
        return dinamico[n];
    }else{
        dinamico[n] = max(1+resolve(n-a),max(1+resolve(n-b),1+resolve(n-c)));
        return dinamico[n];
    }
}
int main(){
    int n,x;
    cin>>n>>a>>b>>c;
    for(int i=0;i<4001;++i){
        dinamico[i] = -1;
    }
    x = resolve(n);
    cout<<x<<endl;
}