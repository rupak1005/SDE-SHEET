class Solution {
public:

    static bool custom(pair<char,int>&a,pair<char,int> &b){
        // if(a.second==b.second)return a.first>b.first;

        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }

        vector<pair<char,int>>
         res;
        for(auto i:mp){
            res.push_back({i.first,i.second});
        }
        sort(res.begin(),res.end(),custom);
        string ans;
        for(auto i:res){
            ans.append(i.second,i.first);
        }
        return ans;
    }
};