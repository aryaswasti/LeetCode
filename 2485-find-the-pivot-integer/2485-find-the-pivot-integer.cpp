class Solution {
public:
    int pivotInteger(int n) {
        int left = (n*(n+1))/2;
        int right = 0;
        
        for(int i=n; i>=1; i--){
            right+=i;
            if(left == right){
                return i;
            } 
            left-=i;
        }
        
        return -1;
    }
};