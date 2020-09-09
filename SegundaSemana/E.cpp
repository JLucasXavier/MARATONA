#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int busca(vector <string> &telefone,string nova){
    int resposta;
        int j=telefone.back().size();
        if(j>nova.size()){
            if(nova.compare(telefone.back().substr(0,nova.size()))==0){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(telefone.back().compare(nova.substr(0,telefone.back().size()))==0){
                return 1;
            }else{
                return 0;
            }
        } 
}

int main(){
    int i,j,casos,qtd,sera[42];
    char tmp[50];
    vector<string> telefone;
    cin >> casos;
    for(i=0;i<casos;i++){
        cin >> qtd;
        for(j=0;j<qtd;j++){
            cin >> tmp;
            telefone.push_back(tmp);
        }
        sort(telefone.begin(),telefone.end());
        for(j=0;j<qtd-1;j++){
            std::string nova=telefone.back().substr();
            telefone.pop_back();
            sera[i]=busca(telefone,nova);
            if(sera[i]==1){
                cout<<"NO"<<endl;
                break;
            }else if(j==qtd-2){
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}