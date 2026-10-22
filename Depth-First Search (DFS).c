#include <stdio.h>
        do {
            swapped = 0;
            ptr1 = adjList[i];
            
            while (ptr1->next != lptr) {
                if (ptr1->vertex > ptr1->next->vertex) {
                    // Swap vertex data
                    int temp = ptr1->vertex;
                    ptr1->vertex = ptr1->next->vertex;
                    ptr1->next->vertex = temp;
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
	}
    
}

// Depth-First Search (DFS) function
void DFS(int start) {
    //write your code here...
         visited[start] = 1;
    printf("%d ", start);
    
    Node* temp = adjList[start];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            DFS(connectedVertex);
        }
        temp = temp->next;

	}    
}

int main() {
    int V, E;
    int u, v, start;

    // Read number of vertices and edges
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Read the edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort the adjacency list for each vertex
    sortAdjList(V);

    // Read the starting node
    scanf("%d", &start);

    // Perform DFS starting from the given node
    DFS(start);

    return 0;
}
