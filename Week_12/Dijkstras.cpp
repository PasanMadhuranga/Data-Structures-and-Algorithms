#include <iostream>

using namespace std;

#define vertices 6
#define no_edge 999
#define INT_MAX 1000000 

float Dijkstras_Algorithm(int adj_matrix[vertices][vertices], int source_node){
    int smallest_time[vertices];
    bool visited[vertices];
    int min_time;
    int next_node;
    // modify the adjacency matrix by substituting 999 to all the non existing edges
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            if(adj_matrix[i][j] == 0){
                adj_matrix[i][j] = no_edge;
            }
        }
    }

    // initialize the time array with infinity and the visited array with false
    for(int i = 0; i < vertices; i++){
        smallest_time[i] = INT_MAX;
        visited[i] = false;
    }
    // initialize the source node with 0
    smallest_time[source_node] = 0;

    // iterate through all the vertices
    for(int i = 0; i < vertices; i++){
        min_time = INT_MAX;
        // find the next node with the minimum time
        for(int j = 0; j < vertices; j++){
            // if the time is smaller than the current minimum time and the node is not visited
            if(min_time > smallest_time[j] && !visited[j]){
                // update the minimum time and the next node
                min_time = smallest_time[j];
                next_node = j;
            }
        }
        // mark the next node as visited
        visited[next_node] = true;
        // update the smallest_time array
        for(int j = 0; j < vertices; j++){
            // if the node is not visited,
            if(!visited[j]){
                // if there is a new smallest time path from source node to the node
                if(min_time + adj_matrix[next_node][j] < smallest_time[j]){
                    // update the time array
                    smallest_time[j] = min_time + adj_matrix[next_node][j];
                }
            }
        }
    }

    // output the smallest time from source node to all the other nodes
    cout << "\nsmallest time from city " << source_node << " to " << endl;
    for (int i = 0; i < vertices; i++) {
        if (i == source_node)
            continue;
        cout << "city " << i << ": " << smallest_time[i] << " " << endl;
    }

    // Calculate the total time from source node to all the other nodes
    int sum = 0;
    for (int i = 0; i < vertices; i++) {
        if (i == source_node)
            continue;
        sum += smallest_time[i];
    }

    // return the average time
    return (float)sum / (vertices - 1);
}


int main(int argc, char const *argv[])
{
    // Initialize the adjacency matrix of the graph
    int graph_adj_matrix[vertices][vertices] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    // Store the smallest average time from every node to all the other nodes
    float smallest_avg_time[vertices];

    for (int i = 0; i < vertices; i++) {
        smallest_avg_time[i] = Dijkstras_Algorithm(graph_adj_matrix, i);
    }

    // Find the smallest average time
    float min_time = INT_MAX;
    for (int i = 0; i < vertices; i++) {
        if (min_time > smallest_avg_time[i]) {
            min_time = smallest_avg_time[i];
        }
    }

    // Display all the ciites with the smallest average time
    cout << "\nThe city/ies with the smallest average time (" << min_time << ") :"<< endl;
    for (int i = 0; i < vertices; i++) {
        if (min_time == smallest_avg_time[i]) {
            cout << "city " << i << endl;
        }
    }
    return 0;
}

