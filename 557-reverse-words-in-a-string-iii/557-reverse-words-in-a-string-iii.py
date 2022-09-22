def reverseWord(s):
    revS = ""
        
    for char in s:
        revS = char + revS
            
    return revS

class Solution(object):
    
    
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = s.split(" ")
        
        newS = " "
        for i in range(len(l)):
            l[i] = reverseWord(l[i]);
        
        return newS.join(l, )
        
        