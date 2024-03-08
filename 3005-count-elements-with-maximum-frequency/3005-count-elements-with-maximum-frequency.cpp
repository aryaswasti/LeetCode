class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> umap;
        int max = 0;
        
        for(int i : nums){
            umap[i]++;
            if(umap[i] > max){
                max = umap[i];
            }
        }
        
        int ans = 0;
        for (auto& pair : umap) {
            if(umap[pair.first] == max){
                ans+=pair.second;
            }
        }
        
        return ans;
    }
};