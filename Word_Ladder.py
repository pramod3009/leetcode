class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        d = {}
        for i in wordList:
            for j in range(0,len(i)):
                word = i[:j]+"*"+i[j+1:]
                a = d.get(word,[])
                a.append(i)
                d[word] = a
        visited ={beginWord:True}
        queue = collections.deque([(beginWord,1)])
        n = len(beginWord)
        while queue:
            curr_word,level = queue.popleft()
            print(curr_word, level)
            for i in range(n):
                word = curr_word[:i]+"*"+curr_word[i+1:]
                for j in d.get(word,[]):
                    if j == endWord:
                        return level+1
                    if j not in visited:
                        visited[j] = True
                        queue.append((j,level+1))
                d[word] = []
        return 0
