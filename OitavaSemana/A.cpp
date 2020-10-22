#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n,m,tmp;
    cin>>n;
    tmp=sqrt(n);
    m=tmp*tmp;
    cout<<2*tmp+(n-m)/(tmp)+((n-m)%tmp!=0);
}