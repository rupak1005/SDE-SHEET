class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++){
        // if the current interval does not
        // lie in the last interval:
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
        // if the current interval
        // lies in the last interval:
                ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            }

        }
        return ans;
    }
};