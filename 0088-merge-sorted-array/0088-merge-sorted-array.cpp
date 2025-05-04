class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        for(int i=0;i<m;i++){
            ans.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++){
            ans.push_back(nums2[i]);
        }
        nums1=ans;
        sort(nums1.begin(),nums1.end());
    }
};