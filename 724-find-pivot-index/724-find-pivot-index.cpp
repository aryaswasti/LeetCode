class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0)
            return -1;
        else if(nums.size()==1)
            return 0;
        
        vector<int> ans;
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum = sum+nums[i];
            ans.push_back(sum);
        }
        
        int curr = 0;
        int lsum = 0;
        int rsum = 0;
        
        while(curr<nums.size())
        {            
            if(curr == 0)
            {
                lsum = 0;
                rsum = ans[nums.size()-1]-ans[curr];
            }
            else
            {
                lsum = ans[curr-1];
                rsum = ans[nums.size()-1]-ans[curr];
            }
            if(lsum == rsum)
                return curr;
            curr++;
        }
        return -1;
    }
};