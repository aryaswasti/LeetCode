class Solution {
public:
    //if k>n then k=k%n (after evern n rotation nums become intial arrary.)
    //S.C. = O(1)
    //Example: [1,2,3,4,5,6,7] k=3;
    //First reverse index 0-4,after reverse nums : [4,3,2,1,5,6,7],
    //Then reverse index 4-6, after reverse nums :[4,3,2,1,7,6,5],
    //Finally reverse 0-n-1, after reverse nums:[5,6,7,1,2,3,4].
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin()+(n-k),nums.end());
        reverse(nums.begin(),nums.begin()+(n-k));
        reverse(nums.begin(),nums.end());
    }
};