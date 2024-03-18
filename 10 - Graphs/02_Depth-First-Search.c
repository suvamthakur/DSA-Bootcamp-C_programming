#include<stdio.h>

#define N 5
int visited[N] = {0,0,0,0,0};
int graph[N][N] = {
        {0,1,0,0,1},
        {1,0,1,0,0},
        {0,0,0,1,0},
        {1,1,1,0,0},
        {0,1,0,1,0}
};

void DFS(int node) {
    printf("%4d", node);
    visited[node] = 1;
    for(int j=0;j<N;j++) {
        if(graph[node][j] && !visited[j]) {
            DFS(j);
        }
    }
}

int main() {
    int s;
    printf("\nEnter source node: ");
    scanf("%d", &s);
    DFS(s);
}