#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, flow, C, rev;
};

struct Dinic {
    int V;
    vector<int> level;
    vector<vector<Edge>> adj;

    Dinic(int V) {
        this->V = V;
        adj.resize(V);
        level.resize(V);
    }

    void addEdge(int u, int v, int C) {
        Edge a{v, 0, C, (int)adj[v].size()};
        Edge b{u, 0, 0, (int)adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : adj[u]) {
                if (level[e.v] < 0 && e.flow < e.C) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] >= 0;
    }

    int sendFlow(int u, int flow, int t, vector<int>& start) {
        if (u == t) return flow;
        for (; start[u] < adj[u].size(); start[u]++) {
            Edge &e = adj[u][start[u]];
            if (level[e.v] == level[u] + 1 && e.flow < e.C) {
                int curr_flow = min(flow, e.C - e.flow);
                int temp_flow = sendFlow(e.v, curr_flow, t, start);
                if (temp_flow > 0) {
                    e.flow += temp_flow;
                    adj[e.v][e.rev].flow -= temp_flow;
                    return temp_flow;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        if (s == t) return -1;
        int total = 0;
        while (bfs(s, t)) {
            vector<int> start(V, 0);
            while (int flow = sendFlow(s, INT_MAX, t, start))
                total += flow;
        }
        return total;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Dinic g(V);
    cout << "Enter edges (u v capacity):\n";
    for (int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g.addEdge(u, v, c);
    }

    int s, t;
    cout << "\nEnter source and sink: ";
    cin >> s >> t;

    cout << "Maximum Flow: " << g.maxFlow(s, t) << endl;
    return 0;
}