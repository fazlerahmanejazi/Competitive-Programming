#include<bits/stdc++.h>

#define INF 1000010000
#define nl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

#define rep(i,n) for( int i = 0; i < n; ++i )
#define repi(i,n) for( int i = 1 ; i <= n; ++i )
#define repn(i,n) for( int i = n - 1 ; i >= 0 ; --i )
#define repf(j,i,n) for( int j = i ; j < n ; ++j )
#define die(s) {std::cout << s << nl;}
#define dier(s) {std::cout << s; return 0;}
#define dbg(var) {std::cout << #var << "  = " << var << nl;}
#define vi vector<int>
typedef long long ll;

using namespace std;


const int N = 1e6;
int a[N],c[N];
bool ck[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0);

	string s;
	cin >> s;

	int n = s.size();
	vi bf;
	repi(i , 3) bf.pb(i);
	vi id[4];
	repi(i , n) id[a[i] = s[i -1] - 'a' + 1].pb(i);
	while(next_permutation(all(bf)))
	{
		int x = bf[0];
		int y = bf[1];
		int sz = 0;
		memset(ck , 0 , sizeof ck);
		repi(i , n)
		{
			if(a[i] == x)
			{
				++sz;
				ck[i] = 1;
			}
			else if(a[i] == y)
			{
				c[i] = sz;
			}
		}

		int l = 0 , r = id[y].size() - 1;
		while(l <= r)
		{
			if(c[id[y][l]] + c[id[y][r]] == sz)
			{
				ck[id[y][l++]] = ck[id[y][r--]] = 1;
			}
			else if(c[id[y][l]] + c[id[y][r]] > sz)
			{
				--r;
			}
			else ++l;
		}
		sz = 0;
		repi(i , n) if(ck[i]) ++sz;
		if(sz >= n / 2)
		{
			repi(i , n) if(ck[i]) cout << s[i - 1];
			return 0;
		}

	}
	cout << "NO\n";


	return 0;
}
