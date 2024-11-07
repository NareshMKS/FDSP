#include <stdio.h>
#include <limits.h>

#define bool int
#define true 1
#define false 0
#define V 9

// Function to find the vertex with the minimum distance
int minDistance(int dist[], bool sptSet[]) {
    int v;
    int min = INT_MAX, min_index;
    for (v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v]; 
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the solution
void printSolution(int dist[]) {
    int i;
    printf("Vertex \t\t Distance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%d \t\t\t %d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm to find the shortest path
void dijkstra(int graph[V][V], int src) {
    int i, v, count;
    int dist[V];
    bool sptSet[V];

    // Initialize all distances to infinity and sptSet as false
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); // Find the vertex with minimum distance
        sptSet[u] = true; // Mark the picked vertex as processed

        // Update the distance of the adjacent vertices of the picked vertex
        for (v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the final shortest distance
    printSolution(dist);
}

int main() {
    // Create the example graph
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    clrscr();

    // Call Dijkstra's algorithm with source vertex 0
    dijkstra(graph, 0);
    getch();
    return 0;
}
