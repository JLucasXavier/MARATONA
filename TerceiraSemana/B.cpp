#include <iostream>
#include <vector>

using namespace std;

int main(){
    int casos,i;
    cin >> casos;
    int tmp,ultimo;
    int qtd=0;
    for(i=0;i<casos;i++){
        cin >> tmp;
        if(ultimo!=tmp){
            qtd++;
        }
        ultimo=tmp;
    }
    printf("%d\n",qtd);
}