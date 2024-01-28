class Solution {
public:
    int majorityElement(vector<int>& nums) {    
        //Moore Voting Algorithm - O(n)
        //if finding element occuring more than n/2 => count of candidate will always be more
        int count = 0;
        int candidate = nums[0];
        
        for(int i=0; i<nums.size(); i++){
            int current = nums[i];
            
            //count=0 and current != candidate => assign current as new candidate
            if(count == 0 && current != candidate){
                candidate = current;
                count++;
            //current = candidate => increase count
            } else if(current == candidate) {
                count++;
            //count > 0 and current != candidate => decrease count for candidate 
            } else {
                count--;
            }
        }
        return candidate;
        
        // Using sorting - O(nlogn) 
        // sort(nums.begin(), nums.end());
        // //return middle element
        // return nums[nums.size()/2];
    }
};