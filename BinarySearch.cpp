\\Devuelve n o tam del vector si no encuentra un indice
int find_lower(vector<int>& v, int x) {
    int l = -1, r = v.size();
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (v[m] > x) r = m;
        else l = m;
    }
    return l;
}