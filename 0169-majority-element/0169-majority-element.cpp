class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==majority)count++;
            else {count--;
                if(count==0){
                    majority=nums[i];
                    count=1;
                }
            
            }


        }
        count=0;
        for(auto i:nums){
            if(i==majority)count++;
        }
        if(count>nums.size()/2)return majority;

        return 0;
    }
};