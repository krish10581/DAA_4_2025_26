#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u;
    int v;
    int w;
};

vector<int> bellmanFord(int V, vector<Edge> &edges, int src){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i = 1; i <= V - 1; i++){
        for(int j = 0; j < edges.size(); j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int j = 0; j < edges.size(); j++){
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            return {};
        }
    }

    return dist;
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<Edge> edges;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;

    vector<int> result = bellmanFord(V, edges, src);

    return 0;
}