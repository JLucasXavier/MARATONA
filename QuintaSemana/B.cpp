#include <iostream>

using namespace std;

int tmp(long long n, long long m){
    long long tmp1=n,tmp2=0;
    while(tmp1>=m){
        tmp2=tmp2+m;
        tmp1=tmp1-m;
        tmp1=tmp1-(tmp1/10);
    }
    tmp2=tmp2+tmp1;
    if(tmp2*2>=n){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    long long n,i=1,j;
    cin>>n;
    j=n;
    while(j>i){
        long long m=(j+i)/2;
        if(tmp(n,m)==1){
            j=m;
        }else{
            i=m+1;
        }
    }
    cout <<i<<endl;
}