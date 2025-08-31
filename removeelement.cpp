
#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    vector<int> ans;
    for(auto i:nums){
        if(i==val){continue;}
        else{
            ans.push_back(i);
        }
    }
    nums=ans;
    return ans.size();

}

int main(){
    vector<int> nums = {3,2,2,3};
    int val = 3;
    int k = removeElement(nums, val);
    cout<<k<<endl;
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}