class Solution {
public:    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int p1 = 0, p2 = 0;
        set<int> res;
        
        while(p1 < nums1.size() && p2 < nums2.size())
        {
            if(nums1[p1] == nums2[p2])
                res.insert(nums1[p1]);

            
            if(nums1[p1] <= nums2[p2])
                p1++;
                
            else if(nums2[p2] <= nums1[p1])
                p2++;
        }
        
        vector<int> v(res.begin(), res.end());
        return v;
    }
};