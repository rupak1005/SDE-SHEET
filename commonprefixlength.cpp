#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<string> arr = {"flower","flow","floght","fltter","flor"};
    sort(arr.begin(),arr.end());
    string ans;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[0][i]!=arr[arr.size()-1][i]){break;}
        else{
            ans+=arr[0][i];
        }
    }
    cout<<ans;
    return 0;
}