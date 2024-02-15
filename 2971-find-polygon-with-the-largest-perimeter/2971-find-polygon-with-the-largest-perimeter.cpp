class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0;
        for(int j=0;j<nums.size();j++){
            sum=sum+nums[j];
          }
        sort(nums.begin(), nums.end());
        
        for(int i=nums.size()-1;i>1;i--){
            if(nums[i]<sum-nums[i]){
                return sum;
            }else{
                sum=sum-nums[i];
            }
        }
        return -1;
    }
};