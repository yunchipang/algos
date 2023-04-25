# python program to print DFS traversal for complete graph
from collections import defaultdict

class Graph:
    
    def __init__(self):
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        self.graph[u].append(v)
    
    def dfs_util(self, v, visited):
        # mark the current vertex as visited and print it
        visited[v] = True
        print(v, end=" ")

        # recur for all adjacent vertices of the current vertex
        for i in self.graph[v]:
            if not visited[i]:
                self.dfs_util(i, visited)
            
    def dfs(self):
        V = len(self.graph) # total number of vertices
        visited = [False for i in range(V)]
        for i in range(V):
            if not visited[i]:
                self.dfs_util(i, visited)


if __name__ == "__main__":
    g = Graph()
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(2, 0)
    g.add_edge(2, 3)
    g.add_edge(3, 3)
    
    print("DFS traversal:")
    g.dfs()