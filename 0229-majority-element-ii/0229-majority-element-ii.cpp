class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int cnt1=0;
        int cnt2=0;
        int el1=INT_MIN;
        int el2=INT_MIN;
        for(auto i:nums){
            if(cnt1==0 && el2!=i){
                cnt1=1;
                el1=i;
            }else if(cnt2==0 && el1!=i){
                cnt2=1;
                el2=i;
            }else if(el1==i)cnt1++;
            else if(el2==i)cnt2++;
            else{
                cnt1--,cnt2--;
            }
        }

         cnt1=0;
         cnt2=0;
        for(auto i:nums){
            if(el1==i)cnt1++;
            if(el2==i)cnt2++;
        }
        if(cnt1>n/3)ans.push_back(el1);
        if(cnt2>n/3)ans.push_back(el2);
        return ans;

        
    }
};
