#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    unordered_set<int> cds;
    int catalog,n,m,i,qtd=0;
    while(cin >> n>> m && n!=0 && m!=0){
        qtd=0;
        cds.clear();
        for(i=0;i<n;i++){
            cin >> catalog;
            cds.insert(catalog);  
        }
        for(i=0;i<m;i++){
            cin >> catalog;
            if(cds.count(catalog)){
                qtd++;
            }  
        }
        cout << qtd<<endl;
    }
    return 0;
}