//Devuelve el maximo indice tal que v[i]<=x
int closestToTheLeft(vector<int>& v, int x) {
    int l = -1, r = v.size(),m;
    while (r > l + 1) {
        m = l+(r - l) / 2;
        if (v[m] <= x) l = m;
        else r = m;
    }
    return l;
}

//Devuelve el indice del primer elemento v[i]>=x
int closestToTheRight(vector<int>& v, int x){
    int l=-1,r=n,m;
    while(r>l+1){
        m = l+(r-l)/2;
        if(a[m]<x)  l=m;
        else    r=m;
    }
    return r;
}
