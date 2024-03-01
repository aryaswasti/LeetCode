class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int left = 0;
        int right = s.size()-1;
        
        while(left <= right){
            if(s[left] == '1'){
                left++;
            } 
            if(s[right] == '0'){
                right--;
            }
            if(s[left] == '0' && s[right] == '1'){
                s[left] = '1';
                s[right] = '0';
                left++;
                right--;
            }
        }
        
        //swap last '1' with last digit
        char temp = s[left-1];
        s[left-1] = s[s.size()-1];
        s[s.size()-1] = temp;
        
        return s;
    }
};