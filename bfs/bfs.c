/*
 * Program  : Breadth First Search of Graph
 * Language : C
 */
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define QUEUE_SIZE 10
#define VSIZE 10

// typedef int element;

typedef struct Queue{
    int arr[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

typedef struct Graph{
    int V;
    int adj_mat[VSIZE][VSIZE];
} Graph;

void queue_init(Queue *q){
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue *q){
    return (q->front == q->rear);
}

int is_full(Queue *q){
    return ((q->rear+1)%QUEUE_SIZE == q->front);
}

void enqueue(Queue *q, int item){
    if(is_full(q))
        printf("Overflow.\n");
    q->rear = (q->rear+1)%QUEUE_SIZE;
    q->arr[q->rear] = item;
}

int dequeue(Queue *q){
    if(is_empty(q))
        printf("Underflow.\n");
    q->front=(q->front+1)%QUEUE_SIZE;
    return q->arr[q->front];
}

int visited[VSIZE];

void graph_init(Graph* graph){
    int r,c;
    graph->V = 0;
    for(r=0; r<VSIZE; r++)
        for(c=0; c<VSIZE; c++)
            graph->adj_mat[r][c] = 0;
}

void insert_vertex(Graph* graph){
    if((graph->V)+1 > VSIZE) {
        printf("Overflow.\n");
        return;
    }
    graph->V++;
}

void insert_edge(Graph* graph, int start, int end){
    if(start>=graph->V||end>=graph->V){
        printf("Graph index error.\n");
        return;
    }
    graph->adj_mat[start][end] = 1;
    graph->adj_mat[end][start] = 1;
}

void bfs_mat(Graph* graph, int v){
    int w;
    Queue q;

    // Add your code here
    queue_init(&q);
    visited[v] = TRUE;
    printf("visit %d -> ", v);
    enqueue(&q, v);

    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (w=0; w<graph->V; w++) {
            if (graph->adj_mat[v][w] && !visited[w]) {
                visited[w] = TRUE;
                printf("visit %d -> ", w);
                enqueue(&q, w);
            }
        }
    }
}

int main(void){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph_init(graph);
    for(int i=0; i<7; i++)
        insert_vertex(graph);

    insert_edge(graph, 0, 1);
    insert_edge(graph, 0, 2);
    insert_edge(graph, 1, 3);
    insert_edge(graph, 1, 4);
    insert_edge(graph, 2, 5);
    insert_edge(graph, 2, 6);

    printf("BFS\n");
    bfs_mat(graph, 1);
    printf("\n");
    free(graph);
    return 0;

}
