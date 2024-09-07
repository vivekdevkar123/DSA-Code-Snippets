vector<int>parant;
vector<int>rank;


int find(int x){
    if(parant[x] == x) return x;
    return parant[x] = find(parant[x]);
}
    
void Union(int x,int y){
    int x_parant = find(x);
    int y_parant = find(y);
    
    if(rank[x_parant] > rank[y_parant]){
        parant[y_parant] = x_parant;
    }
    else if(rank[x_parant] < rank[y_parant]){
        parant[x_parant] = y_parant;
    }
    else{
        parant[x_parant] = y_parant;
        rank[y_parant]++;
    }
}

void initialize(int n) {
    parant.resize(n);
    rank.resize(n);
    
    for(int i = 0; i < n; i++) {
        parant[i] = i;
        rank[i] = 0;
    }
}
