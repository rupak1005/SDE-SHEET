#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans(nums.size(), 1);
    vector<int> prefix(nums.size(), 1);
    vector<int> suffix(nums.size(), 1);
    for(int i=1;i<nums.size();i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }
    for(int i=nums.size()-2;i>=0;i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }
    for(int i=0;i<nums.size();i++){
        ans[i] = prefix[i] * suffix[i];
    }
    for(int i=0;i<nums.size();i++){
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<suffix[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<ans[i]<<" ";
    }
}