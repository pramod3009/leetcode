class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for i in strs:
            word = ''.join(sorted(i))
            if d.get(word,0):
                d[word].append(i)
            else:
                d[word] = [i]
        return list(d.values())        
                
        