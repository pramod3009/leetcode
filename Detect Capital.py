class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        n = len(word)
        if n<=1:
            return True
        all_caps = False
        all_small = False
        first_caps = False
        if word[0].isupper() and word[1].isupper():
            all_caps = True
        elif word[0].isupper():
            first_caps = True
        else:
            all_small = True
        
        for i  in range(1,n):
            if (all_caps and word[i].islower()) or (all_small and word[i].isupper()) or (first_caps and word[i].isupper()): 
                return False
            
        return True