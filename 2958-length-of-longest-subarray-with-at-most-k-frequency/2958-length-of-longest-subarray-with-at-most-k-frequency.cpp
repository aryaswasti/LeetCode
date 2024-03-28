class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int count = 0;
        int maxLen = 0;
        
        for (int l = 0, r = 0; r < nums.size(); r++) {
            umap[nums[r]]++;
            
            // Check if the count of nums[r] is greater than k
            while (umap[nums[r]] > k) {
                // Remove elements from the left until the count becomes less than or equal to k
                umap[nums[l]]--;
                if (umap[nums[l]] == 0) {
                    // If the count becomes 0, remove nums[l] from the map
                    umap.erase(nums[l]);
                }
                // Move the left pointer forward
                l++;
            }
            
            // Update the maximum length if necessary
            maxLen = max(maxLen, r - l + 1);
        }
        
        return maxLen;
    }
};