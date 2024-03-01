class Solution(object):
    def maximumOddBinaryNumber(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt1 = 0
        cnt0 = 0
        for i in s:
            if i == '1':
                cnt1+=1
            elif i == '0':
                cnt0+=1
                
        return ('1'*(cnt1-1)) + '0'*cnt0 + '1'