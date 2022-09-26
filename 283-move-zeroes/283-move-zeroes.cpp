class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int end = nums.size()-1;
        
        while(end > 0) {
            if(nums[end] != 0)
                break;
            end--;
        }
        
        int i = 0;
        
        while(i<nums.size() && i!=end) {
            if(nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                i--;
                end--;
            } 
            i++;
        }
    }
};