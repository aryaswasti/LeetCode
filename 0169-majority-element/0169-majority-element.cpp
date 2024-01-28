class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //O(nlogn) - Using sorting
        sort(nums.begin(), nums.end());
        //return middle element
        return nums[nums.size()/2];
        
        
        //O(n) - Moore Voting Algorithm
//         int count = 0;
//         int candidate = nums[0];
        
//         for(int i=0; i<nums.size(); i++){
//             int current = nums[i];
            
//             if(count == 0 && current != candiate){
//                 candidate = current;
//                 count++;
//             } else if(current == candidate) {
//                 count++;
//             } else {
//                 count--;
//             }
//         }
//         return candidate;
    }
};