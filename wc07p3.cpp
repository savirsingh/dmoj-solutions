// code by savir singh
// https://dmoj.ca/problem/wc07p3
// 100/100

// auto-generated by cpide
// the ide built for competitive programming

//================================================================
// Name        : wc07p3.cpp
// Author      : volcano
// Description : just another dp gt problem
//================================================================

#include <bits/stdc++.h>
using namespace std;

const int MM = 15;
const int MMM = 1 << MM;
const int MOD = 13371337;

int N, dp[MMM][MM];
vector<int> adj[MM];

int solve(int node, int mask) {
    if (node == N - 1) return 1;
    if (dp[mask][node]) return dp[mask][node];
    for (auto nxt : adj[node]) {
        if (!(mask & 1 << nxt)) {
            int sb = mask | 1 << nxt;
            dp[mask][node] += solve(nxt, sb);
            dp[mask][node] %= 13371337;
        }
    }
    return dp[mask][node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;while(t--) {
        cin >> N;
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < MM; ++i) adj[i].clear();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int dec;cin>>dec;
                if (dec)adj[i].push_back(j);
            }
        }
        cout << solve(0, 1) << endl;
    }
}
