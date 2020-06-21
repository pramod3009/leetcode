import queue
class Solution:
    def bfs(self,graph,start, color, visited):
        q= queue.Queue()
        q.put(start)
        color[start] = 1
        visited[start] = 1
        while not q.empty():
            index = q.get()
            for i in graph[index]:
                if not visited[i]:
                    q.put(i)
                    visited[i] = 1
                    if color[index] == 1:
                        color[i] = 2
                    else:
                        color[i] = 1
                if color[i] == color[index]:
                    return False
        return True
    def isBipartite(self, graph: List[List[int]]) -> bool:
        colors = {}
        
        length = len(graph)
        visited = [0]*length
        for i in range(0,length):
            if visited[i]==0:
                if not self.bfs(graph, i, colors, visited):
                    return False
        return True
        