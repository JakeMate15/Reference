template<typename T>
struct SegmentTree{
	int N;
	vector<T> ST;
 
	//Creacion a partir de un arreglo O(n)
	SegmentTree(int N, vector<T> & arr): N(N){
		ST.resize(N << 1);
		for(int i = 0; i < N; ++i)
			ST[N + i] = arr[i];     //Dato normal
			ST[N + i] = creaNodo(); //Dato compuesto
		for(int i = N - 1; i > 0; --i)
			ST[i] = ST[i << 1] + ST[i << 1 | 1];        //Dato normal
			ST[i] = merge(ST[i << 1] , ST[i << 1 | 1]); //Dato compuesto
	}
 
	//Actualizacion de un elemento en la posicion i
	void update(int i, T value){
		ST[i += N] = value;     //Dato normal
		ST[i += N] = creaNodo();//Dato compuesto
		while(i >>= 1)
			ST[i] = ST[i << 1] + ST[i << 1 | 1];        //Dato normal  
			ST[i] = merge(ST[i << 1] , ST[i << 1 | 1]); //Dato compuesto
	}
 
	//query en [l, r]
	T query(int l, int r){
		T res = 0;  //Dato normal
		nodo resl = creaNodo(), resr = creaNodo();//Dato compuesto
		for(l += N, r += N; l <= r; l >>= 1, r >>= 1){
			if(l & 1)       res += ST[l++]; //Dato normal
			if(!(r & 1))    res += ST[r--]; //Dato normal

			if(l & 1)       resl = merge(resl,ST[l++]); //Dato compuesto
			if(!(r & 1))    resr = merge(ST[r--],resr); //Dato compuesto
		}
		return res;                 //Dato normal
		return merge(resl,resr);    //Dato compuesto
	}
};