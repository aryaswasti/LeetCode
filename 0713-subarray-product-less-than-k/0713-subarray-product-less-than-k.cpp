class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //return edge case
        if(k <= 1){
            return 0;
        }
        
        int count = 0;
        int prod = 1;
        
        for(int right=0, left=0; right<nums.size(); right++){
            //include current element in product
            prod*=nums[right];
            
            //remove elements from left till product is in range k
            while(prod>=k)
                prod/=nums[left++];
            
            //add count of all products present between [right, left]
            count+=(right-left)+1;
        }
        
        return count;
    }
};