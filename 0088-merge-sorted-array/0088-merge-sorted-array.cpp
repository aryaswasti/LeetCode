class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Pointer for nums1
        int j = n - 1; // Pointer for nums2
        int k = m + n - 1; // Pointer for the end of merged array

        // it will not overwrite nums1 elements
        while (i >= 0 && j >= 0) {
            // add nums[i] at k
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            // add nums2[j] at k
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Copy remaining elements from nums2, if any
        // don't need to copy nums1 smaller elements as it is already in place(within nums1)
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
