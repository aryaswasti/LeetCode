class Solution {
public:    
    void nextPermutation(vector<int>& nums) {
        int idx1 = nums.size()-2;
        int idx2 = nums.size()-1;
        
        while(idx1 >= 0){
            if(nums[idx1] < nums[idx1+1]){
                break;
            }
            idx1--;
        }
        
        if(idx1 < 0){
            reverse(nums.begin(), nums.end());
        } else {
            while(idx2 >= 0){
                if(nums[idx2] > nums[idx1]){
                    break;
                }
                idx2--;
            }

            swap(nums[idx1], nums[idx2]);
            reverse(nums.begin()+idx1+1, nums.end());
        }
    }
};