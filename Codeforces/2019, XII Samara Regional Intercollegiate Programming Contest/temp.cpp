#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int n;
pair<pair<int, int>, int> a[1000000];
pair<int, int> mx[1000000];
 
int ans = 0;
int p1 = 0;
int p2 = 1;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.second >> a[i].first.first;
        a[i].second = i;
    }

    sort(a, a + n);
    mx[0] = {0, -1};
    if (a[1].first.second > a[0].first.second) {
        mx[1] = {1, 0};
    } else {
        mx[1] = {0, 1};
    }

    for (int i = 2; i < n; i++) {
        int mx1 = mx[i - 1].first;
        int mx2 = mx[i - 1].second;
        if (a[i].first.second > a[mx1].first.second) {
            mx2 = mx1;
            mx1 = i;
        } else if (a[i].first.second > a[mx2].first.second) {
            mx2 = i;
        }
        mx[i] = {mx1, mx2};
    }

    for (int i = 0; i < n; i++) {
        int l = -1;
        int r = n;

        int att = a[i].first.second;
        int h = a[i].first.first;
        int ind = a[i].second;

        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (a[m].first.first <= att) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l == -1) continue;
        int bs = mx[l].first;
        if (a[bs].second == ind) {
            bs = mx[l].second;
        }
        if (bs == -1) continue;
        int currAns = a[bs].first.second;
        if (a[bs].first.second >= h) {
            currAns += att;
        }
        if (currAns > ans) {
            ans = currAns;
            p1 = ind;
            p2 = a[bs].second;
        }
    }

    cout << ans << "\n" << p1 + 1 << " " << p2 + 1;

    return 0;
}
