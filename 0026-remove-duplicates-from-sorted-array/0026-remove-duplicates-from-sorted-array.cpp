class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        
        int i = 1;
        int j = 1;
        while(j < nums.size()){
            if(nums[j-1] != nums[j]){
                nums[i] = nums[j];
                i++;
                j++;
            } else if(nums[j-1] == nums[j]){
                j++;
            }
        }
        return i;
    }
};