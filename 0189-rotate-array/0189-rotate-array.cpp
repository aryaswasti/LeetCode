class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        ans = nums;
        int n = nums.size();
        
        if(k>n){
            k = k%n; 
        }
        
        int i = 0;
        int j = n-k;
        while(j<n){
            nums[i] = ans[j];
            i++;
            j++;
        }
        
        int l = 0;
        while(i<n){
            nums[i] = ans[l];
            i++;
            l++;
        }
    }
};