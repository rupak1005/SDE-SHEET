class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(auto i:nums){
            mpp[i]++;
        }
        vector<pair<int,int>>vec;
        for(auto i:mpp){
            vec.push_back({i.second,i.first});
        }

        sort(vec.begin(),vec.end(),[](const pair<int,int> &a,const pair<int,int> &b){
            return a.first>b.first;
        });
        
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        
        return ans;
        
    }
};