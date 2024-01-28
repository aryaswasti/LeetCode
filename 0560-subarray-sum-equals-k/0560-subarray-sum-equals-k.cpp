class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //store all possible sum(to left of current element) of array
        //<sum, no. of occurance of sum>
        unordered_map<int, int> umap;
        
        umap[0] = 1;
        int currSum = 0;
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            //calculating total sum to the left of element
            currSum += nums[i];
            
            //currentNumber - target = number needed to reach target
            //if number to reach target exist => add umap count of the number to answer
            if (umap.count(currSum-k) > 0)
                ans += umap[currSum-k];
            
            umap[currSum]++;
        }
        return ans;
    }
};