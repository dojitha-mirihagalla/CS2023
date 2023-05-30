#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX // Infinity

// Structure to represent a vertex and its distance from the source
struct Vertex {
    int index;
    int distance;

    Vertex(int i, int d) : index(i), distance(d) {}
};

// Comparison operator for the priority queue (min-heap)
struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.distance > v2.distance;
    }
};

// Dijkstra's algorithm for finding shortest paths
std::vector<int> dijkstraShortestPaths(std::vector<std::vector<int>>& graph, int source) {
    int V = graph.size(); // Number of vertices
    std::vector<int> distances(V, INF); // Array to store the shortest distance values
    std::vector<bool> visited(V, false); // Array to track visited vertices

    distances[source] = 0; // Distance from source to itself is 0

    // Priority queue (min-heap) to store vertices with their distances
    std::priority_queue<Vertex, std::vector<Vertex>, CompareVertex> pq;
    pq.push(Vertex(source, 0));

    while (!pq.empty()) {
        int u = pq.top().index;
        pq.pop();

        // Skip if the vertex has already been visited
        if (visited[u])
            continue;

        visited[u] = true;

        // Iterate through all adjacent vertices of u
        for (int v = 0; v < V; v++) {
            // Update the distance if there is a shorter path
            if (!visited[v] && graph[u][v] != INF &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                pq.push(Vertex(v, distances[v]));
            }
        }
    }

    // Print the shortest distance values1
    
    return distances;
}

int main() {
    // Example graph represented by the adjacency matrix
    std::vector<std::vector<int>> graph = {
        {0, 10,INF, INF,15,5},
        {10, 0,10, 30, INF, INF},
        {INF,10, 0, 12, 5, INF},
        {INF, 30, 12, 0, INF, 20},
        {15, INF, 5, INF, 0, INF},
        {5, INF, INF, 20, INF, 0}
    };


    std::vector<float> avg_times;

  for (int node=0;node<6;node++){
    int tot =0;
    for (int source=0;source<6;source++){
        std::vector<int> dis = dijkstraShortestPaths(graph, source);
        tot+=dis[node];
    }
    std::cout<<"Node "<<node << " -> Avg time " << tot/5.0<<std::endl;
    avg_times.push_back(tot/5.0);
    
  }
    
 
   

return 0;
}