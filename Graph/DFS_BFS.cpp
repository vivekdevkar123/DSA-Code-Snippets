void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited) {
    visited[u] = true;
    
    //Visit neighbours
    for(int &v : adj[u]) {
        if(!visited[v]) {
            DFS(adj, v, visited);
        }
    }
}


void BFS(int n, unordered_map<int, vector<int>> &adj,vector<int> &ans) {

    queue<int>q;
    q.push(0);
    vector<int> vis(n,0);
    vis[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}