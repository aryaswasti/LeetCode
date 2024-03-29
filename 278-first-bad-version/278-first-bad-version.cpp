// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        int mid;
        
        while(true)
        {
            mid = left+(right-left)/2;
            
            if(isBadVersion(mid)==false && isBadVersion(mid+1)==true)
                return mid+1;
            else if(isBadVersion(mid) == false)
                left = mid+1;
            else
                right = mid-1;
        }
    }
};