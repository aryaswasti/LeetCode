#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //store maximum length od subArray
        int maxLength = 0;
        //sum till current element
        int sum = 0;
        // Maps sum to its first occurrence index
        unordered_map<int, int> sumIndex; 
        
        // Initialize the map with the sum 0 and its index -1
        //this is used when sum encountered is 0
        //and 0 sum means all elements from start of array can be included(-1)
        sumIndex[0] = -1; 

        for (int i = 0; i < nums.size(); ++i) {
            // Convert 0 to -1 and 1 to 1
            sum += (nums[i] == 0) ? -1 : 1;

            //if sum already exists => prev occurance till current element is valid subArray
            if (sumIndex.find(sum) != sumIndex.end()) {
                maxLength = max(maxLength, i - sumIndex[sum]);
            //if sum is encountered for first time => add it to Map
            } else {
                sumIndex[sum] = i;
            }
        }
        
        //return maximum length of valid subArray
        return maxLength;
    }
};
