class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //store difference of <countOne-CountZero, index>
        unordered_map<int, int> umap;
        //store count of 0
        int zeros = 0;
        //store count of 1
        int ones = 0;
        //store maximum length od subArray
        int maxLen = 0;
        
        umap[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            //count 0
            if(nums[i] == 0){
                zeros++;
            //count 1
            } else if(nums[i] == 1){
                ones++;
            }
            
            //calculate difference between count of 0 and 1
            int diff = zeros - ones;
            
            //check if same diff exist in prev index
            if (umap.count(diff)) {
                //if yes => sum from prevIndex to currIndex(of same difference) will be same
                //i - umap[diff] => currentIndex - prevIndex
                maxLen = max(maxLen, i - umap[diff]);
            } else {
                //store first unique difference
                umap[diff] = i;
            }
        }
        //return maxLength
        return maxLen;
    }
};