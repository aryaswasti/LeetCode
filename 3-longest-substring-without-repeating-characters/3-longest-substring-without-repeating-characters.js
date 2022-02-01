/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let i=0, j=0, maxLen=0, subLen=0;
    let n=s.length;
    let seenChar = [];
    
    if(n===0) {
        return n;
    }
    while (i<n && j<n) {
        if (!seenChar.includes(s[j])){
            seenChar.push(s[j]);
            j++;
            subLen = seenChar.length;
            maxLen = Math.max(maxLen, subLen);
        } else {
            i++;
            j=i;
            seenChar = [];
        }
    }
    return maxLen;
}