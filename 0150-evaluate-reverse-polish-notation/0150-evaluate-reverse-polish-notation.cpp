class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> s ;
        
        for(auto &i:tokens)
        { 
            //pop 2 numbers and perform operation
            if(i == "+" || i == "-" || i == "*" || i == "/") // operators 
            {
                long long int op1 = s.top() ; 
                s.pop() ;
                long long int op2 = s.top() ; 
                s.pop() ;
                if(i == "+") 
                    op1 = op2 + op1 ;
                if(i == "-") 
                    op1 = op2 - op1 ;
                if(i == "*") 
                    op1 = op2*op1 ; 
                if(i == "/") 
                    op1 = op2/op1 ;  
                
                //push the answer back to stack
                s.push(op1) ;
            }
            else 
                //store numbers in stack
                s.push(stoll(i)) ; // number -> need to convert from str to int
        }    
        return s.top() ; 
    }
};