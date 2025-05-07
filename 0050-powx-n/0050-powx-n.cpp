class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long m=n;//to overcome overflow issue
        if(m<0)m=-1*m;//to make it positive first then will invert the answer
        while(m>0){
            if(m%2==1){//if power odd
                ans*=x;//multiply x to the ans
                m--;//minus the power
            }else{//if even
                x*=x;
                m/=2;//half the power
            }
            
        }
        if(n<0){//invert if -ve
                ans=1.0/ans;
            }
        return ans;
    }
};