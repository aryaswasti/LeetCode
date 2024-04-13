class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int mx = 0;
        int n = heights.size();
        
        for(int i=0; i<=n; i++){
            while(!s.empty() && (i==n || heights[s.top()] >= heights[i])){
                int height = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()) 
                    width = i;
                else 
                    width = i-s.top()-1;
                
                mx = max(mx, height*width);
            }
            s.push(i);
        }
        
        return mx;
    }
};