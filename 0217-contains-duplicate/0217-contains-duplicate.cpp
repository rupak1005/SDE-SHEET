class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int a:nums){
            if(s.find(a)!=s.end()){
                return true;
            }
            s.insert(a);
        }
        return false;
    }
};