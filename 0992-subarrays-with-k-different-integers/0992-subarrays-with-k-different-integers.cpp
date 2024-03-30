class Solution {
private:
    int subArrayWithAtMostK(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int ans = 0;
        
        for(int right = 0, left = 0; right < nums.size(); right++) {
            umap[nums[right]]++;
            
            while (umap.size() > k) {
                umap[nums[left]]--;
                if (umap[nums[left]] == 0) {
                    umap.erase(nums[left]);
                }
                left++;
            }
            
            ans+=(right-left)+1;
        }
        
        return ans;
    } 
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = subArrayWithAtMostK(nums, k) - subArrayWithAtMostK(nums, k-1);
        return ans;
    }
};