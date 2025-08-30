#include<iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    vector<string> arr = {"eat","tea","tan","ate","nat","bat"};
    unordered_map<string,vector<string>> mp;
    for(auto i:arr){
        string temp=i;
        sort(temp.begin(),temp.end());
        mp[temp].push_back(i);
    }
    for(auto i:mp){
        cout<<i.first<<" ";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vector<vector<string>> ans;
    for(auto i:mp){
        ans.push_back(i.second);
    }
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}