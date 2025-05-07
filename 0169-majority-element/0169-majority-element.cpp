class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el = 0;
        
        for(auto i : nums) {
            if(cnt == 0) {
                el = i;
                cnt = 1;   // â initialize count
            } else if(i == el) {
                cnt++;
            } else {
                cnt--;
            }
        }
        
        return el;
    }
};
