class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int zeros = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0)
                ans.push_back(nums[i]);
            else if(nums[i] == 0)
                zeros++;        
        }
        
        while(zeros>0) {
            ans.push_back(0);
            zeros--;
        }
        nums = ans;
    }
};