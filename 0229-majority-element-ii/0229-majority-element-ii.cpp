class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(auto i:nums){
            mp[i]++;
            if(mp[i]>nums.size()/3 && find(ans.begin(),ans.end(),i)==ans.end()){
                ans.push_back(i);
            }
        }
        return ans;

    }
};