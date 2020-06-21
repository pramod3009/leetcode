class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        if k >= len(s):
            return s[::-1]
        result = ""
        i=0
        flag1 = 0
        flag2 = 0
        while i <= len(s):
            if i + k <= len(s):
                result += s[i:i+k][::-1] 
                i=i+k
                if i+k<=len(s):
                    result +=s[i:i+k]
                    i = i + k
                else:
                    flag2 = 1
                    break
            else:
                flag1 = 1
                break
            
        if flag1:
            result+=s[i:][::-1]
        elif flag2:
            result+=s[i:]
        return result    