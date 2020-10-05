#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int N, S, R;
    cin >> N >> S >> R;
    vector<bool> kayaks(N + 1);
    while(S--){
        int i;
        cin >> i;
        kayaks[i] = true;
    }
    vector<int> reserves;
    while(R--){
        int i;
        cin >> i;
        reserves.push_back(i);
    }
    vector<int> no;
    for(auto i:reserves){
        if(kayaks[i]){
            kayaks[i] = false;
        } else if(i-1 >= 1 && i + 1 <= N &&kayaks[i-1] && kayaks[i+1]){
            no.push_back(i);
        } else if(i-1 >= 1 && kayaks[i-1]){
            kayaks[i-1]=false;
        } else if(i + 1 <= N && kayaks[i+1]){
            kayaks[i+1]=false;
        }
    }
    for(auto i:no){
        if(i-1 >= 1 && kayaks[i-1]){
            kayaks[i-1] = false;
        } else if(i + 1<= N && kayaks[i+1]){
            kayaks[i+1]=false;
        }
    }
    int c=0;
    for(auto i:kayaks){
        if(i){
            c++;
        }
    }
    cout << c;
    return 0;
}