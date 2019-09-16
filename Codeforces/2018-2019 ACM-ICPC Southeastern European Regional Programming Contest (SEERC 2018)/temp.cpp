#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr << #x << ": " << x << endl
#define dbg_v(v, n) cerr << #v << ": "; for(int _ = 0; _ < n; ++_) cerr << (v)[_] << ' '; cerr << endl
 
const int N = 200005;
 
int i, n, m, from[N], to[N], spt[N], spr[N];
int nrt, nrr, pr[N], pt[N], slet[N];
long long dist[N], distCheat[N];
vector<int> lda[N], ldat[N];
bool canUse[N];
 
void dijkstra() {
    set<pair<long long, int>> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[n] = 0;
    q.insert(make_pair(0, n));
    while(q.size()) {
        int now = q.begin()->second;
        long long cost = q.begin()->first;
        q.erase(q.begin());

        if(dist[now] != cost) continue;


        for(int it : ldat[now]) {
            if(dist[from[it]] <= cost + spr[it]) continue;
            q.erase(make_pair(dist[from[it]], from[it]));
            dist[from[it]] = cost + spr[it];
            q.insert(make_pair(dist[from[it]], from[it]));
        }
    }
}
 
int main() {
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; ++i) {
        scanf("%d %d %d %d", from + i, to + i, spt + i, spr + i);
        lda[from[i]].push_back(i);
        ldat[to[i]].push_back(i);
    }

    long long sumSleep = 0, totalDist = 0, totalRabit = 0;
    scanf("%d", &nrt);
    for(i = 1; i <= nrt; ++i)
        scanf("%d %d", pt + i, slet + i), sumSleep += slet[i] * (i != nrt), totalDist += spt[pt[i]] + slet[i] * (i != nrt);
    slet[nrt] = 0;
    scanf("%d", &nrr);
    for(i = 1; i <= nrr; ++i) scanf("%d", pr + i), totalRabit += spr[pr[i]], canUse[pr[i]] = true;

    dijkstra();
    // dbg_v(dist + 1, n);

    for(i = 1; i <= n; ++i) {
        distCheat[i] = 1e18;
        for(auto it : lda[i]) {
            if(!canUse[it]) distCheat[i] = min(distCheat[i], dist[to[it]] + spr[it]);
        }
        if(distCheat[i] != dist[i]) distCheat[i] = 1e18;
    }

    vector<int> ans;
    long long prefRabit = 0, prefTurtle = 0, currSleep = 0;
    for(int ptrr = 1, ptrt = 1; ptrr <= nrr; ++ptrr) {
        while(ptrt <= nrt && prefTurtle + spt[pt[ptrt]] + currSleep <= prefRabit) {
            prefTurtle += spt[pt[ptrt]];
            currSleep += slet[ptrt];
            ++ptrt;
        }

        if(prefRabit + distCheat[from[pr[ptrr]]] < totalRabit) {
            // dbg(from[pr[ptrr]]);
            // dbg(prefRabit + dist[from[pr[ptrr]]]);
            // dbg(totalDist - currSleep);
            if(prefRabit + distCheat[from[pr[ptrr]]] <= totalDist - (sumSleep - currSleep)) ans.push_back(from[pr[ptrr]]);
        }

        prefRabit += spr[pr[ptrr]];
    }

    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());

    for(auto it : ans) printf("%d ", it);
    if(ans.size()) printf("\n");

    return 0;
}
