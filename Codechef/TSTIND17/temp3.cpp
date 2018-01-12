#include <bits/stdc++.h>


#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN
#define clr(ar) memset(ar, 0, sizeof(ar));

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	bool edge[101][101];
	int test, n, m, d, D, i, j;
	cin >> test;
	while(test--){
		cin >> n >> m >> d >> D;
		clr(edge);

		int cur_node = 1, siz = 0;
		while(m >= n){
			cur_node = 1;
			for(i = 1; i <= n; ++i){
				edge[cur_node][(cur_node+siz>n?(cur_node+siz-n):(cur_node+siz))] = 1;
				cur_node++;
			}
			siz++;
			m -= n;
		}
		cur_node = 1;
		while(m){
			edge[cur_node][(cur_node+siz>n?(cur_node+siz-n):(cur_node+siz))] = 1;
			cur_node++;
			m--;
		}
		bool flag = true;
		for(i = 1; i <= n; ++i){
			int count = 0;
			for(j = 1; j <= n; ++j){
				if(edge[i][j])
					++count;
			}
			if(count < d || count > D)
				flag = false;
		}
		/*if(flag){
			for(i = 1; i <= n; ++i){
				for(j =1 ; j <= n; ++j){
					if(edge[i][j]) cout << i << " "<< j << "\n";
				}
			}
		}else{
			cout << "-1\n";
		}*/
		if(!flag) cout<< -1 << endl ;
	}
}
