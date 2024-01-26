class Solution {
public:
    int MOD = 1e9 + 7;
    int memo[51][51][51];
    int solve(int row, int col, int m, int n, int move){
        //since we start from 0, m and n will be out of bounds. Hence = is put
        if(row >= m || row < 0 || col >= n || col < 0){
            //only one move needed to go out of bound
            return 1;
        }
        
        //if no moves left
        if(move == 0){
            return 0;
        }
        
        
        if(memo[row][col][move] != -1 ) 
            return memo[row][col][move];
        
        int top = solve(row + 1, col, m, n, move-1);
        int bottom = solve(row - 1, col, m, n, move-1);
        int left = solve(row, col + 1, m, n, move-1);
        int right = solve(row, col - 1, m, n, move -1);
        
        memo[row][col][move] = ((top%MOD + bottom%MOD)%MOD + (left%MOD + right%MOD)%MOD)%MOD;
        
        return memo[row][col][move];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo, -1, sizeof(memo));
        return solve(startRow, startColumn, m, n, maxMove);
    }
};