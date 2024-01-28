class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //keeps track of maximum sum
        int maxSum = nums[0];
        //keeps track of current maximum sum
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            //check currentElement > currentSum + currentElement
            //as there are negatuve numbers current number maybe be more than the current sum
            currentSum = max(nums[i], currentSum + nums[i]);
            //if currentSum is larger than te maxSum, replace it
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};