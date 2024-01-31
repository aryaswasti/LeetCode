class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        //we do this so that first array is always the smaller one
        if(n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        //in this approach we will focus on making combined array to the left of median
        int left = (n1 + n2 + 1)/2;
        
        //binary search is done on smaller array
        //we select how many elements will be to the left of median from num1 => mid1
        //remaining elements from num2 that are taken to the left of median => mid2
        int low = 0;
        int high = n1;
        
        while(low<=high){
            //mid of smaller array(num1) (points in num1)
            int mid1 = (low + high)/2;
            //how many elements needed from num2(points in nums2)
            int mid2 = left - mid1;
            
            //l1 => largest of left side(num1)
            //l2 => largest of left side(num2)
            int l1 = INT_MIN, l2 = INT_MIN;
            
            //r1 => lowest of right side(num1)
            //r2 => lowest of right side(num2)
            int r1 = INT_MAX, r2 = INT_MAX;
            
            //initalise INT_MIN and INT_MAX to handle case of no elements
            
            //check if r1, r2, l1, l2 exists
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1-1 >= 0) l1 = nums1[mid1-1];
            if(mid2-1 >= 0) l2 = nums2[mid2-1];
            
            //check for valid case
            //left < right is checked for left of one array with right of other array
            //since array is sorted, we don't have to check left < right for same array
            if(l1<=r2 && l2<=r1){
                //check if n1+n2 is odd
                if((n1+n2)%2 == 1){
                    //left side of array has more elements than right =>so max(l1, l2) will be the median 
                    return max(l1, l2);
                }
                //for even n1+n2 => it will be mean of 2 center elements
                //from left side => max(l1, l2) 
                //from right side => low(r1, r2)
                return (double)((max(l1, l2) + min(r1, r2))/2.0);
            //since left(num1) > right(num2) => eliminate left of num1
            } else if(l1 > r2) {
                high = mid1 - 1;
            //here left(num2) > right(num1) => want bigger number in num1, hence add a left elment in num1
            } else {
                low = mid1 + 1;
            }
        }
        //default return
        return 0;
    }
};