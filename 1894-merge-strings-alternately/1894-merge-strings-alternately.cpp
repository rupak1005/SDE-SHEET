class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        string ans;
        int i=0;
        int  j=0;
        while(i<n || j<m){
            if(i<n)ans+=word1[i++];
            if(j<m)ans+=word2[j++];
        }
        return ans;
    }
};
