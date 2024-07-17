//https://godbolt.org/z/6h83MY18f

#include <bits/stdc++.h>

using namespace std;

// graph class: adj list and addEdge method
class Graph {
public:
    unordered_map<int, vector<int>> adjList;
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }
};

// 4.1 route between nodes
// method1 :dfs

// helper func
bool dfs(unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& visited, int start, int e) {
    if (start == e) return true;
    visited[start] = true;

    for (int neighbor : adjList[start]) {
        if (!visited[neighbor]) {
            if (dfs(adjList, visited, neighbor, e)) {
                return true;
            }
        }
    }
    return false; // all search done without finding path
}

// impl
bool thereIsRoute_dfs(Graph& graph, int s, int e) {
    unordered_map<int, bool> visited;
    return dfs(graph.adjList, visited, s, e);
}



// method2 :bfs

bool thereIsRoute_bfs(Graph& graph, int start, int e) {
    if(start == e) return true;

    unordered_map<int, bool> visited;
    queue<int> q;
    
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        // traverse adjlist
        for(int neighbor: graph.adjList[node]){
            if(!visited[neighbor]){
                if(neighbor == e){
                    return true;
                }
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }

    }
    return false;

}



int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int start = 1, end = 3;
    // method1
    cout << "method1 ----DFS --: \n";
    if (thereIsRoute_dfs(g, start, end)) {
        cout << "There is a path from " << start << " to " << end << endl;
    } else {
        cout << "There is no path from " << start << " to " << end << endl;
    }
    
    // method2
    cout << "method1 ----BFS --: \n";
    if (thereIsRoute_bfs(g, start, end)) {
        cout << "There is a path from " << start << " to " << end << endl;
    } else {
        cout << "There is no path from " << start << " to " << end << endl;
    }


    return 0;
}
