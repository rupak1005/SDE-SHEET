class Solution {
public:
    bool validPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return ispalindrome(s,l+1,r) || ispalindrome(s,l,r-1);
            }else{
                l++;
                r--;
            }
        }
        return true;

    }

    bool ispalindrome(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r])return false;
            else{
                l++;
                r--;
            }
        }
        return true;
    }
};