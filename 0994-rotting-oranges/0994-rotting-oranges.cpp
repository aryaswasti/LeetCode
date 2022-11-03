class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0) 
            return -1;
        
        vector<vector<int>> dir {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int countFresh = 0;
        int min = 0;
        vector<int> idx;
        queue<vector<int>> q;
        
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col] == 1) 
                    countFresh++;
                if(grid[row][col] == 2) 
                    q.push({row, col});
            }
        }
        
        int level = q.size();
                    
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {   
                while(q.size()) { 
                    if(level == 0) {
                        level = q.size();
                        min++;
                    }

                    idx = q.front();
                    q.pop();
                    level--;

                    for(int i = 0; i < dir.size(); i++) {
                        vector<int> curr = dir[i];

                        int nextRow = idx[0] + curr[0];
                        int nextCol = idx[1] + curr[1];

                        if(nextRow < 0 || nextCol < 0 || nextRow >= grid.size() || nextCol >= grid[0].size()) 
                            continue; 
                        if(grid[nextRow][nextCol] == 1){
                            grid[nextRow][nextCol] = 2;
                            q.push({nextRow, nextCol});
                            countFresh--;
                        }
                        
                        queue<vector<int>> temp = q;
                    }
                }
                
            }
        }
        return countFresh > 0 ? -1 : min;
    }
};