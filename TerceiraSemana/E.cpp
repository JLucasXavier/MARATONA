#include <iostream>
#include <vector>

using namespace std;

int main(){
    int i,queries,c,m,s,team=0;
    cin >> queries;
    for(i=0;i<queries;i++){
        cin >>c>>m>>s;
        while(c!=0 || m!=0){
            if((c==1 && m>1 && s>1) || (m==1 && c>1 && s>1)){
                team++;
                break;
            }else{
                
            }
        }
    }
}