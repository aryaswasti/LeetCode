class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) 
            return 0;
        
        vector<vector<int>> dir {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int count = 0;
        
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col] == '1') {
                    count++;
                    grid[row][col] = '0';
                    
                    vector<int> idx;
                    queue<vector<int>> q;
                    q.push({row, col});
                    
                    while(q.size()) {
                        idx = q.front();
                        q.pop();
                        
                        for(int i = 0; i < dir.size(); i++) {
                            vector<int> curr = dir[i];

                            int nextRow = idx[0] + curr[0];
                            int nextCol = idx[1] + curr[1];
                            
                            if(nextRow < 0 || nextCol < 0 || nextRow >= grid.size() || nextCol >= grid[0].size()) 
                                continue; 
                            if (grid[nextRow][nextCol] == '1'){
                                grid[nextRow][nextCol] = '0';
                                q.push({nextRow, nextCol});                                
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};