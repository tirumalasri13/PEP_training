#include<iostream>
#include<vector>
using namespace std;
//building undirected graph using adjacency matrix

vector<vector<int>> adj_matrix_undirected(vector<vector<int>>& edges, int n){
    vector<vector<int>>graph(n, vector<int>(n, 0)); // Initialize an n x n matrix with 0s

    //build graph
    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        graph[u][v] = 1; // Mark the presence of an edge from u to v
        graph[v][u] = 1; // Mark the presence of an edge from v to u (undirected)
    }
    return graph;
}

//building directed graph using adjacency matrix
vector<vector<int>> adj_matrix_directed(vector<vector<int>>& edges, int n){
    vector<vector<int>>graph(n, vector<int>(n, 0)); // Initialize an n x n matrix with 0s

    //build graph
    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        graph[u][v] = 1; // Mark the presence of an edge from u to v (directed)
    }
    return graph;
}