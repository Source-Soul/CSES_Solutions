#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 100000;  // Maximum number of computers
vector<int> adj[MAXN];    // Adjacency list to store connections
int parent[MAXN];         // Array to store the parent of each node in the BFS
bool visited[MAXN];       // Visited array

// Function to perform BFS
bool bfs(int n)
{
    queue<int> q;
    q.push(1);            // Start BFS from computer 1 (Uolevi)
    visited[1] = true;
    parent[1] = -1;       // Mark the parent of the starting node as -1

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == n)    // If we reached Maija's computer (n)
        {
            return true;
        }

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = node; // Set parent for path reconstruction
                q.push(neighbor);
            }
        }
    }
    return false;         // Return false if there is no path to Maija's computer
}

int main()
{
    int n, m;
    cin >> n >> m;

    // Read the connections
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);  // Add connection a to b
        adj[b].push_back(a);  // Add connection b to a (since the graph is undirected)
    }

    // Perform BFS to check if there's a path from 1 to n
    if (bfs(n))
    {
        // Reconstruct the path from n to 1 using the parent array
        vector<int> path;
        int node = n;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }

        // Print the result
        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;  // No path found
    }

    return 0;
}
