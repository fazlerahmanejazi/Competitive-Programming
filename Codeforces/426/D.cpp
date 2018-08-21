typedef long long ll;
#include <algorithm>
#include <string>
#include <iostream>
#include <math.h>
#include <numeric>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include <stack>
#include <sstream>
#include <climits>
#include <limits.h>

using namespace std;

bool check(ll a, ll mid) {
    for (int i = 0; i < 3; i ++) {
        a /= mid;
    }
    return min(a, (ll)1);
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    ll a,b;
    cin >> a >> b;
    ll cac = a * b;
    int gcd = cbrt(cac);
    if (gcd == 0) cout << "NO" << endl;
    cout << gcd << " " << cac << " " ;
    int A = a / gcd;
    int B = b / gcd;
    if (!check(cac, gcd) || A * B != gcd || A == 0 || B == 0 || gcd == -1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }


  }










}
