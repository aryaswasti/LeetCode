class Solution {
public:
    int DFS(int curr, vector<vector<int>>& adjList, vector<int>& informTime) {
        if(adjList[curr].size() == 0) {
            return 0;
        }
        
        int maxTime = 0;
        for(int i = 0; i<adjList[curr].size(); i++) {
            maxTime = max(maxTime, DFS(adjList[curr][i], adjList, informTime));
        }
        return maxTime+informTime[curr];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {        
        vector<vector<int>> adjList(n);

        for(int i=0; i<n; i++) {
            if(manager[i] != -1)
                adjList[manager[i]].push_back(i);
        }

        return DFS(headID, adjList, informTime);
    }
};