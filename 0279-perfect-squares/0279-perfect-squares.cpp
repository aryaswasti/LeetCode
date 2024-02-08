class Solution {
public:
    int numSquares(int n) {
        // store result from 0-n
        vector<int> dp(n+1, INT_MAX);
        //base case for n = 0 is 0
        dp[0] = 0;
        
        //for n = i, we will check for sum of squares
        for(int i=1; i<=n; i++){
            //dp[i - j*j ] => we are getting value of number of squares needed to make sum i-j*j 
            //+ 1 => means we are adding a square to sum of i-j*j
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        //return count of sum 'n'
        return dp[n];
    }
};