class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        int prefixsum=0;
        int count=0;
        for(auto i:nums){
            prefixsum+=i;
            int diff=prefixsum-k;
            if(map.find(diff)!=map.end()){
                count+=map[diff];
            }
            map[prefixsum]++;


        }
        return count;
    }
};