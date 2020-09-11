#include <iostream>
#include <vector>

using namespace std;

int main(){
    int casos,i;
    cin >> casos;
    int tmp,ultimo;
    int qtd=0;
    vector<int> magnet (100000);    
    for(i=0;i<casos;i++){
        cin >> tmp;
        magnet.push_back(tmp);
        if(ultimo!=tmp && i>0){
            qtd++;
        }
        ultimo=tmp;
    }
    printf("%d\n",qtd+1);
}