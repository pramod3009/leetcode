class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(" ")
        if len(words)==0:
            return -1
        for i in range(0, len(words)):
            if words[i].find(searchWord)==0:
                return i + 1
        return -1
        
