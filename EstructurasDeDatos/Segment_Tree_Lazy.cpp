//Lazy propagation con incremento de u en rango y minimo
template<typename T>
struct SegmentTreeLazy{
	int N,h;
	vector<T> ST, d;
 
	//Build from an array in O(n)
	SegmentTreeLazy(int n, vector<T> &a): N(n){
		ST.resize(N << 1);
		d.resize(N);
		h = 64 - __builtin_clzll(n);
 
		for(int i = 0; i < N; ++i)
			ST[N + i] = a[i];
		for(int i = N - 1; i > 0; --i)
			ST[i] = min(ST[i << 1] , ST[i << 1 | 1]);
	}
 
	void apply(int p, T value) {
		ST[p] += value;
		if(p<N)	d[p]+= value;
	}
 
	// modify value of parents of p
	void build(int p){
		while(p>1){
			p >>= 1;
			ST[p] = min(ST[p << 1], ST[p << 1 | 1]) + d[p];
		}
	}
 
	// propagate from root to p
	void push(int p){
		for (int s = h; s > 0; --s) {
			int i = p >> s;
			if (d[i] != 0) {
				apply(i << 1, d[i]);
				apply(i << 1 | 1, d[i]);
				d[i] = 0;
			}
		}
	}
 
	// add v to interval [l, r)
	void increment(int l, int r, T value) {	
		l += N, r += N;
		int l0 = l, r0 = r;
		for (; l < r; l >>= 1, r >>= 1) {
			if(l & 1) apply(l++, value);
			if(r & 1) apply(--r, value);
		}
		build(l0);
		build(r0 - 1);
	}
 
	// min on interval [l, r)
	T range_min(int l, int r) { 	
		l += N, r += N;
		push(l);
		push(r - 1);
		T res = LLONG_MAX;
		for (; l < r; l >>= 1, r >>= 1) {
			if(l & 1)	res = min(res, ST[l++]);
			if(r & 1)	res = min(res, ST[--r]);
		}
		return res;
	}
    
};