/*
 * Program  : Adjacency List Representation of Graph
 * Language : C
 */
#include <stdio.h>
#include <stdlib.h>

#define VSIZE 5

typedef struct GraphNode{
    int vertex;
    struct GraphNode* next;
} GraphNode;

typedef struct Graph{
    int V;
    GraphNode* adj_list[VSIZE];
} Graph;

// graph initializing
void init(Graph* graph){
    int v;
    graph->V = 0;
    for(v=0; v<VSIZE; v++)
        graph->adj_list[v]=NULL;
}

// insert vertex
void insert_vertex(Graph* graph){
    if(((graph->V)+1)>VSIZE){
        printf("Overflow.\n");
        return;
    }
    graph->V++;
}

void insert_edge(Graph* graph, int u, int v){

    GraphNode* node;
    if (u >= graph->V || v >= graph->V) {
        printf("vertex index error.\n");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->next = graph->adj_list[u];
    graph->adj_list[u] = node;
}

void print_adj_list(Graph* graph){
    for(int i=0; i<graph->V; i++){
        GraphNode* p = graph->adj_list[i];
        printf("Vertex %d adjecnt list", i);
        while(p != NULL){
            printf(" -> %d",p->vertex);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    init(graph);
    for(int i=0;i<4;i++)
        insert_vertex(graph);
    insert_edge(graph,0,1);
    insert_edge(graph,1,0);
    insert_edge(graph,0,2);
    insert_edge(graph,2,0);
    insert_edge(graph,0,3);
    insert_edge(graph,3,0);
    insert_edge(graph,1,2);
    insert_edge(graph,2,1);
    insert_edge(graph,2,3);
    insert_edge(graph,3,2);
    print_adj_list(graph);

    free(graph);

    return 0;


}
