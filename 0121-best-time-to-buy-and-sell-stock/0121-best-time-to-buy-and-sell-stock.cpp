class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minPrice=INT_MAX;
       int maxPro=0;
       
       for(auto i :prices){
        if(i<minPrice){
            minPrice=min(minPrice,i);

        }
        maxPro=max(maxPro,i-minPrice);
       }
       return maxPro;
    }
    
};