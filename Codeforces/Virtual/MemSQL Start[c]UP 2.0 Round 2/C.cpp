#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define PI 3.1415926535
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 40000005
// #define N 40005
int main() {
    SYNC
    int k, n1, n2, n3, t1, t2, t3, cnt[N][3] = {};
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    int cur = 0, ans = 0;
    while(k) {
        // if(cnt[cur][0] < n1 && cnt[cur + t1][1] < n2 && cnt[cur + t1 + t2][2] < n3) {
       int nxt = cur;
       FOR(i,cur, cur+t1) {
            cnt[i][0]++;
            if(cnt[i][0] == n1) nxt = i + 1;
       }
       FOR(i,cur + t1, cur + t1 + t2) {
            cnt[i][1]++;
            if(cnt[i][1] == n2) nxt = max(nxt, i - t1 + 1);
       }
       FOR(i, cur + t1 + t2, cur + t1 + t2 + t3) {
            cnt[i][2]++;
            if(cnt[i][2] == n3) nxt = max(nxt, i - t1 - t2 + 1);
       }
       ans = cur + t1 + t2 + t3;
       k--;
       cur = nxt;
        //    continue;
        // }
        // cur++;
    }
    cout << ans;
}
