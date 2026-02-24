class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.length();
        int maxlen=0;
        unordered_set<char> set;
        while(r<n){
            if(set.find(s[r])==set.end()){
                set.insert(s[r]);
                r++;
                maxlen=max(maxlen,r-l);

            }else{
                set.erase(s[l]);
                l++;
            }
        }
        return maxlen;
    }
};