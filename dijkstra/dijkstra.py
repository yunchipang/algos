# python program for Dijkstra's single source shortest path algorithm
# this program is for adjacency matrix representation of the graph

class Graph():
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def print_solution(self, dist):
        print("vertex \t distance from source")
        for node in range(self.V):
            print(node, "\t\t", dist[node])
    
    # find the vertex with minimum distance value
    # from the set of vertices not yet included in shortest path tree
    def min_distance(self, dist, spt_set):

        # init minimum distance for next node
        min = 1e7

        # search for nearest vertex not yet in the shortest path tree
        for v in range(self.V):
            if dist[v] < min and spt_set[v] == False:
                min = dist[v]
                min_index = v
        return min_index

    def dijkstra(self, src):
        
        dist = [1e7 for i in range(self.V)]
        dist[src] = 0
        spt_set = [False for i in range(self.V)]

        for i in range(self.V):

            # 1. pick the minimum distance vertex from the set of vertices not yet processed
            # u is always equal to src in first iteration
            u = self.min_distance(dist, spt_set)

            # 2. put the minimum distance vertex in the shortest path tree
            spt_set[u] = True

            # 3. updtae dist value of the adjacent vertices of the picked vertex only if
            # the current distance is greater than new distance and the vertex is not in the shortest path tree
            for v in range(self.V):
                if (self.graph[u][v] > 0 and 
                    spt_set[v]==False and
                    dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]
        
        self.print_solution(dist)

if __name__ == "__main__":
    g = Graph(9)
    g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
                [4, 0, 8, 0, 0, 0, 0, 11, 0],
                [0, 8, 0, 7, 0, 4, 0, 0, 2],
                [0, 0, 7, 0, 9, 14, 0, 0, 0],
                [0, 0, 0, 9, 0, 10, 0, 0, 0],
                [0, 0, 4, 14, 10, 0, 2, 0, 0],
                [0, 0, 0, 0, 0, 2, 0, 1, 6],
                [8, 11, 0, 0, 0, 0, 1, 0, 7],
                [0, 0, 2, 0, 0, 0, 6, 7, 0]]
    g.dijkstra(0)
