// // Majority Element

// // Easy

// // Given an array nums of size n, return the majority element.

// // The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// // Example 1:

// // Input: nums = [3,2,3]
// // Output: 3

// // Example 2:

// // Input: nums = [2,2,1,1,1,2,2]
// // Output: 2

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int majorityElement(vector<int>& nums) {
//     int count = 0, candidate = -1;
//     for (int num : nums) {
//         if (count == 0) {
//             candidate = num;
//         }
//         count += (num == candidate) ? 1 : -1;
//     }
//     return candidate;
// }
// int majorityElement2(vector<int>& nums){
//     sort(nums.begin(), nums.end());
//     return nums[nums.size()/2];
// }

// int main(){
//     vector<int> nums1 = {3, 2, 3};
//     vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    
//     int result1 = majorityElement2(nums1); // Output: 3
//     int result2 = majorityElement2(nums2); // Output: 2
    
//     cout<<result1<<" "<<result2;
//     return 0;
// }
// // Time Complexity: O(n)
// // Space Complexity: O(1)   


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int removeDublicates(vector<int>& arr, int n){
    set<int>s;
    for(int i:arr){
        s.insert(i);
    }
    int k=s.size();
    int j=0;
    for(auto i :s){
        arr[j++]=i;
    }
    return k;

}


int main(){
    vector<int> arr = {1, 2, 2, 4, 4, 6, 7, 8, 9};
    int n = arr.size();
    int k=removeDublicates(arr, n);
    cout << "Number of unique elements: " << k << endl;
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
}