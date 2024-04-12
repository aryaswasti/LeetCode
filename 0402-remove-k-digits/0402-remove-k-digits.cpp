class Solution {
public:
    string removeKdigits(string num, int k) {
        //used to store string characters
        vector<char> stk;
        //final answer
        string ans;
        
        for(char c :num){
            //k>0 => elements to be removed(k) is > 0
            //stk != empty => can't remove elements from empty stk
            while(k>0 && !stk.empty() && stk.back()>c){
                //Last seen element of stack(stk.back()) > Current element(c)
                //Remove greater element
                stk.pop_back();
                //reduce number of element to be removed
                k--;
            }
            
            //Current element is < Last seen
            //Add to stk
            stk.push_back(c);
        }
        
        //if k still > 0
        while(k>0){
            //remove last elements
            stk.pop_back();
            k--;
        }
        
        //make enter str => ans
        for(char c : stk){
            //ans.empty => to check if we encounter first element
            //skip '0' if first element
            if(ans.empty() && c=='0') continue;
            //else add to ans
            ans.push_back(c);

        }
        
        //return ans
        //if ans is empty => return 0
        return ans.empty()?"0":ans ;
    }
};