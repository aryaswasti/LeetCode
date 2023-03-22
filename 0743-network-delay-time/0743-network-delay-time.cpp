class Solution {
public:
    struct CompareFirst {
      bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) {
        return p1.first > p2.first;
      }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n, vector<pair<int,int>>{});
        
        int startNode, endNode, time;
        
        vector<int> minTime(n, INT_MAX);   
        minTime[k-1] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, CompareFirst> q;
        q.push({k-1, 0});
        
        for(int i = 0; i < times.size(); i++) {
            startNode = times[i][0]-1;
            endNode = times[i][1]-1;
            time = times[i][2];
            
            pair<int, int> temp(endNode, time);
            adjList[startNode].push_back(temp);
        }
        
        while(!q.empty()){
            pair<int, int> currentNode = q.top();
            q.pop();
            int currTime = currentNode.second;
            vector<pair<int, int>> adjacentNodes = adjList[currentNode.first];
            
            for(int i=0; i<adjacentNodes.size(); i++){
                int nextNode = adjacentNodes[i].first;
                int timeNode = adjacentNodes[i].second;
                
                if(currTime + timeNode < minTime[nextNode]){
                    minTime[nextNode] = currTime + timeNode;
                    q.push({nextNode, currTime + timeNode});
                }
            }
        }
        
        int max = *max_element(minTime.begin(), minTime.end());
        
        return max == INT_MAX ? -1 : max;
    }
};