// code by savir singh
// https://dmoj.ca/problem/grind
// 100/100

// there are 2 ways, the array thingamajig and the priority queue thingy

// first way is faster:

// auto-generated by cpide
// the ide built for competitive programming

// ================================================================
// Name        : grind.cpp
// Author      : volcano
// Description : friendly304010 and i are very similar :)
// ================================================================

// #include <bits/stdc++.h>
// using namespace std;
// #define pq priority_queue
// #define pii pair<int, int>

// const int MM = 1e7;
// int n, dif[MM], res = 0, upto = 0;

// int main() {
//     ios::sync_with_stdio(false);cin.tie(nullptr);
//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         int s, f; cin >> s >> f;
//         upto = max(upto, f);
//         dif[s]++;dif[f]--;
//     }
//     for (int i = 1; i <= upto; i++) {
//         dif[i] += dif[i - 1]; res = max(res, dif[i]);
//     }
//     cout << res << endl;
// }

// but here is the slow version uncommented:

// auto-generated by cpide
// the ide built for competitive programming

//================================================================
// Name        : grind.cpp
// Author      : volcano
// Description : friendly304010 and i are very similar :)
//================================================================

#include <bits/stdc++.h>
using namespace std;
#define pq priority_queue
#define pii pair<int, int>

int n;
pq<int, vector<int>, greater<int>> machines;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n;
    vector<pii> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int curr_start = tasks[i].first;
        int curr_end = tasks[i].second;
        if (!machines.empty() && machines.top() <= curr_start) {
            machines.pop();
        } else {
            ans++;
        }
        machines.push(curr_end);
    }
    cout << ans << endl;
}

// this format is good because you can just copy paste this and use the template for a similar problem :D
// peace