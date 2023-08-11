class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        
        for(int i=0; i<prerequisites.size(); i++){
            vector<int> pair;
            pair = prerequisites[i];
            
            indegree[pair[0]]++;
            adjList[pair[1]].push_back(pair[0]);
        }
        
        stack<int> topoStack;
        for(int j=0; j<numCourses; j++){
            if(indegree[j] == 0){
                topoStack.push(j);
            }
        }
        
        while(topoStack.size()){
            int curr = topoStack.top();
            topoStack.pop();
            
            ans.push_back(curr);
            
            vector<int> child = adjList[curr];
            for(int k=0; k<child.size(); k++){
                indegree[child[k]]--;
                if(indegree[child[k]] == 0){
                    topoStack.push(child[k]);
                }
            }
        }
        
        vector<int> empty;
        return accumulate(indegree.begin(), indegree.end(), 0) == 0 ? ans : empty;
    }
};