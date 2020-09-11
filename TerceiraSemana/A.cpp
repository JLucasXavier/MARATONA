#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int number,price,i,days,coins;
    vector<int>shops;
    cin >> number;
    for(i=0;i<number;i++){
        cin >> price;
        shops.push_back(price);
    }
    sort(shops.begin(),shops.end());
    cin >> days;
    for(i=0;i<days;i++){
        cin>>coins;
        auto x=upper_bound(shops.begin(),shops.end(),coins);
        cout <<x-shops.begin()<<endl;
    }
}