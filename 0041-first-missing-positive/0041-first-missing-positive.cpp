class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //replace -ve value with size+1 => because negative value is not in answer set
        //size+1(this is the worse case solution hence will not affect calculation of orignal answer)
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] < 1){
                nums[i] = n+1;
            }
        }
        
        //now mark the index as -ve to indicate that index is present as element in the array
        for(int i=0; i<n; i++){
            int idx = abs(nums[i]) - 1;
            
            //check if the element is in range
            if(idx<n && idx>=0){
                //check if it is already marked as negative
                if(nums[idx]>0){
                    nums[idx]*=-1;
                }
            }
        }
        
        //check for the first unmarked index(+ve element)
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                //return that index i.e. the element that is not present in the array => smallest positive number
                return i+1;
            }
        }
        
        return n+1;
    }
};