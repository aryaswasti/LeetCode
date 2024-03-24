// Floyd's Fast & Slow find the cycle entrance
// Assume each element as pointer to array position.
// Duplicate number will point to same array position 

class Solution {
public:
    static int findDuplicate(vector<int>& nums) {
        // slow and fast pointer will intersect indicating a cycle
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(fast!=slow);

        // Now move slow2 from start and slow from intersection point
        // Now where they will intersect will be the start of cycle => answer
        int slow2=nums[0];
        while(slow!=slow2){
            slow=nums[slow];
            slow2=nums[slow2];
        }
        return slow;
    }
};


// // Solution by making the vector negative
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
        
//         //iteratere through nums array
//         for(int i=0; i<nums.size(); i++){
//             //get posititive value of nums
//             //abs because in case of duplicate element the nums[i] value will be -ve => -ve index will give error
//             int index = abs(nums[i]);
            
//             //check if the nums value at index is negative
//             if(nums[index] < 0){
//                 //if it is nagative it means it was previously visited by the duplicate element
//                 return index;
//             }
            
//             //set the visited element at index as -ve
//             nums[index] = -nums[index];
//         }
        
//         return 0;
//     }
// };