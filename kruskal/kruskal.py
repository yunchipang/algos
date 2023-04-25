# python program for kruskal's algorithm to find mininum spanning tree
# of a given connected, undirected and weighted graph

class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = []
    
    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])

    # find set of an element i (path compression)
    def find(self, parent, i):
        if parent[i] != i:
            # re-assign node's parent
            parent[i] = self.find(parent, parent[i])
        return parent[i]
    
    # union of 2 sets x and y (union by rank)
    def union(self, parent, rank, x, y):

        # attach the smaller rank tree under root of the higher rank tree 
        if rank[x] < rank[y]:
            parent[x] = y
        elif rank[x] > rank[y]:
            parent[y] = x

        # if ranks are same, make one as root and increment its rank by 1
        else:
            parent[y] = x
            rank[x] += 1
    
    # main function which constract a MST using kruskal's algorithm
    def kruskal(self):
        result = []
        i, j = 0, 0 # i=index for sorted edges, j=index for result[]

        # sort all edges in non-descreasing order of their weight
        self.graph = sorted(self.graph, key=lambda item: item[2])
        
        # init parent and rank arrays
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        
        # iterate through all node (number of edges are V-1)
        while j < self.V-1:

            # pick the smallest edge increment
            u, v, w = self.graph[i]
            i += 1
            x = self.find(parent, u)
            y = self.find(parent, v)

            # if including this edge does not cause cycle
            # then include it in result and increment the index of result
            if x != y:
                j += 1
                result.append([u, v, w])
                self.union(parent, rank, x, y)
            # else discard the edge
        
        min_cost = 0
        print("edges in the constrcuted MST:")
        for u, v, weight in result:
            min_cost += weight
            print("%d -- %d == %d"  % (u, v, weight))
        print("cost of minimum spanning tree = ", min_cost)


if __name__ == '__main__':
    g = Graph(4)
    g.add_edge(0, 1, 10)
    g.add_edge(0, 2, 6)
    g.add_edge(0, 3, 5)
    g.add_edge(1, 3, 15)
    g.add_edge(2, 3, 4)
 
    g.kruskal()