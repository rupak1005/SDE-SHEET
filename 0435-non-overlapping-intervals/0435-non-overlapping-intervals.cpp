class Solution {
public:
static bool comp(vector<int> a,vector<int>b){
    return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res=0;
        if(intervals.size()==0)return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int prev_end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(prev_end> intervals[i][0]){
                res++;
            }else{
                prev_end=intervals[i][1];
            }
        }
        return res;
    }
};