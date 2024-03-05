class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        
        while(left < right){
            if(s[left]==s[right]){
                while(s[left]==s[left+1] && left<right)
                    left++;
                while(s[right]==s[right-1] && left<right)
                    right--;
                
                left++;
                right--;
            } else{
                break;
            }
        }
        
        int ans=right-left+1; //ans=remaining array length
        
        return ans<0 ? 0 : ans;
    }
};