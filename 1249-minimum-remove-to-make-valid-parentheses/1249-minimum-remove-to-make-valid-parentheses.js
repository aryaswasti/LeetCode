/**
 * @param {string} s
 * @return {string}
 */
var minRemoveToMakeValid = function(s) {
    const stack = [];
    let arr = s.split('');
    
    for(let p = 0; p < s.length; p++)
    {
        if(arr[p] === '(')
        {
            stack.push(p);    
        }
        else if(arr[p] === ')')
        {
            let leftBracket = stack.pop();
            if(leftBracket === undefined)
                {
                    arr[p] = '';
                }
        }
    }
    
    if(stack.length !== 0)
    {
        for(let i=0; i < stack.length; i++)
            {
                arr[stack[i]] = '';    
            }
    }
    
    s = arr.join('');
    
    return s;
};