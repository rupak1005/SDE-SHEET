       #include<iostream>
       #include<bits/stdc++.h>
       using namespace std;

       void topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(auto i:nums){
            mpp[i]++;
        }
        // sort(mpp.begin()[1],mpp.end()[1]);
        for(auto i:mpp){
            cout<<i.first<<"->"<<i.second<<endl;
        }
        vector<pair<int,int>> vec;
        for(auto i :mpp){
            vec.push_back({i.first,i.second});
        }
        sort(vec.begin(),vec.end(),[](const pair<int,int> &a,const pair<int,int> &b){
            return a.second>b.second;
        });

        for(int i=0;i<k;i++){
            cout<<vec[i].first<<" ";
        }

        
    }

        int main(){
            vector<int> nums = {1,1,1,2,2,3};
            int k = 2;
            topKFrequent(nums, k);
            
            return 0;
        }