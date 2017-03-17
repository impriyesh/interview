#include <iostream>
using namespace std;

// A C Program to demonstrate adjacency list representation of graphs

#include <stdio.h>
#include <stdlib.h>

struct adjNode {
    int dest;
    struct adjNode * next;
};

struct adjList {
    struct adjNode * head;
};

struct Graph {
    int V;
    struct adjList * array;
};

struct adjNode * createadjNode(int v){

    struct adjNode * newNode = (struct adjNode *) malloc (sizeof(struct adjNode));
    newNode->dest =v;
    newNode->next =NULL;
    return newNode;

};

struct Graph * createGraph(int v){

    struct Graph* graph= (struct Graph *) malloc (sizeof(struct Graph));
    graph->V = v;
    graph->array = (struct adjList *) malloc(v * sizeof(struct AdjList*));
    for(int i =0;i<v ;i++)
        graph->array[i].head=NULL;
    return graph;

};

void addEdge(struct Graph *graph,int src,int dest) {

//set src to dest
        struct adjNode * newNode = createadjNode(dest);
        newNode->next=graph->array[src].head;
        graph->array[src].head=newNode;

        newNode = createadjNode(src);
        newNode->next=graph->array[dest].head;
        graph->array[dest].head=newNode;

}

void printGraph(struct Graph * graph){

    struct adjNode *tmp;
    for(int i=0;i<graph->V;i++){
            cout <<i;
            tmp = graph->array[i].head;
        while(tmp!=NULL){
                cout << "--";
                cout << tmp->dest;
                tmp=tmp->next;

        }
    cout << "\n";
    }
}


// Driver program to test above functions

//0---1
//|    ---2
//4---3
int main()
{
    // create the graph given in above figure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}





