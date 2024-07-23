vector<int> topoSort(int N, unordered_map<int, vector<int>> &adj)  {
    queue<int> que;
    vector<int> indegree(N, 0);
    
    //1
    for(int u = 0; u<N; u++) {
        for(int &v : adj[u]) {
            indegree[v]++;
        }
    }
    
    //2. Fill que, indegree with 0
    for(int i = 0; i<N; i++) {
        if(indegree[i] == 0) {
            que.push(i);
        }
    }
    
    //3. Simple BFS
    vector<int> result;
    while(!que.empty()) {
        int u = que.front();
        result.push_back(u);
        que.pop();
        
        for(int &v : adj[u]) {
            indegree[v]--;
            
            if(indegree[v] == 0) {
                que.push(v);
            }
            
        }
    }
    
    return result;
}