/*
 * Program  : Adjacency Matrix Representation of Graph
 * Language : C
 */

#include <stdio.h>
#include <stdlib.h>

#define VSIZE 5

typedef struct Graph{
    int V;
    int adj_mat[VSIZE][VSIZE];
} Graph;


// graph initializing
void init(Graph* graph){
    int r,c;
    graph->V=0;
    for(r=0; r<VSIZE; r++)
        for(c=0; c<VSIZE; c++)
           graph->adj_mat[r][c] = 0;
}

// insert Vertex
void insert_vertex(Graph* graph){
    if (((graph->V)+1)>VSIZE){
        printf("Overflow.\n");
        return;
    }
    graph->V++;
}

// insert Edge
void insert_edge(Graph* graph,int start,int end){

    if (start >= graph->V || end >= graph->V) {
        printf("vertex jey error.\n");
        return;
    }
    graph->adj_mat[start][end] = 1;
    graph->adj_mat[end][start] = 1;
}

// print
void print_adj_mat(Graph* graph){
    for (int i=0; i<graph->V; i++){
        for(int j=0; j<graph->V;j++){
            printf("%2d",graph->adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    init(graph);
    for( int i=0; i<4; i++)
       insert_vertex(graph);
    insert_edge(graph,0,1);
    insert_edge(graph,0,2);
    insert_edge(graph,0,3);
    insert_edge(graph,1,2);
    insert_edge(graph,2,3);
    print_adj_mat(graph);
    
    free(graph);
    return 0;
}
