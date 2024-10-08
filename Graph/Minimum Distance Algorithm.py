# To get the minimum distance of each node from every node

void Floyd_Warshall_Algorithm(vector<vector<int>>& grid){
    int n = grid.size();
    for(int via = 0; via < n; via++) {
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
            }
        }
    }
}


vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> result(V, INT_MAX);
    result[S] = 0;
    for(int c = 1; c<=V-1; c++) {
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(result[u] != 1e8 && result[u] + w < result[v]) {
                result[v] = result[u] + w;
            }
        }
    }
    
    //Now detect negative cycle
    for(auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if(result[u] != 1e8 && result[u] + w < result[v]) {
            return {-1};
        }
    }
    return result;
}

