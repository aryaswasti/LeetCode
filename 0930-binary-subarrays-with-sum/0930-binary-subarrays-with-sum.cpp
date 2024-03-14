class Solution {
private:
    int atMost(vector<int> nums, int goal){
        int left = 0;
        int sum = 0;
        int ans = 0;
        
        for(int right=0; right<nums.size(); right++){
            sum+=nums[right];
            while(sum>goal && left<=right){
                sum-=nums[left];
                left++;
            }
            //formula to calcumate subarrays => right-left+1
            ans+=right-left+1;
        }
        return ans;
    }
    
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //atmost(subarrays with goal) - atmost(subarrays with goal-1) = exact(subarrays with goal)
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};