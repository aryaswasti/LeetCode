class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        string ans;
        stack<int> tmp;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')
                tmp.push(i);
            else if(s[i]==')'&&!tmp.empty()&&s[tmp.top()]=='(')
                tmp.pop();
            else if(s[i]==')')
                tmp.push(i);
        }
        for(int i=s.size()-1;i>=0;--i)
        {
            if(!tmp.empty()&&tmp.top()==i)
                tmp.pop();
            else
                ans+=s[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};