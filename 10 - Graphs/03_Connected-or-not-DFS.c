#include<stdio.h>

int graph[10][10];
int visited[10];
int v;

void DFS(int node) {
    visited[node] = 1;
    for(int j=0;j<v;j++) {
        if(graph[node][j] && !visited[j]) {
            DFS(j);
        }
    }
}

int is_connected() {
    for(int i=0;i<v;i++) {
        visited[i] = 0;
    }
    DFS(0);
    for(int i=0;i<v;i++) {
        if(!visited[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("\nEnter no of vertices: ");
    scanf("%d", &v);
    printf("\nEnter adjacency matrix of the graph: ");
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nGiven adjacency matrix:\n");
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            printf("%4d", graph[i][j]);
        }
        printf("\n");
    }
    if(is_connected()) {
        printf("\nThe graph is connected");
    } else {
        printf("\nThe graph is not connected");
    }
}