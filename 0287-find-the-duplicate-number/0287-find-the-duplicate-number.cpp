class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //iteratere through nums array
        for(int i=0; i<nums.size(); i++){
            //get posititive value of nums
            //abs because in case of duplicate element the nums[i] value will be -ve => -ve index will give error
            int index = abs(nums[i]);
            
            //check if the nums value at index is negative
            if(nums[index] < 0){
                //if it is nagative it means it was previously visited by the duplicate element
                return index;
            }
            
            //set the visited element at index as -ve
            nums[index] = -nums[index];
        }
        
        return 0;
    }
};