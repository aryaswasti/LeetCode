class Solution {
public:
    void swap(int &num1, int &num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        
        for(int j=0; j<nums.size(); j++) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};