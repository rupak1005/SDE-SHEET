class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long m=n;
        if(m<0)m=-1*m;
        while(m>0){
            if(m%2==0){
                x*=x;
                m/=2;
            }
            else{
                ans*=x;
                m--;
            }

        }
        if(n<0)ans=1.0/ans;
        return ans;
    }
};