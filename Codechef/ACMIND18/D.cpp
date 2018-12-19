//EVIEBOT

#include <bits/stdc++.h>


#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define clr(xxx) memset(xxx, 0, sizeof(xxx));

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

int n, k;
bool check(vector <int> & arr){
	if(n == 1)
		return 0;
	if(arr[n-1] > k && arr[n-2] > k)
		return true;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO
	int test;
	cin >> test;
	for(int q = 1; q <= test; ++q){

		cin >> n >> k;
		vector <int> arr;
		for(int i = 1; i <= n; ++i){
			int x;
			cin >> x;
			arr.pb(x);
		}
		sort(arr.begin(), arr.end());
		while(check(arr)){
			int idx1 = -1, idx2 = -1;
			for(int i = 0; i < n; ++i){
				if(arr[i] > k){
					if(idx1 == -1){
						idx1 = i;
					}else{
						idx2 = i;
						break;
					}
				}
			}
			int c = arr[idx1]-k;
			arr[idx1] -= c;
			arr[idx2] -= c;
		}

		int sum = 0;
		for(int i = 0; i < n; ++i)
			sum += arr[i];
		cout << sum << "\n";
	}
}
