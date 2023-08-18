class Solution {
public:
    pair<int, int> getCord(int num, int n){
        int row = (num - 1) / n;
        int col = (num - 1) % n;

        if(row % 2 != 0){
            col = n - 1 - col; 
        }

        return {row, col}; 
    }


    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        reverse(board.begin(), board.end());

        set<int> visited;
        queue<pair<int, int>> q;

        q.push({1, 0});

        while(q.size()){
            pair<int, int> curr = q.front();
            q.pop();

            for(int i=1; i<=6; i++){
                int next = curr.first + i;
                pair<int,int> nextCord = getCord(next, n);

                if(board[nextCord.first][nextCord.second] != -1){
                    next = board[nextCord.first][nextCord.second];
                }
                if(next == n*n){
                    return curr.second + 1;
                }
                if(visited.find(next) == visited.end()){
                    visited.insert(next);
                    q.push({next, curr.second + 1});
                }

            }
        }

        return -1;
    }
};