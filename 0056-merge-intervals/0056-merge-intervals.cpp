class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            vector<int>& previnterval=ans.back();

            if(previnterval[1]>=intervals[i][0]){
                previnterval[1]=max(previnterval[1],intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};