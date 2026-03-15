#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); // graf tidak berarah
    }

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (int x : adj[v]) {
            if (!visited[x]) {
                DFSUtil(x, visited);
            }
        }
    }

    void DFS(int start) {
        bool *visited = new bool[V];

        for (int i = 0; i < V; i++)
            visited[i] = false;

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        bool *visited = new bool[V];
        queue<int> q;

        for (int i = 0; i < V; i++)
            visited[i] = false;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int v = q.front();
            cout << v << " ";
            q.pop();

            for (int x : adj[v]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);

    g.DFS(0);
    g.BFS(0);

    return 0;
}