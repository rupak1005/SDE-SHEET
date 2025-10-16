class Solution {
public:
    string longestPalindrome(string s) {
       
        string res=s.substr(0,1);
        for(int i=0;i<s.length();i++){
        string len1=expandfromcenter(s,i,i);
        string len2=expandfromcenter(s,i,i+1);
        if(len1.size()>res.size())res=len1;
        if(len2.size()>res.size())res=len2;

        }
        
        return res;
        
        
    }

    private:
    string expandfromcenter(string s,int left,int right){
        while(left>=0 && right <s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
};