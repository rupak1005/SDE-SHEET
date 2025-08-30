class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;

        for(int i:nums){
            ans.push_back(i);
        }
        for(int i:nums){
            ans.push_back(i);
        }
        return ans;
    }
};