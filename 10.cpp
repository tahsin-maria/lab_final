// Perform DFS (Depth First Search) traversal of a graph
#include <bits/stdc++.h>
using namespace std;

void DFS(int src, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[src] = true;

    cout << src << " ";

    for (int child : adj[src])
    {
        if (vis[child] == false)
        {
            DFS(child, adj, vis);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            DFS(i, adj, vis);
    }
}