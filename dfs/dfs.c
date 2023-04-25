/*
 * Program  : Depth First Search of Graph
 * Language : C
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define VSIZE 50

typedef struct Graph{
    int V;
    int adj_mat[VSIZE][VSIZE];
}Graph;

int visited[VSIZE];

void init(Graph* graph){
    int r,c;
    graph->V=0;
    for(r=0; r<VSIZE; r++)
        for(c=0; c<VSIZE; c++)
            graph->adj_mat[r][c] = 0;
}

void insert_vertex(Graph* graph){
    if(((graph->V)+1)>VSIZE){
        printf("Overflow.\n");
        return;
    }
    graph->V++;
}


void insert_edge(Graph* graph, int start, int end){
    if(start>=graph->V || end>=graph->V){
        printf("Vertex index error.\n");
        return;
    }
    graph->adj_mat[start][end] = 1;
    graph->adj_mat[end][start] = 1;
}

void dfs_mat(Graph* graph,int v){
    visited[v] = TRUE;
    printf("visit %d ->  ", v);

    for (int w=0; w<graph->V; w++) {
        if (graph->adj_mat[v][w] && !visited[w]) {
            dfs_mat(graph, w);
        }
    }
}


int main(void){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    init(graph);
    for(int i=0;i<7;i++)
        insert_vertex(graph);

    insert_edge(graph, 0, 1);
    insert_edge(graph, 0, 2);
    insert_edge(graph, 1, 3);
    insert_edge(graph, 1, 4);
    insert_edge(graph, 2, 5);
    insert_edge(graph, 2, 6);

    printf("DFS\n");
    dfs_mat(graph, 0);
    printf("\n");
    free(graph);
    return 0;
}
