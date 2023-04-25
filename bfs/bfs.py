# python program to print BFS traversal for complete graph
from collections import defaultdict

class Graph:
    
    def __init__(self):
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.visited=[]
    
    def bfs(self, s):
        queue = []
        # add the current vertex to visited and enqueue it
        queue.append(s)
        self.visited.append(s)

        while queue:
            s = queue.pop(0)
            print(s, end=" ")

            # get all adjacent vertices of the current vertex
            # if a adjacent vertex has not been visited, add it to visited and enqueue it
            for i in self.graph[s]:
                if i not in self.visited:
                    queue.append(i)
                    self.visited.append(i)


if __name__ == "__main__":
    g = Graph()
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(2, 0)
    g.add_edge(2, 3)
    g.add_edge(3, 3)

    print("BFS traversal: ")
    g.bfs(2)