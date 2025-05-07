class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long m=n;
        if(m<0)m=-1*m;
        while(m>0){
            if(m%2==1){
                ans*=x;
                m--;
            }else{
                x*=x;
                m/=2;
            }
            
        }
        if(n<0){
                ans=1.0/ans;
            }
        return ans;
    }
};