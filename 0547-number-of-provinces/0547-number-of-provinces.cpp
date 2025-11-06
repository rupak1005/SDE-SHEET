class Solution {
public:


    void dfs(int idx,vector<vector<int>> &adj,vector<int> &visit){
        visit[idx]=1;
        
        for(auto it:adj[idx]){
            if(!visit[it]){
                dfs(it,adj,visit);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int ans=0;
        vector<vector<int>> adj(n);
        vector<int> visit(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 &&i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<adj.size();i++){
            if(!visit[i]){
                dfs(i,adj,visit);
                ans++;

            }
        }
        return ans;
    }
};