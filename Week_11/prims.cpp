#include <iostream>

#define vertices 6
#define MAXIMUM 10000000
#define no_edge 9999

using namespace std;

void prims_algorithm(int adj_mtx[vertices][vertices], int source_node){
    // modify adjacency matrix by setting no edges to 9999
    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            if (adj_mtx[i][j] == 0){
                adj_mtx[i][j] = no_edge;
            }
        }
    }
    // create visited array to keep track of visited vertices 
    bool visited[vertices];
    // set all vertices to false
    for (int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    // set source node to true
    visited[source_node] = true;
    // create variables to keep track of minimum edge
    int min_edge;
    // create variables to keep track of the edges that make up the minimum edge
    int edge_vertex_1;
    int edge_vertex_2;
    // create variable to keep track of whether all vertices have been visited
    bool all_vertices_visited;

    cout << "Edge : Weight" << endl;
    while(true){
        all_vertices_visited = true;
        // Find minimum edge that connects visited set to unvisited set
        min_edge = MAXIMUM;
        for (int i = 0; i < vertices; i++){
            if (visited[i]){
                for (int j = 0; j < vertices; j++){
                    if (!visited[j] && adj_mtx[i][j] < min_edge){
                        min_edge = adj_mtx[i][j];
                        edge_vertex_1 = i;
                        edge_vertex_2 = j;
                        all_vertices_visited = false;
                    }  
                } 
            }   
        }
        // if all vertices have been visited that means we are done. So break out of loop
        if (all_vertices_visited){
            break;
        }
        // print out the minimum edge
        cout << edge_vertex_1 << " - " << edge_vertex_2 << " : " << min_edge << endl;
        // set true for the vertex that was just visited
        visited[edge_vertex_2] = true;
    }
    
}

int main(int argc, char const *argv[])
{
    // create adjacency matrix for the graph
    int adj_matrix[vertices][vertices] = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 5}
    };
    // call prims algorithm from source node 0 to find minimum spanning tree
    prims_algorithm(adj_matrix, 0);
    return 0;
}
