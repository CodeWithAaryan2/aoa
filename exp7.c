#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 99999
void floydWarshall(int n, int dist[][n]) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    printf("\nShortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%5s", "INF");
            else
                printf("%5d", dist[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    char temp[20];
    printf("Enter adjacency matrix (use INF for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", temp);  
            if (strcmp(temp, "INF") == 0)
                graph[i][j] = INF;
            else
                graph[i][j] = atoi(temp);
        }
    }
    floydWarshall(n, graph);
    return 0;
}
