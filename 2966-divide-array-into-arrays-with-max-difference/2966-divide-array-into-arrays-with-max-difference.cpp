class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if(nums.size()%3 != 0){
            return {};
        }
        
        //Sort the input array
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        //Iterate over the sorted array in steps of 3
        for(int i=0; i<nums.size(); i+=3){
            //Check if there are at least 3 elements remaining
            if(i+2 < nums.size()){
                //If the difference between the maximum and minimum elements in the subarray is greater than k, return an empty list
                if(nums[i+2]-nums[i] > k){
                    return {};
                }
                //Append the current subarray to the result
                res.push_back({nums[i], nums[i+1], nums[i+2]});
            }
        }
        return res;
    }
};