class Solution {
public:
    int firstUniqChar(string s) {
        //vector storing 1-26(a-z) index as count of all letters
        vector<int> letters(26, 0);
        
        //insert char and their count into map 
        for(char c : s){
            letters[c-'a']++;
        }
        
        //iterate over string
        for(int i=0; i<s.size(); i++){
            //return position of first char with only 1 occurance
            if(letters[s[i]-'a'] == 1){
                return i;
            }
        }
        
        //in case of no unique characters
        return -1;
    }
};