class Solution {
public:
    int binarySearch(int left, int right, vector<int>& nums, int target)
    {        
        while(left <= right)
        {
            int mid = (left+right)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        
        if(nums.size() == 0)
        {
            vector<int> res{-1,-1};
            return res;   
        }
        
        int firstPos = binarySearch(0, nums.size()-1, nums, target);
        
        if(firstPos == -1)
        {
            vector<int> res{-1,-1};
            return res;
        }
        
        int startPos = firstPos, endPos = firstPos, leftTemp = firstPos, rightTemp = firstPos;
        
        while(leftTemp != -1)
        {
            startPos = leftTemp;
            leftTemp = binarySearch(0, startPos-1, nums, target);
        }
        
        while(rightTemp != -1)
        {
            endPos = rightTemp;
            rightTemp = binarySearch(endPos+1, nums.size() - 1, nums, target);
        }
        
        
        vector<int> res{startPos, endPos};
        return res;
    }
};