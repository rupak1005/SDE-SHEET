class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> freq;
        int n=grid.size();

        for(auto i:grid){
            for(auto j :i){
                freq[j]++;
            }
        }
        
        int repeated=1;
        int missing =-1;
        for(int i=1;i<=n*n;i++){
            if(freq[i]==2)repeated=i;
            if(freq[i]==0)missing=i;


        }
     return {repeated,missing};   
    }
};