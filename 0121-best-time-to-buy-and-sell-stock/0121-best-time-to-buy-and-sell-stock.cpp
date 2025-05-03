class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy=prices[0];
        int maxprofit=0;
        for(auto i: prices){
            
                maxprofit=max(maxprofit,i-bestbuy);
            
            bestbuy=min(bestbuy,i);
        }
        return maxprofit;
    }
};