#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n,c=0;
    string a,b;
    cin>>n;
    cin>>a;
    cin>>b;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            c++;
            if(a[i+1]!=b[i+1] && a[i+1]!=a[i]){
                i++;
            }
        }
    }
    cout<<c<<endl;
}