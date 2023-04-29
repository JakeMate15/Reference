vector<vector<int>> arbol;
vi distInd(n+1);
 
void dfs(int nodo, int padre, vi &a){
    for(auto u: arbol[nodo]){
        if(u==padre)    continue;
        a[u] = a[nodo]+1;
        dfs(u,nodo,a);
    }
}

dfs(1,0,distInd);