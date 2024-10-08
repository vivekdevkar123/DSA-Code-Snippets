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
