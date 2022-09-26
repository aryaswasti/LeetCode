class Solution {
public:
    void swap(int &num1, int &num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        
        for(int j=0; j<nums.size(); j++) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int end = nums.size()-1;
        
//         while(end > 0) {
//             if(nums[end] != 0)
//                 break;
//             end--;
//         }
        
//         int i = 0;
        
//         while(i<nums.size() && i!=end) {
//             if(nums[i] == 0) {
//                 nums.erase(nums.begin() + i);
//                 nums.push_back(0);
//                 i--;
//                 end--;
//             } 
//             i++;
//         }
//     }
// };

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         vector<int> ans;
//         int zeros = 0;
        
//         for(int i=0; i<nums.size(); i++) {
//             if(nums[i] != 0)
//                 ans.push_back(nums[i]);
//             else if(nums[i] == 0)
//                 zeros++;        
//         }
        
//         while(zeros>0) {
//             ans.push_back(0);
//             zeros--;
//         }
//         nums = ans;
//     }
// };