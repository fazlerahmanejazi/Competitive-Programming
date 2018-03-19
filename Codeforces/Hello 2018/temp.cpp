#include <iostream>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int N = 32;
const long long oo = (1LL<<30);
long long n, L;
long long c[N];

int main()
{
  cin >> n >> L;
  for(int i = 0 ; i <= 30 ; i++)
    c[i] = -1;
  for(int i = 0 ; i < n ; i++)
    cin >> c[i];
  for(int i = 1 ; i <= 30 ; i++)
    if(c[i]==-1ll || c[i-1] * 2 < c[i])
      c[i] = c[i-1] * 2ll;
  long long ans = 0;
  for(int i = 30 ; i >= 0 ; i--){
    if((1LL<<i) & L)
      ans += c[i];
  }
  cout << ans << endl;
	return 0;
}
