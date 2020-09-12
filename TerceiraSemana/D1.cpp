#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    long long int qual=0;
    long long int i,j=0,dorm,carta,tmp,teste;
    cin >> dorm >>carta;
    vector<long long int>dorms;
    vector<long long int>cartas;
    for(i=0;i<dorm;i++){
        cin >>tmp;
        dorms.push_back(tmp);
    }
    for(i=0;i<carta;i++){
        cin>>tmp;
        cartas.push_back(tmp);
    }
    for(i=0;i<carta;i++){
        while(cartas[i]>dorms[j]+qual){
            qual=qual+dorms[j++];
        }
        cout<<j+1<<" "<<cartas[i]-qual<<endl;
    }
}