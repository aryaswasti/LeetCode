class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        int index, i;
        
        for(i = 0; i<nums.size(); i++) {
            if(umap.find(target - nums[i]) == umap.end()) {
                umap[nums[i]] = i;
            }
            else if(umap.find(target - nums[i]) != umap.end()) {
                index = umap.at(target-nums[i]);
                break;
            }
        }
        return {index, i};
    }
};