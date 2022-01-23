
class MyQueue 
{
    constructor() 
    {
        this.in = [];
        this.out = [];
    }
    
    push(x) 
    {
        this.in.push(x);
    }
    
    pop() 
    {
        if(this.out.length === 0)
        {
            while(this.in.length > 0)
            {
                this.out.push(this.in.pop());
            }
        }
        
        return this.out.pop();
    }
    
    peek()
    {
        if(this.out.length > 0)
            return this.out[this.out.length - 1];
        else
            return this.in[0];
    }
    
    empty()
    {
        return (this.in.length === 0 && this.out.length === 0);
    }
};