class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        //store perimeter/sum of all sides
        long long sum = 0;
        
        //can't use accumulate as sum is more than INT_MAX
        for(int j=0;j<nums.size();j++){
            sum=sum+nums[j];
          }
        //sort sides according to their length(smallest first)
        sort(nums.begin(), nums.end());
        
        //iterate from n-1(largest side)
        for(int i=nums.size()-1;i>1;i--){
            //check if current largest side < sum of remaining sides
            if(nums[i]<sum-nums[i]){
                //since we are iterating LARGE to SMALL we return the first true value
                return sum;
                
            //check for next largest size
            }else{
                //decrease current non-possible side from sum
                sum=sum-nums[i];
            }
        }
        
        //no polygon possible
        return -1;
    }
};