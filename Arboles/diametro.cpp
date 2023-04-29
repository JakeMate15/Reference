//Es la distancia mas larga entre dos nodos en el arbol
vector<vector<int>> arbol;
 
void dfs(int nodo, int padre, vi &a){
    for(auto u: arbol[nodo]){
        if(u==padre)    continue;
        a[u] = a[nodo]+1;
        dfs(u,nodo,a);
    }
}

int diametro(){
    vi a(n+1),b(n+1);
    dfs(1,0,a);
    int d1 = max_element(all(a))-a.begin();
 
    dfs(d1,0,b);
    int d2 = max_element(all(b))-b.begin();
 
    return max(a[d1],b[d2]);
}
