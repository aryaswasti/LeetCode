class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        
        while(left != right){
            left>>=1;
            right>>=1;
            count++;
        }
        
        return left<<count;
    }
};

//O(n) - TLE
// int ans = left;
        
// while(left <= right){
//     ans = int(ans & left);
//     left++;
// }
        
// return ans;