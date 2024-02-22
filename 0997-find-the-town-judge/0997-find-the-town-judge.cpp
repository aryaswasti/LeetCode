class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ans(n+1, 0);
             
        for(auto person : trust){
            ans[person[0]]--;
            ans[person[1]]++;
        }
        
        for(int i=1; i<ans.size(); i++){
            if(ans[i] == n-1){
                return i;
            }
        }
        
        return -1;
    }
};