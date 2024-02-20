class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //using sum => summation for n(size+1) - sum of nums
        int sum = 0;
        for(int i : nums){
            sum+=i;
        }
        
        int n = nums.size();
        int sumN = (n*(n+1))/2;
        return sumN - sum;
    }
};