//Se calcula la cantidad de nodos del subarbol del nodo x
const int maxV = 2*1e5+1;
vector<vector<int>> arbol;
int cantNodos[maxV];
 
void dfs(int nodo, int padre){
    cantNodos[nodo] = 1;
    for(int u: arbol[nodo]){
        if(u==padre) continue;
        dfs(u,nodo);
        cantNodos[nodo]+=cantNodos[u];
    }
}

dfs(1,0);