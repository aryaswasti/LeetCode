class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        //get maximum element of array
        long long int maxNum = *max_element(nums.begin(),nums.end());
        
        //size of nums
        long long int n = nums.size();
        //count of maximum element
        long long int count = 0;
        //number of subarray with at least k times maxNum => at least means (count >= k)
        long long int ans = 0;
        
        //start sliding window
        for(long long int right=0, left=0; right<n; right++){
            //increase 'count' if right element = maxNum
            if(nums[right] == maxNum){
                count++;
            }
            
            //iterate till window is still valid subarray(i.e. atleast k maxNum)
            while(count >= k){
                //if left element to be removed from window = maxNum
                if(nums[left] == maxNum){
                    //decrease count of maxNum
                    count--;
                }
                //n-right => gives remaining element of array beyond subarray
                //we can add each element once to current window to make another valid subarray
                //so ans = ans + all possible subarray of cuurent window(n-right)
                ans+=(n-right);
                //move left forward to reduce window size
                left++;
            }
        }

        return ans;
    }
};