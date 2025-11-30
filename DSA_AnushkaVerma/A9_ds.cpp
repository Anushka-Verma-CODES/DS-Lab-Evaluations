#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj; // node, weight

    Graph(int v) {
        V = v;
        adj.resize(v);
    }

    void addEdge(int u, int v, int w=1, bool directed=false) {
        adj[u].push_back({v,w});
        if(!directed) adj[v].push_back({u,w});
    }

    // ---------------- 1) BFS ----------------
    void BFS(int start) {
        vector<bool> visited(V,false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        cout << "\nBFS: ";
        while(!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";

            for(auto &nbr : adj[node]) {
                if(!visited[nbr.first]) {
                    visited[nbr.first] = true;
                    q.push(nbr.first);
                }
            }
        }
        cout << endl;
    }

    // ---------------- 2) DFS ----------------
    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";
        for(auto &nbr : adj[node]) {
            if(!visited[nbr.first])
                DFSUtil(nbr.first, visited);
        }
    }

    void DFS(int start) {
        cout << "\nDFS: ";
        vector<bool> visited(V,false);
        DFSUtil(start, visited);
        cout << endl;
    }

    // ---------------- 3) Minimum Spanning Tree ----------------

    // PRIM'S
    void primMST() {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> key(V, INT_MAX), parent(V,-1);
        vector<bool> inMST(V,false);

        key[0] = 0;
        pq.push({0,0});

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;

            for(auto &nbr: adj[u]) {
                int v = nbr.first, weight = nbr.second;
                if(!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        cout << "\nPrim's MST:\n";
        for(int i=1;i<V;i++)
            cout << parent[i] << " - " << i << endl;
    }

    // KRUSKAL'S
    int findSet(int v, vector<int>& parent) {
        if(parent[v] == v) return v;
        return parent[v] = findSet(parent[v], parent);
    }

    void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = findSet(a, parent);
        b = findSet(b, parent);
        if(a != b) {
            if(rank[a] < rank[b]) swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
        }
    }

    void kruskalMST() {
        vector<tuple<int,int,int>> edges; 

        for(int i=0;i<V;i++)
            for(auto &nbr : adj[i])
                if(i < nbr.first)
                    edges.push_back({nbr.second, i, nbr.first});

        sort(edges.begin(), edges.end());

        vector<int> parent(V), rank(V,0);
        for(int i=0;i<V;i++) parent[i] = i;

        cout << "\nKruskal's MST:\n";
        for(auto &e : edges) {
            int w,u,v;
            tie(w,u,v) = e;
            if(findSet(u,parent) != findSet(v,parent)) {
                cout << u << " - " << v << " (" << w << ")\n";
                unionSet(u,v,parent,rank);
            }
        }
    }

    // ---------------- 4) Dijkstra ----------------
    void dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[start] = 0;
        pq.push({0,start});

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for(auto &nbr : adj[u]) {
                int v = nbr.first, weight = nbr.second;
                if(dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nDijkstra from " << start << ":\n";
        for(int i=0;i<V;i++)
            cout << "Node " << i << " Dist " << dist[i] << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0,1,4);
    g.addEdge(0,2,2);
    g.addEdge(1,2,1);
    g.addEdge(1,3,5);
    g.addEdge(2,3,8);
    g.addEdge(2,4,10);
    g.addEdge(3,4,2);
    g.addEdge(3,5,6);
    g.addEdge(4,5,3);

    g.BFS(0);       // 1. BFS
    g.DFS(0);       // 2. DFS
    
    g.primMST();    // 3. Prim
    g.kruskalMST(); // 3. Kruskal 

    g.dijkstra(0);  // 4. Dijkstra

    return 0;
}
