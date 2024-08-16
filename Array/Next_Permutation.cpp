// Code to find the next Permutation : T.C = O(N), S.C = O(1)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int findBreakPoint(vector<int>&nums,int n){
         // traverse from back
         for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]) // if found dip means after that some elements are greater
               return i; // it is a break point
         }
       return -1; // no Permutation after that
    }
    void swapWithExactlyGreater(int index,vector<int>& nums,int n){
         // traverse from back because elements are sorted in descending order after index
         for(int i = n-1 ; i >= index; i--){
            if(nums[i] > nums[index]){  
               swap(nums[i],nums[index]); // if found greater swap with index
               return;
            }
         }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = findBreakPoint(nums,n);  // find the point after which some elements are greater
        if(index == -1){  // if no such point 
            reverse(nums.begin(),nums.end());  // reverse the array
            return;
        }
        swapWithExactlyGreater(index,nums,n);  // find the exactly greater element than nums[index] and swap it
        reverse(nums.begin()+index+1, nums.end()); // reverse the array after the break point
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    Solution obj;
    obj.nextPermutation(v);
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }

    return 0;
}
