class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>map;
        int start=0;
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            if(map.find(s[i])!=map.end()){
                start=max(start,map[s[i]]+1);
            }
            map[s[i]]=i;
            maxlen=max(maxlen,i-start+1);
        }
        return maxlen;


        
    }
};