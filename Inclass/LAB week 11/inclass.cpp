#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

// number of vertices in the graph
#define V 6

// create a 2d array of size VxV for adjacency matrix to represent the graph
int graph[V][V] = {
{0, 3, 0, 0, 0, 1},
{3, 0, 2, 1, 10, 0},
{0, 2, 0, 3, 0, 5},
{0, 1, 3, 0, 5, 0},
{0, 10, 0, 5, 0, 4},
{1, 0, 5, 0, 4, 0}
};

int main() {
int no_edges; // number of edges
// create an array to track selected vertices
// selected will become true if a vertex is selected, otherwise false
bool selected[V];

// set all vertices as unselected initially
memset(selected, false, sizeof(selected));

// set number of edges to 0
no_edges = 0;

int startVertex;
cout << "Enter the starting node: ";
cin >> startVertex;

// choose the starting vertex and mark it as selected
selected[startVertex] = true;

int currentVertex;  // current vertex
int nextVertex;     // next vertex

// print the selected edges and their weights
cout << "Edge : Weight" << endl;
while (no_edges < V - 1) {
    int minWeight = INF;
    currentVertex = 0;
    nextVertex = 0;

    // For every vertex in the selected set, find all adjacent vertices
    // and calculate the weight from the current vertex.
    // If the vertex is already in the selected set, discard it, otherwise
    // choose the vertex with the minimum weight among the unselected vertices.

    for (int i = 0; i < V; i++) {
        if (selected[i]) {
            for (int j = 0; j < V; j++) {
                if (!selected[j] && graph[i][j]) {  // not selected and there is an edge
                    if (minWeight > graph[i][j]) {
                        minWeight = graph[i][j];
                        currentVertex = i;
                        nextVertex = j;
                    }
                }
            }
        }
    }
    
    // Print the selected edge and its weight
    cout << currentVertex << " - " << nextVertex << " : " << graph[currentVertex][nextVertex] << endl;

    // Mark the next vertex as selected and increment the number of edges
    selected[nextVertex] = true;
    no_edges++;
}

return 0;
}