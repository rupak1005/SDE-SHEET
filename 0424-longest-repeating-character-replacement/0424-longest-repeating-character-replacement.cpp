class Solution {
public:
    int characterReplacement(string s, int k) {
       int left=0,right=0,maxOccurance=0,ans=0;
       vector<int>Occurance(26,0);
       while(right<s.length()){
        maxOccurance=max(maxOccurance,++Occurance[s[right]-'A']);
        if((right-left+1)-maxOccurance>k){
            Occurance[s[left]-'A']--;
            left++;
        }
        ans=max(ans,right-left+1);
        right++;

       }
       return ans;
        
    }
};