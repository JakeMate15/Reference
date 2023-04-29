//Es asegurado que con 100 funcionara
forn(i,100){
    m = l+(r-l)/2;
    if(ok(m))   r = m;
    else        l = m;
}
cout << setprecision(20) << l << "\n";