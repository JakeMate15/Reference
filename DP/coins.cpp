int dp[ESTADO_MAX+1];
vector<int>coins(ESTADO_MAX+1,INF);

dp[0] = 0;
memset(dp,INF,sizeof(dp));
for (int x = 1; x <= n; x++) {
    value[x] = INF;
    for (auto c : coins) {
        if (x-c >= 0) {
            dp[x] = min(dp[x], dp[x-c]+1);
        }
    }
}