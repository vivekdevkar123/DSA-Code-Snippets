# Undirected Graph

bool isCycle(unordered_map<int,vector<int>>&m,int curr,int parant,vector<int>&vis){
    if(vis[curr] && parant != curr) return true;
    vis[curr] = 1;
    for(int u:m[curr]){
        if(parant == u) continue;
        if(vis[u]) return true;
        if(solve(m,u,curr,vis)) return true;
    }
    return false;
}
