class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int buy=prices[0];
        int profit=0;
        for(auto i:prices){
            if(i<buy)buy=i;
            else{
                if(i-buy>profit)profit=i-buy;
            }
        }
        return profit;
    }
};