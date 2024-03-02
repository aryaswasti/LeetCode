class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> ans(n+1, -1);
        
        int left = 0;
        int right = n;
        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                ans[n] = nums[left]*nums[left];
                left++;
            } else {
                ans[n] = nums[right]*nums[right];
                right--;
            }
            n--;
        }
        return ans;
    }
};