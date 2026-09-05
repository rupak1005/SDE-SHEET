class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int minprice=prices[0];
        int maxprofit=0;
        for(auto i:prices){
            if(i<minprice)minprice=i;
            if(i-minprice>maxprofit)maxprofit=i-minprice;
        }
        return maxprofit;
    }
};