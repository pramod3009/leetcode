class Solution:
    result = []
    d = {"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
    def helper(self, index, size, digits,string, s_size):
        if(size==s_size):
            self.result.append(string[::])
            return
        for i in range(index,size):
            #print(self.d[digits[i]])
            for j in self.d[digits[i]]:
                self.helper(i+1,size,digits,string+j,s_size+1)
                self.helper(i+1,size,digits,string,s_size)
    def letterCombinations(self, digits: str) -> List[str]:
        if not len(digits):
            return []
        self.result = []
        self.helper(0,len(digits),digits,"",0)
        return self.result
        
        