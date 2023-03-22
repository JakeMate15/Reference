void dfs(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m || vis[x][y] || grafo[x][y] == 0)    return;

    vis[x][y] = true;

    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);

    return;
}
