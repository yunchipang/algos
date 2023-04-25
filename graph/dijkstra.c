#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define VSIZE 100	
#define INF 1000000     // not connected -> inf (big enough num)	

typedef struct Graph {
	int V;	
	int weight_mat[VSIZE][VSIZE];   // adj matrix with weights
} Graph;

int distance[VSIZE];                    // shortest distance from u 
int visited[VSIZE];	                // visited: True

// get mininum distance idx
int getSmallIdx(int distance[], int n, int visited[])
{
    int i, min, minidx;
    min = INT_MAX;                      // INT_MAX: inf integer
    minidx = -1;

    for (i = 0; i < n; i++) {
        if (distance[i] < min && !visited[i]) {
            min = distance[i];
            minidx = i;
        }
    }
    return minidx;
}

void print_status(Graph* graph)
{
    static int step = 1;
    printf("STEP %d: ", step++);
    printf("distance: ");
    for (int i = 0; i < graph->V; i++) {
        if (distance[i] == INF)
            printf(" * ");
	else
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf("        visited:  ");
    for (int i = 0; i < graph->V; i++)
        printf("%2d ", visited[i]);
    printf("\n\n");
}

// Dijkstra algorithm
void dijkstra(Graph * graph, int start)
{
    int i, u, w;

    for (i = 0; i < graph->V; i++) {      // initialing
        distance[i] = graph->weight_mat[start][i];
        visited[i] = FALSE;
    }

    visited[start] = TRUE;                // starting V: True
    distance[start] = 0;                  // distance: 0

    for (i = 0; i < graph->V - 1; i++) {
        print_status(graph);
        u = getSmallIdx(distance, graph->V, visited);
        visited[u] = TRUE;

        for (w = 0; w < graph->V; w++) {
            if (!visited[w])
                if (distance[u] + graph->weight_mat[u][w] < distance[w])
                    distance[w] = distance[u] + graph->weight_mat[u][w];
        }
    }
}

int main(void)
{
    Graph graph = { 7,
        {{   0,   7, INF, INF,   3,  10, INF },
         {   7,   0,   4,  10,   2,   6, INF },
         { INF,   4,   0,   2, INF, INF, INF },
         { INF,  10,   2,   0,  11,   9,   4 },
         {   3,   2, INF,  11,   0, INF,   5 },
         {  10,   6, INF,   9, INF,   0, INF },
         { INF, INF, INF,   4,   5, INF,   0 }}
    };

    dijkstra(&graph, 0);
    return 0;
}
