class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        if not len(folder):
            return []
        folder.sort()
        result = []
        current = folder[0]
        result.append(current)
        for i in range(1,len(folder)):
            if current+"/" in folder[i]:
                continue
            else:
                result.append(folder[i])
                current = folder[i]
        return result
        
        
