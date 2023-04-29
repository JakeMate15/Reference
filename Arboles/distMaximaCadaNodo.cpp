//Calculo de la distancia mas larga iniciando desde cualquier nodo
vector<vector<int>> arbol;
vi a(n+1),b(n+1),distInd(n+1);
 
void dfs(int nodo, int padre, vi &a){
    for(auto u: arbol[nodo]){
        if(u==padre)    continue;
        a[u] = a[nodo]+1;
        dfs(u,nodo,a);
    }
}

void distMaximas(){
    dfs(1,0,distInd);
    int n1 = max_element(all(distInd))-distInd.begin();
 
    dfs(n1,0,a);
    int n2 = max_element(all(a))-a.begin();
 
    dfs(n2,0,b);

    //La respuesta de cada nodo i es
    max(a[i],b[i]);
}